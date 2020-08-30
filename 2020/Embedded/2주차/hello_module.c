#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
//201524582_정희석 2주차 모듈프로그래밍 코드 
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
