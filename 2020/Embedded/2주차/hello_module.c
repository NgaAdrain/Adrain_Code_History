#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
//201524582_���� 2���� ������α׷��� �ڵ� 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Huins");

static int __init module_begin(void) {
    printk(KERN_ALERT "Hello, Wellcome to module!!\n");
    printk(KERN_ALERT "201524582\n"); 
    return 0;
}

static void __exit module_end(void) {
    printk(KERN_ALERT "Goodbye, Exit module!!\n");
    printk(KERN_ALERT "JEONG HEE SEOK in CSE\n");
}

module_init(module_begin);
module_exit(module_end);
