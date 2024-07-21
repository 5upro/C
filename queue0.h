#ifndef QUEUE_SLL
#define QUEUE_SLL

#ifndef SLL_NODE
#define SLL_NODE
typedef struct node{
    int data;
    struct node* next;
}node;
#endif
/* 
 */
int isEmpty(node *ptr){
    if(ptr==NULL) return 1;
    return 0;
}

int isFull(){
    node* temp = (node*)malloc(sizeof(node));
    if(temp==NULL)return 1;
    free(temp);
    return 0;
}

void queTrav(node *fptr){
    node *temp = fptr;
    if(isEmpty(fptr)){
        printf("Queue Underflow!\n");
    }
    else{
        while(temp!=NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    } 
}

void enqueue(node **fptr, node **rptr, int data){
    if(!isFull()){
        node *nw = (node*)malloc(sizeof(node));
        nw->data = data;
        nw->next = NULL;
        if((*fptr)==NULL){
            *fptr = *rptr = nw;
        }
        else{
            (*rptr)->next = nw;
            *rptr = nw;
        }
    }
    else printf("Queue Overflow!");
}

int dequeue(node **fptr, node **rptr){
    int val=-1;
    if(!isEmpty(*fptr)){
        node *temp = *fptr;
        val = temp->data;
        if(*fptr==*rptr) *rptr=NULL;
        *fptr = (*fptr)->next;
        free(temp);
    }
    return val;
}

int lastVal(node *rptr){
    if(!isEmpty(rptr)) return rptr->data; 
    return -1;
}

int firstVal(node *fptr){
    if(!isEmpty(fptr)) return fptr->data;
    return -1;
}

#endif