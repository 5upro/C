#include "stdio.h"
#include "stdlib.h"

void swap(int *a, int *b){
    *b = (*a)^(*b);
    *a = (*a)^(*b);
    *b = (*a)^(*b);
}

void rearrange(int *heap, int node, int len){
    int grtst = node, left = (node*2)+1, right = (node*2)+2;
    if(left < len && heap[grtst] < heap[left]) grtst = left;
    if(right < len && heap[grtst] < heap[right]) grtst = right;
    if(grtst != node){
        swap(heap+node, heap+grtst);
        rearrange(heap, grtst, len);
    }
}

void heapify(int *heap, int len){
    int current = (len/2)-1;
    for(; current>=0; current--) rearrange(heap, current, len);
}

int pop(int *heap, int *len){
    int ret;
    if(*len>0){
        ret = heap[0];
        (*len)--;
        heap[0] = heap[*len];
        rearrange(heap, 0, *len);
        return ret;
    }
}

void heapsort(int *heap, int len){
    while(len>0){
        int val = pop(heap, &len);
        heap[len] = val;
    }
}

int main(){
    int len = 7, *arrheap = (int*)malloc(len * sizeof(int));
    arrheap[0] = 1;
    arrheap[1] = 80;
    arrheap[2] = 9;
    arrheap[3] = 10;
    arrheap[4] = 71;
    arrheap[5] = 14;
    arrheap[6] = 5000;
    
    /*     __100__
     *    /       \
     *   80       90
     *  / \      / \
     * 60  70  40  50
     */
    for(int i=0; i<len; i++){
        printf("%d ", *(arrheap+i));
    }
    heapify(arrheap, len);
    puts(" ");
    for(int i=0; i<len; i++){
        printf("%d ", *(arrheap+i));
    }
    heapsort(arrheap, len);
    puts(" ");
    for(int i=0; i<len; i++){
        printf("%d ", *(arrheap+i));
    }
    return 0;
}