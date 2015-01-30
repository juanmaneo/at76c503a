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
	{ 0x6c3397fb, "malloc_sizes" },
	{ 0x1b7d4074, "printk" },
	{ 0x101ea228, "usb_control_msg" },
	{ 0x123d3b6a, "kmem_cache_alloc" },
	{ 0x17d59d01, "schedule_timeout" },
	{ 0x37a0cba, "kfree" },
};

static const char __module_depends[]
__attribute_used__
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "4EDAC33AD824666C40DC7E5");
