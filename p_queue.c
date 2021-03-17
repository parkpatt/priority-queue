#include "p_queue.h"

void Init_P_Queue(struct tlb_p_queue* q){
  q->currsize = 0;
  q->len = P_QUEUE_CAPACITY;
  for (int i = 0; i < q->len; i++){
    q->arr[i].v_addr = q->arr[i].p_addr = q->arr[i].key = 0;
  }
}

int IncreaseKey(struct tlb_p_queue* q, int i, int k){
  if (k < q->arr[i].key)
    return 0;
  q->arr[i].key = k;
  while (i > 0 && q->arr[PARENT(i)].key < q->arr[i].key){
    printf("i is %d. parent of i is %d\n", i, PARENT(i));
    printf("swapping %d (child) with %d (parent)\n",
	   q->arr[i].key, q->arr[PARENT(i)].key);
    Swap(q->arr, q->currsize, i, PARENT(i));
    i = PARENT(i);
  }
  return 1;
}

void Insert(struct tlb_p_queue* q, struct sortable_tlb_e entry){
  q->arr[q->currsize] = entry;
  IncreaseKey(q, q->currsize, entry.key);
  q->currsize++;
}

struct sortable_tlb_e Maximum(struct tlb_p_queue* q){
  return q->arr[0];
}

void RemoveMax(struct tlb_p_queue* q){
  if (q->currsize > 0){
    q->currsize --;
    q->arr[0] = q->arr[q->currsize];
    MaxHeapify(q->arr, q->currsize, 0);
  }
}

int P_IsFull(struct tlb_p_queue* q){
  return q->currsize == q->len;
}

int P_IsEmpty(struct tlb_p_queue* q){
  return q->currsize == 0;
}

int P_Dequeue(struct tlb_p_queue* q){
  if (P_IsEmpty(q))
    return 0;
  RemoveMax(q);
  return 1;
}

int P_Enqueue(struct tlb_p_queue* q, struct sortable_tlb_e entry){
  if (P_IsFull(q)){
    if (!P_Dequeue(q))
      return 0;
  }
  Insert(q, entry);
  return 1;
}

void PrintArrayKeys(struct tlb_p_queue* q){
  printf("[");
  for (int i = 0; i < q->len; i++){
    printf("%d,",q->arr[i].key );
  }
  printf("]\n");
}
