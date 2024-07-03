#ifndef QUEUE_ARR
#define QUEUE_ARR
/* Queue is a ADT, which can be implimented 
 * using Arrays and Link Lists. 
 * the Queue ADT follows the FIFO/LILO sequence.
 * FIFO: First In First Out
 * LILO: Last In Last Out
 * 
 * this header file contains all the basic
 * operations/functions required to initialize,
 * insert, delete and manipulate queues. 
 * 
 * note that, the queue operations/functions 
 * that are defined in this header file are 
 * only compatible for array implimented queue.
 */
//definition of queue ADT 
typedef struct{
    int size, b, f, *arr;
}queue;
/* isEmpty deduces whether the queue is empty 
 * or not.
 *
 * PARAM: @ptr, the queue's address
 */
int isEmpty(queue *ptr){
    if(ptr->b == ptr->f) return 1;
    return 0;
}
/* isFull deduces whether the queue is full 
 * or not.
 *
 * PARAM: @ptr, the queue's address
 */
int isFull(queue *ptr){
    if(ptr->b == ptr->size-1) return 1;
    return 0;
}
/* queueTrav (abbrevaition for Queue Traversal)
 * traverses the queue, id the queue is empty
 * it will raise an error.
 * 
 * PARAM: @ptr, the queue's address
 */
void queueTrav(queue *ptr){
    if(!isEmpty(ptr)){
        int i = ptr->f+1;
        for(;i<=ptr->b;i++){
            printf("%d ", ptr->arr[i]);
        }
    }
    else{
        printf("Queue Underflow!");
    }
    printf("\n");
}
/* enqueue inserts a new element into the queue,
 * following the FIFO sequence. 
 * 
 * PARAM: @ptr, the queue's address
 * PARAM: @data, the elements value that will be inserted
 */
void enqueue(queue *ptr, int data){
    if(!isFull(ptr)){
        ptr->b++;
        ptr->arr[ptr->b] = data;
    }
    else{
        printf("Queue Overflow!\n");
    }
}
/* dequeue deletes the first element of a queue,
 * following the FIFO sequence. and returns the
 * value of the element.
 * 
 * PARAM: @ptr, the queue's address
 */
int dequeue(queue *ptr){
    if(!isEmpty(ptr)){
        ptr->f++;
        return ptr->arr[ptr->f];
    }
    return 0;
}
/* peek returns a certain positioned element's
 * value(assuming that first element's index is 00).
 * if the given position/index doesn't exist, returns 0.
 * 
 * PARAM: @ptr, the queue's address
 * PARAM: @index, the position/index of the element
 */
int peek(queue *ptr, int index){
    if(!isEmpty(ptr) && ptr->f+index+1<=ptr->b) return ptr->arr[ptr->f+index+1];
    return 0;
}
/* firstVal returns a queue's current first element's
 * value but if the queue is empty it will return 0.
 * 
 * PARAM: @ptr, the queue's address
 */
int firstVal(queue *ptr){
    if(!isEmpty(ptr)) return ptr->arr[ptr->f+1];
    return 0;
}
/* lastVal returns a queue's current last element's
 * value but if the queue is empty it will return 0.
 * 
 * PARAM: @ptr, the queue's address
 */
int lastVal(queue *ptr){
    if(!isEmpty(ptr)) return ptr->arr[ptr->b];
    return 0;
}
#endif