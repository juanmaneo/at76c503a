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

MODULE_ALIAS("usb:v03EBp7605dl*dh*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v069Ap0321dl*dh*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v077Bp2219dl*dh*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v077Bp2227dl*dh*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0864p4102dl*dh*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v2001p3200dl*dh*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v1668p7605dl*dh*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v03EBp4102dl*dh*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v1371p5743dl*dh*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v1371p0002dl*dh*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v04A5p9001dl*dh*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0506p0A01dl*dh*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0681p001Bdl*dh*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v050Dp0050dl*dh*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v07B8pB000dl*dh*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v1044p8003dl*dh*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v2019p3220dl*dh*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v049Fp0032dl*dh*dc*dsc*dp*ic*isc*ip*");

MODULE_INFO(srcversion, "243333D90D617A95326A536");
