#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xa4bb88f0, "module_layout" },
	{ 0x37a0cba, "kfree" },
	{ 0xc6a86c1e, "cdev_del" },
	{ 0x7485e15e, "unregister_chrdev_region" },
	{ 0x7ac9bc4, "class_destroy" },
	{ 0x5e776490, "device_destroy" },
	{ 0x228ca119, "cdev_add" },
	{ 0xb3fbdf89, "cdev_init" },
	{ 0x29872e76, "device_create" },
	{ 0x8b70e5e7, "__class_create" },
	{ 0x2beeeca9, "kmem_cache_alloc_trace" },
	{ 0x9ceda17c, "kmalloc_caches" },
	{ 0x29537c9e, "alloc_chrdev_region" },
	{ 0x362ef408, "_copy_from_user" },
	{ 0x2f287f0d, "copy_to_user" },
	{ 0x50eedeb8, "printk" },
	{ 0xb4390f9a, "mcount" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "8DD41B214EF0E37B4A7D97A");
