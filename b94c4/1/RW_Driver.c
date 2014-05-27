#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/errno.h> /* error codes */
#include <linux/types.h> /* size_t */
#include <linux/proc_fs.h>
#include <linux/fcntl.h> /* O_ACCMODE */
//#include <linux/asm/system.h> /* cli(), *_flags */
#include <asm/uaccess.h> /* copy_from/to_user */
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/kdev_t.h>
#include <linux/slab.h>
//#include <linux/config.h>
static dev_t first; // Global variable for the first device number 
static struct cdev c_dev; // Global variable for the character device structure
static struct class *cl; // Global variable for the device class
//static int major_num = 60;
char *str;

int hello_open(struct inode *inode,struct file *filep)
{

	printk("hello open:\n");
	return 0;
}
int hello_release(struct inode *inode,struct file *filep)
{
	printk("hello close\n");
	return 0;
}
ssize_t hello_read(struct file *filep,char *buf,size_t count, loff_t *f_pos)
{
	printk("in hello read\n");
	if (copy_to_user(buf, str, count) != 0)
        	return -EFAULT;
    	else
		printk("bytes read is %s\n",buf);
		return 0;
}
ssize_t hello_write(struct file *filep,const char *buf,size_t count, loff_t *f_pos)
{
	printk("hello write\n");
	if (copy_from_user(str, buf,count) != 0)
        return -EFAULT;
    else
	printk("bytes write is %s\n",str);
	return count;
}
static const struct file_operations hello_fops =
{
 	.open = hello_open,
	.release = hello_release,
	.read  = hello_read,
 	.write = hello_write,

};
static int __init  hello_init(void)  //constructor
{
	int result;
	result = alloc_chrdev_region(&first, 0, 1, "chints");
if(result<0)
{
	printk("error in register\n");
}
  // Allocating memory for the buffer 
  str = kmalloc(1000, GFP_KERNEL); 
  if (str==NULL)
   printk(KERN_INFO,"error in allocating \n");
   
 if ((cl = class_create(THIS_MODULE, "chardrv")) == NULL)
  {
    unregister_chrdev_region(first, 1);
    return -1;
  }
	    if (device_create(cl, NULL, first, NULL, "hello") == NULL)
  {
    class_destroy(cl);
    unregister_chrdev_region(first, 1);
    return -1;
  }
    cdev_init(&c_dev, &hello_fops);
    if (cdev_add(&c_dev, first, 1) == -1)
  {
    device_destroy(cl, first);
    class_destroy(cl);
    unregister_chrdev_region(first, 1);
    return -1;
  }
 
  return 0;


}
static void __exit hello_exit(void) //destructor
{

cdev_del(&c_dev);
  device_destroy(cl, first);
  class_destroy(cl);
  unregister_chrdev_region(first, 1);
  printk(KERN_INFO "Alvida: hello unregistered");

//  Freeing buffer memory 
 if (str) {
    kfree(str);
  }

}

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("chintan patel");
MODULE_DESCRIPTION("read wri:te Char Driver");
