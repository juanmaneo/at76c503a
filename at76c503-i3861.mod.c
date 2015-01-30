#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

#undef unix
struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = __stringify(KBUILD_MODNAME),
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
};

static const struct modversion_info ____versions[]
__attribute_used__
__attribute__((section("__versions"))) = {
	{ 0x432c7dca, "struct_module" },
	{ 0x990f87c1, "usb_deregister" },
	{ 0x9dada93, "usb_register" },
	{ 0x2d2f167c, "at76c503_delete_device" },
	{ 0xf62986a6, "at76c503_do_probe" },
	{ 0x1b7d4074, "printk" },
};

static const char __module_depends[]
__attribute_used__
__attribute__((section(".modinfo"))) =
"depends=at76c503";

MODULE_ALIAS("usb:v03EBp7603dl*dh*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v066Bp2211dl*dh*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0864p4100dl*dh*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0B3Bp1612dl*dh*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v03F0p011Cdl*dh*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0CDEp0001dl*dh*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v069Ap0320dl*dh*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0D5CpA001dl*dh*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v04A5p9000dl*dh*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v05DDpFF31dl*dh*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v8086p0200dl*dh*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0D8Ep7100dl*dh*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0D8Ep7110dl*dh*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v04BBp0919dl*dh*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v069Ap0821dl*dh*dc*dsc*dp*ic*isc*ip*");

MODULE_INFO(srcversion, "C4E50BAD271C1D6088AD308");
