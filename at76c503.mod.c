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
	{ 0x30f999a3, "iw_handler_set_thrspy" },
	{ 0x7da8156e, "__kmalloc" },
	{ 0xf0be4b57, "__kfree_skb" },
	{ 0x65b08105, "unregister_netdevice" },
	{ 0xdfecce8f, "alloc_etherdev" },
	{ 0x1683aa15, "del_timer" },
	{ 0x6c3397fb, "malloc_sizes" },
	{ 0x9a31effe, "rtnl_sem" },
	{ 0x47d400c9, "schedule_work" },
	{ 0xdc184156, "linkwatch_fire_event" },
	{ 0xd8c152cd, "raise_softirq_irqoff" },
	{ 0xcf1d8a8, "__netdev_watchdog_up" },
	{ 0x1d26aa98, "sprintf" },
	{ 0xa7bb33cd, "usb_unlink_urb" },
	{ 0xda02d67, "jiffies" },
	{ 0xd533bec7, "__might_sleep" },
	{ 0x7533e72d, "netif_rx" },
	{ 0xb33cb11d, "wireless_spy_update" },
	{ 0x1b7d4074, "printk" },
	{ 0x71c90087, "memcmp" },
	{ 0x9b43035a, "alloc_skb" },
	{ 0x8ddf32d2, "iw_handler_get_spy" },
	{ 0x969cfc40, "free_netdev" },
	{ 0xed5c73bf, "__tasklet_schedule" },
	{ 0xdddf910a, "register_netdev" },
	{ 0x2cd3086, "__down_failed_trylock" },
	{ 0xaccccb8, "wireless_send_event" },
	{ 0x101ea228, "usb_control_msg" },
	{ 0x625acc81, "__down_failed_interruptible" },
	{ 0x17136545, "mod_timer" },
	{ 0x49e79940, "__cond_resched" },
	{ 0x19caee0b, "skb_over_panic" },
	{ 0xa3e46343, "usb_submit_urb" },
	{ 0x123d3b6a, "kmem_cache_alloc" },
	{ 0xea4114b5, "usb_get_dev" },
	{ 0xac237b72, "usb_reset_device" },
	{ 0xdec604fd, "usb_put_dev" },
	{ 0x17d59d01, "schedule_timeout" },
	{ 0xb0c791, "iw_handler_get_thrspy" },
	{ 0x7d731807, "usb_clear_halt" },
	{ 0xb5ffe69f, "usbdfu_download" },
	{ 0x799aca4, "local_bh_enable" },
	{ 0xb8fc7550, "skb_under_panic" },
	{ 0x690b1e05, "iw_handler_set_spy" },
	{ 0x37a0cba, "kfree" },
	{ 0x2e60bace, "memcpy" },
	{ 0x801678, "flush_scheduled_work" },
	{ 0x6526c592, "___pskb_trim" },
	{ 0x60a4461c, "__up_wakeup" },
	{ 0xb742fd7, "simple_strtol" },
	{ 0x25da070, "snprintf" },
	{ 0x96b27088, "__down_failed" },
	{ 0x27067900, "usb_free_urb" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0x28facbe7, "usb_alloc_urb" },
	{ 0xd563bf71, "per_cpu__softnet_data" },
};

static const char __module_depends[]
__attribute_used__
__attribute__((section(".modinfo"))) =
"depends=at76_usbdfu";


MODULE_INFO(srcversion, "9BCD58BB0A853D6C867D1F9");
