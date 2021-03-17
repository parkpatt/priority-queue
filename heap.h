#ifndef HEAP_H_
#define HEAP_H_

#include <stdlib.h>
#include <stdio.h>

#define LEFT(i) (2 * i)
#define RIGHT(i) (2 * i + 1)
#define PARENT(i) ((i / 2) - 1)

struct sortable_tlb_e {
  int v_addr, p_addr;
  unsigned short key;
};

void InitSortable(struct sortable_tlb_e* e);
int Swap(struct sortable_tlb_e* arr[], int len, int i1, int i2);
void MaxHeapify(struct sortable_tlb_e arr[], int len, int i);
void BuildMaxHeap(struct sortable_tlb_e arr[], int len);
int SmallestKey(struct sortable_tlb_e arr[], int len);
// maybe we want int index instead of sortable_tlb_e

#endif  // HEAP_H_
