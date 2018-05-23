#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DJ");
MODULE_DESCRIPTION("Getting started with kernel modules");
MODULE_VERSION("1.0");

static char *name = "world";
module_param(name,charp,S_IRUGO);
MODULE_PARM_DESC(name, "WTF I am doing?");

static int __init helloworld_init(void){
	printk(KERN_INFO "Hello world:::: %s !!!\n", name);
	return 0;
}

static void __exit helloworld_exit(void){
	printk(KERN_INFO "Good Bye %s !!!\n",name);
}

module_init(helloworld_init);
module_exit(helloworld_exit);
