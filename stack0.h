#ifndef STACK_01_SLL
#define STACK_01_SLL

/* Stack is a ADT, which can be implimented
 * using arrays or linked lists.
 * the stack ADT follows the LIFO/FILO sequence.
 * LIFO: Last In First Out.
 * FILO: First In Last Out.
 * 
 * this header file contains all the basic
 * operations/functions required to initialize,
 * insert, delete and manipulate the stack. 
 * 
 * note that, the stack operations/functions 
 * that are defined in this header file are 
 * only compatible for linked list implimented
 * stack.
 */
//definition of the node ADT 
#ifndef SLL_NODE
#define SLL_NODE
typedef struct node{
    int data;
    struct node* next;
}node;
#endif
/* isEmpty deduce whether stack is empty or not.
 * 
 * PARAM: @tp, the stack's top most node's address 
 */
int isEmpty(node *tp){
    if(tp==NULL) return 1;
    return 0;
}
/* isFull deduce whether stack is Full or not.
 * 
 * PARAM: @tp, the stack's top most node's address 
 */
int isFull(node *tp){
    node *nw = (node*)malloc(sizeof(node));
    if(nw==NULL) return 1;
    return 0;
}
/* stacktrav traverse through the stack
 * if the stack is not empty, if the stack
 * is empty then it will raise an error.
 * 
 * PARAM: @tp, the stack's top most node's address
 */
void stacktrav(node *tp){
    node *ptr = tp;
    if(isEmpty(tp)){
        printf("[!]Stack is Empty!\n");
    }
    else{
        while(ptr!=NULL){
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}
/* peek returns the certain position's contents.
 * 
 * PARAM: @tp, the stack's top most node's address
 * PARAM: @index, the position/index of the node 
 */
int peek(node *tp, int index){
    if(isEmpty(tp)){
        printf("[!]Stack Underflow!\n");
    }
    else{
        node *ptr = tp;
        for(int i=0; i<index-1 && ptr!=NULL; i++){
            ptr = ptr->next;
        }
        if(ptr!=NULL){
            return ptr->data;
        }
    }
    return 0;
}
/* push inserts new elements into the stack
 * from the top of the stack, following the
 * LIFO sequence.
 * 
 * PARAM: @ptr, the (main's) local variable's address
 * where the stack's top most node's address is stored
 * PARAM: @data, the elements value that will be inserted
 */ 
void push(node **tp, int data){
    if(isFull(*tp)){
        printf("[!]Stack Overflow!\n");
    }
    else{
        node *nw = (node*)malloc(sizeof(node));
        nw->data = data;
        nw->next = (*tp);
        *tp = nw;
    }
}
/* pop deletes the top most node and returns
 * its contents aka the element, following the
 * LIFO sequence.
 * 
 * PARAM: @ptr, the (main's) local variable's address
 * where the stack's top most node's address is stored
 */ 
int pop(node **tp){
    if(isEmpty(*tp)){
        printf("[!]Stack Underflow!\n");
    }
    else{
        node *n = *tp;
        *tp = (*tp)->next;
        int data = n->data;
        free(n);
        return data;
    }
}
/* stackBottom returns the bottom most 
 * element of the stack, and there's no bottom
 * element aka the stack itself is empty it will
 * return 0 and a error.
 * 
 * PARAM: @ptr, the stack's top most node's address
 */
int stackBottom(node *tp){
    if(isEmpty(tp)){
        printf("[!]Stack Underflow!\n");
        return 0;
    }
    node* ptr = tp;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    return ptr->data;
}
/* stackTop returns the top most element of the 
 * stack, and there's no element aka the stack 
 * itself is empty it will return 0 and a error. 
 * 
 * PARAM: @ptr, the stack's top most node's address
 */
int stackTop(node *tp){
    if(isEmpty(tp)){
        printf("[!]Stack Underflow!\n");
        return 0;
    } 
    return tp->data;
}
#endif