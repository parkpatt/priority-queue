#include "heap.h"

void InitSortable(struct sortable_tlb_e* e){
  e->v_addr = -1;
  e->p_addr = -1;
  e->key = 0;
}

int Swap(struct sortable_tlb_e* arr[], int len, int i1, int i2){
  if (i1 >= len || i2 >= len)
    return 0;
  struct sortable_tlb_e temp = *arr[i1];
  *arr[i1] = *arr[i2];
  *arr[i2] = temp;
  return 1;
}

void MaxHeapify(struct sortable_tlb_e arr[], int len, int i){
  int largest = i;
  int l = LEFT(i);
  int r = RIGHT(i);
  if (l < len && arr[l].key > arr[i].key)
    largest = l;
  if (r < len && arr[r].key > arr[i].key)
    largest = r;
  if (largest != i){
    Swap(&arr, len, i, largest);
    MaxHeapify(arr, len, largest);
  }
}

void BuildMaxHeap(struct sortable_tlb_e arr[], int len){
  for (int i = len / 2; i >= 0; i--){
    MaxHeapify(arr, len, i);
  }
}

int SmallestKey(struct sortable_tlb_e arr[], int len){
  // returns index of tlb_e with the smallest key
  int b = 1;
  int idx = 0;
  for (int i = 0; i < len; i++){
    if (b){
      idx = i;
      b = 0;
    } else if (arr[i].key < arr[idx].key)
      idx = i;
  }
  return idx;
}


