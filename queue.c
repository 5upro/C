#include "stdio.h"
#include "stdlib.h"
#include "queue.h"

int main(){
    queue *q = (queue*)malloc(sizeof(queue));

    q->size = 20; 
    q->b = q->f = -1;
    q->arr = (int*)malloc(q->size * sizeof(int));
    
    printf("Initial Queue:\n");
    queueTrav(q);
    for(int i=0; i<10; i++) enqueue(q, i+1);
    printf("\nQueue After Insertion:\n");
    queueTrav(q);
    printf("\nCurrent first element is %d\n", firstVal(q));
    printf("Current last element is %d\n", lastVal(q));
    printf("\nDequeuing First 5 Elements:\n");
    for(int i=0; i<5; i++) printf("%d ", dequeue(q));
    printf("\n\nQueue After Deletion:\n");
    queueTrav(q);
    printf("\nCurrent first element is %d\n", firstVal(q));
    printf("Current last element is %d\n", lastVal(q));
    printf("\ncurrent 00'th element is %d\n", peek(q, 0));
    printf("current 02'nd element is %d", peek(q, 2));
    return 0;
}