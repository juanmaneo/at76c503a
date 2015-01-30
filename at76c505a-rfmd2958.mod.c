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

MODULE_ALIAS("usb:v03EBp7614dl*dh*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v03EBp7617dl*dh*dc*dsc*dp*ic*isc*ip*");

MODULE_INFO(srcversion, "A9C6F2FEFA65E9F5810AA22");
