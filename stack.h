#ifndef STACK_00__ARR
#define STACK_00__ARR

/* Stack is a ADT, which can be implimented
 * using arrays or linked lists.
 * the stack ADT follows the LIFO sequence
 * LIFO: Last In First Out
 * 
 * this header file contains all the basic
 * operations/functions required to initialize,
 * insert, delete and manipulate the stack. 
 * 
 * note that, the stack operations/functions 
 * that are defined in this header file are 
 * only compatible for array implimented
 * stack.
 */
//definition of the stack ADT
typedef struct stack{
    int size, top;
    int *arr;
}stack;
/* isEmpty deduce whether stack is empty or not.
 * 
 * PARAM: @ptr, the stack's address
 */
int isEmpty(stack *ptr){
    if(ptr->top == -1) return 1;
    return 0;
}
/* isFull deduce whether stack is full or not.
 * 
 * PARAM: @ptr, the stack's address
 */
int isFull(stack *ptr){
    if(ptr->top == ptr->size-1) return 1;
    return 0;
}
/* stktrav traverse through the whole stack
 * if the stack is not empty, if the stack
 * is empty then it will raise an error.
 * 
 * PARAM: @ptr, the stack's address
 */
void stktrav(stack *ptr){
    if(isEmpty(ptr)) printf("[!] Stack is Empty!");
    for(int i=1; i<=ptr->top+1; i++){
        printf("%d ", peek(ptr, i));
    }
    printf("\n");
}
/* push inserts new elements into the stack
 * from the top of the stack, following the
 * LIFO sequence.
 * 
 * PARAM: @ptr, the stack's address
 * PARAM: @data, the elements value that will be inserted
 */
void push(stack *ptr, int data){
    if(isFull(ptr)) printf("[!] Stack Overflow!");
    else{
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}
/* pop deletes the top most node and returns
 * its contents aka the element, following the
 * LIFO sequence
 * 
 * PARAM: @ptr, the stack's address
 */ 
int pop(stack *ptr){
    if(isEmpty(ptr)){
        //printf("[!] Stack is Empty!");
        return 0;
    }
    ptr->top--;
    return ptr->arr[ptr->top+1];
}
/* peek returns a certain positioned element's
 * value(assuming that first element's index is 01).
 * if the given position/index doesn't exist, returns 0.
 * 
 * PARAM: @ptr, the stack's address
 * PARAM: @pos, the position/index of the element
 */
int peek(stack *ptr, int pos){
    if(ptr->top-pos+1 < 0){
        //printf("[!] Given position doesn't exist/hold any Value!");
        return 0;
    }
    return ptr->arr[ptr->top-pos+1];
}
/* stackTop returns the top most element of the 
 * stack, and there's no element aka the stack 
 * itself is empty it will return 0 and an error.
 * 
 * PARAM: @ptr, the stack's address 
 */
int stackTop(stack *ptr){
    if(isEmpty(ptr)){ 
        //printf("[!] Stack is Empty!\n");
        return 0;
    }
    return ptr->arr[ptr->top];
}
/* stackBottom returns the bottom most 
 * element of the stack, and there's no bottom
 * element aka the stack itself is empty it will
 * return 0 and an error 
 * 
 * PARAM: @ptr, the stack's address
 */
int stackBottom(stack *ptr){
    if(isEmpty(ptr)){ 
        //printf("[!] Stack is Empty!\n");
        return 0;
    }
    return ptr->arr[0];
}
#endif