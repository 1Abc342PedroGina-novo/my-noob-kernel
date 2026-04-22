#ifndef _MM_H
#define _MM_H

#define PAGE_SIZE 4096

typedef struct vm_zone {
    unsigned long start;
    unsigned long end;
    unsigned long free_pages;
    struct vm_zone *next;
} vm_zone_t;

typedef struct vm_kern {
    vm_zone_t *kernel_zone;
    vm_zone_t *dma_zone;
    vm_zone_t *normal_zone;
    unsigned long total_pages;
} vm_kern_t;

extern unsigned long get_free_page(void);
extern unsigned long put_page(unsigned long page, unsigned long address);
extern void free_page(unsigned long addr);

void *memory_alloc(unsigned long size, int flags);
void *zeroallocmemory(unsigned long size);
int kern_mem_mgr(int cmd, void *ptr, unsigned long size);

#endif
