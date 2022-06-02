#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");

int module_start(void)
{
	printk ("Hello World!!\n");
	return 0;
}

void module_end(void)
{
	prink("Goodbye World!!\n");
}
module_init(module_start);
module_init(module_end);