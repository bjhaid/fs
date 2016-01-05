#include <linux/init.h>
#include <linux/list.h>
#include <linux/types.h>
#include<linux/slab.h>
#include <linux/module.h>

struct birthday {
  int day;
  int month;
  int year;
  struct list_head list;
};

static int __init ayo_init(void)
{
	static LIST_HEAD(birthday_list);
	struct birthday *person, *ptr, *next;
	printk("ayo module loaded\n");

	person = kmalloc(sizeof(*person), GFP_KERNEL);
	person->day = 2;
	person->month= 8;
	person->year = 1995;
	INIT_LIST_HEAD(&person->list);
	list_add_tail(&person->list, &birthday_list);
	person = kmalloc(sizeof(*person), GFP_KERNEL);
	person->day = 3;
	person->month= 9;
	person->year = 1996;
	list_add_tail(&person->list, &birthday_list);

	list_for_each_entry_safe(ptr,next,&birthday_list,list) {
		/* on each iteration ptr points */
		/* to the next birthday struct */
                printk("Day is %d, Month is %d, Year is %4d\n", ptr->day, ptr->month, ptr->year);
		list_del(&ptr->list);
		kfree(ptr);
	}
	return 0;
}

static void __exit ayo_fini(void)
{
	printk("ayo module unloaded\n");
}

module_init(ayo_init);
module_exit(ayo_fini);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ayo");
