#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("AZZI Hadjer");
MODULE_DESCRIPTION("A simple example Linux kernel module");
MODULE_VERSION("0.01");

static int __init lkm_init(void) {
    printk(KERN_INFO "Kernel Module Initialized: ______Hello World, This is M2 IoT & CS______\n");
    return 0; 
}

static void __exit lkm_exit(void) {
    printk(KERN_INFO "Kernel Module Unloaded: ______Goodbye______\n");
}

module_init(lkm_init);
module_exit(lkm_exit);

