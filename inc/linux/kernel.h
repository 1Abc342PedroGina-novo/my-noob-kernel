

#ifndef _LINUX_KERNEL_H
#define _LINUX_KERNEL_H

void verify_area(void *addr, int count);
void panic(const char *str);
int printf(const char *fmt, ...);
int printk(const char *fmt, ...);
int tty_write(unsigned ch, char *buf, int count);
void *malloc(unsigned int size);
void free_s(void *obj, int size);

#define free(x) free_s((x), 0)

#define suser() (current->euid == 0)

int init_srv(int srv_id, void *entry, int priority);
void *pmap(unsigned long phys_addr, unsigned long size, int flags);
int obj_mgr(int cmd, int obj_id, void *data);
long ipc(int dest_id, const void *msg, unsigned long len, int flags);

#endif
