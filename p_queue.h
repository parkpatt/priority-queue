#ifndef P_QUEUE_H_
#define P_QUEUE_H_

#include "heap.h"
// stdlib.h and stdio.h included via heap.h

#define P_QUEUE_CAPACITY 8

struct tlb_p_queue {
  int currsize, len;
  struct sortable_tlb_e arr[P_QUEUE_CAPACITY];
};

void Init_P_Queue(struct tlb_p_queue* q);
int IncreaseKey(struct tlb_p_queue* q, int i, int k);
void Insert(struct tlb_p_queue* q, struct sortable_tlb_e entry);
struct sortable_tlb_e Maximum(struct tlb_p_queue* q);
struct sortable_tlb_e* ExtractMax(struct tlb_p_queue* q);
int P_IsFull(struct tlb_p_queue* q);
int P_IsEmpty(struct tlb_p_queue* q);
int P_Enqueue(struct tlb_p_queue* q, struct sortable_tlb_e entry);
int P_Dequeue(struct tlb_p_queue* q);
void PrintArrayKeys(struct tlb_p_queue* q);

#endif
