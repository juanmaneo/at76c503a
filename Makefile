#$Id: Makefile,v 1.41 2004/09/19 19:17:29 jal2 Exp $
#
# Copyright (c) 2002 - 2003 Oliver Kurth
#           (c) 2003 - 2004 Jörg Albert <joerg.albert@gmx.de>
#
#	This program is free software; you can redistribute it and/or
#	modify it under the terms of the GNU General Public License as
#	published by the Free Software Foundation; either version 2 of
#	the License, or (at your option) any later version.
#

CC=gcc

ifneq (,$(KVERS))
 KERNEL_VERSION=$(KVERS)
else
 KERNEL_VERSION = $(shell uname -r)
endif


ifneq (,$(KSRC))
 KERNEL_SRC = $(KSRC)
else
 KERNEL_SRC = /lib/modules/$(KERNEL_VERSION)/build
endif

KERNEL_HEADERS = $(KERNEL_SRC)/include
FW_DL=

# compile for firmware download from user space
# if no firmware header files are available
ifneq ($(wildcard fw-pkg*.h),)
FW_DL += -DCOMPILE_FIRMWARE_INTO_DRIVER
endif

MODULES = at76c503-i3861.o at76c503-rfmd.o at76c503-rfmd-acc.o \
          at76c505-rfmd.o at76c503-i3863.o at76c505-rfmd2958.o at76c505a-rfmd2958.o \
	  at76c503.o at76_usbdfu.o 

SRCS = at76c503.c at76_usbdfu.c at76c503-rfmd.c at76c505-rfmd.c at76c503-rfmd-acc.c \
       at76c503-i3861.c at76c503-i3863.c at76c505-rfmd2958.c at76c505a-rfmd2958.c

HDRS = at76c503.h at76_ieee802_11.h at76_usbdfu.h at76c503-fw_skel.c
FW_HDRS= fw-pkg-505-rfmd2958-1.101.0-86.h  fw-pkg-i3863.h  \
	fw-pkg-rfmd-1.101.0-84.h fw-pkg-i3861.h \
	fw-pkg-rfmd-0.90.2-140.h \
	fw-pkg-r505.h fw-pkg-rfmd-acc-1.101.0-84.h \
	fw-pkg-505a-rfmd2958-1.102.0-113.h

SCRIPTS = fwbin2h fwbin2pkg.sh fwconvert fwversion

DISTFILES = $(SRCS) $(HDRS) $(FW_HDRS) Makefile README COPYING \
            CHANGELOG gen_fw.c kernel_patch.sh Makefile.k26
TOPDISTFILES = 

# get the version from at76c503.h
# for 2.6.x kernels the shell command is evaluated too late, 
#  looking for at76c503.h in the kernel root dir :-(
#VERSION = -
#VERSION += $(shell grep '\#define DRIVER_VERSION' at76c503.h | sed 's/\#define.*DRIVER_VERSION.*"\(.*\)"/\1/g' )
VERSION = 
DISTNAME = at76c503$(VERSION)
DISTDIR = ../dist

# delete any old module in this tree before installing a new one
DEL_MODULE_DIR = $(DESTDIR)/lib/modules/$(KERNEL_VERSION)
MODULE_DIR = $(DESTDIR)/lib/modules/$(KERNEL_VERSION)/kernel/drivers/net/wireless/at76c503
DEPMOD = /sbin/depmod

# if Rules.make exists in the kernel tree, we assume 2.4 style modules
# if it doesn't assume 2.5 style
OLDMAKE = $(wildcard $(KERNEL_SRC)/Rules.make)

ifeq (,$(OLDMAKE))
# 2.5 style modules, get the kernel makefiles to do the work

SRCDIR = $(shell pwd)
MODVERDIR = $(SRCDIR)/.tmp_versions

obj-m := $(MODULES)

all: modules

