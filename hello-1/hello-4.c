/*
 * hello-4.c - Demonstrates module documentation
 */
#include <linux/init.h> /* Needed for the macros */
#include <linux/kernel.h> /* Needed for pr_info() */
#include <linux/module.h> /* Needed by all modules */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("IceFox99");
MODULE_DESCRIPTION("A sample driver");

static int __init hello_4_init(void)
{
    pr_info("Hello, world 4\n");
    return 0;
}

static void __exit hello_4_exit(void)
{
    pr_info("Goodbye, world 4\n");
}

module_init(hello_4_init);
module_exit(hello_4_exit);
