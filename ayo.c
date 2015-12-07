#include <linux/init.h>
#include <linux/module.h>

static int __init ayo_init(void)
{
	pr_debug("ayo module loaded\n");
	return 0;
}

static void __exit ayo_fini(void)
{
	pr_debug("ayo module unloaded\n");
}

module_init(ayo_init);
module_exit(ayo_fini);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ayo");