modules:
	mkdir -p .tmp_versions
	-cp $(KERNEL_SRC)/.tmp_versions/*.mod $(MODVERDIR)
	$(MAKE) -C $(KERNEL_SRC) SUBDIRS=$(SRCDIR) MODVERDIR=$(MODVERDIR) \
		EXTRA_CFLAGS="$(FW_DL)" modules

mv_old:
	for i in $(MODULES:%.o=%.ko); do \
	  find $(DEL_MODULE_DIR) -name $$i -exec rm -f {} {}.orig \; ;done 

install-modules: all mv_old
	mkdir -p $(MODULE_DIR)
	install -m 644 -o 0 -g 0 $(MODULES:%.o=%.ko) $(MODULE_DIR)

install: install-modules
	$(DEPMOD) -ae

uninstall:
	for f in $(MODULES:%.o=%.ko); do rm $(MODULE_DIR)/$$f; done

else
# 2.4 style modules

CPPFLAGS = -D__KERNEL__ \
	-DMODULE -DEXPORT_SYMTAB \
	-I$(KERNEL_HEADERS)
CFLAGS = -O2 -Wall -Wstrict-prototypes -pipe -fno-strict-aliasing \
	 $(FW_DL) \
         -fno-common -Wno-sign-compare -Wno-unused

MODVER = $(shell if cat $(KERNEL_HEADERS)/linux/autoconf.h 2>/dev/null | \
grep -q '^[[:space:]]*\#define[[:space:]]*CONFIG_MODVERSIONS[[:space:]]*1'; \
then echo 1; else echo 0; fi)

ifeq ($(MODVER),1)
MFLAG = -DMODVERSIONS -include $(KERNEL_HEADERS)/linux/modversions.h
endif

CCDEP = $(CC) $(CFLAGS) -M
TAR = tar

all: $(MODULES)

mv_old:
	for i in $(MODULES); do \
	  find $(DEL_MODULE_DIR) -name $$i -exec rm -f {} {}.orig \; ;done 

install-modules: all mv_old
	mkdir -p $(MODULE_DIR)
	for f in $(MODULES); do install -m 644 -o 0 -g 0 $$f $(MODULE_DIR)/$$f; done

install: install-modules
	$(DEPMOD) -ae

uninstall:
	for f in $(MODULES); do rm $(MODULE_DIR)/$$f; done

%.o: %.c
	$(CC) -MD $(CFLAGS) $(CPPFLAGS) $(MFLAG) -c $<

%.s: %.c
	$(CC) -MD $(CFLAGS) $(CPPFLAGS) -S $<

%.i: %.c
	$(CC) -MD $(CPPFLAGS) -E $< -o $@

-include $(SRCS:%.c=%.d)

endif

.PHONY: all dist kernel_patch rmmod mv_old install-modules install modules

TAGS:
	rm -f TAGS
	etags --append $(SRCS) $(HDRS)

clean:
	rm -f core *.o *~ a.out *.d
	rm -f *.ko *.mod.c .*.cmd
	rm -f *.s *.i
	rm -rf .tmp_versions

dist:
	[ -d $(DISTNAME) ] && rm -rf $(DISTNAME) || true
	mkdir $(DISTNAME)
	cp -aR $(DISTFILES) $(DISTNAME)
	mkdir $(DISTNAME)/scripts
	(cd scripts ; cp -aR $(SCRIPTS) ../$(DISTNAME)/scripts)
	tar zcvf $(DISTNAME).tar.gz $(DISTNAME)
	cd $(DISTNAME) ; rm $(FW_HDRS) ; cd ..
	mv $(DISTNAME) $(DISTNAME)-fwdl
	tar zcvf $(DISTNAME)-fwdl.tar.gz $(DISTNAME)-fwdl
	rm -rf $(DISTNAME)-fwdl

kernel_patch:
	 DRV_SRC="$(SRCS)" DRV_HDR="$(HDRS)" ./kernel_patch.sh $(KERNEL_SRC)

rmmod:
	-rmmod $(MODULES:%.o=%)	
