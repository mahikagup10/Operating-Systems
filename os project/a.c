#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>

struct task_struct *task;
struct task_struct *task_child;
struct list_head *list;

int tasks_lister_linear_init(void)
{
  printk(KERN_INFO "Loading module...\n");


  for_each_process(task)
  {
   // printk("\t-");
    printk(KERN_INFO "pid: %d | pname: %s | state: %ld\n", task->pid, task->comm, task->state);
    list_for_each(list,&task->children)
    {
      task_child = list_entry(list,struct task_struct, sibling);
      //  printk("\t\t--");
          printk(KERN_INFO "\t--CHILD_pid: %d | CHILD_pname: %s | CHILD_state: %ld\n", task_child->pid, task_child->comm, task_child->state);

    }
  }

  printk(KERN_INFO "Module loaded.\n");
  return 0;
}

void tasks_lister_linear_exit(void)
{
  printk(KERN_INFO "Module removed.\n");
}

module_init(tasks_lister_linear_init);
module_exit(tasks_lister_linear_exit);

MODULE_LICENSE("GPL");
