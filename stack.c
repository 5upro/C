#include "stdio.h"
#include "stdlib.h"
#include "stack.h"

int main(){
    stack *s;
    s->size = 20;
    s->top = -1;
    s->arr = (int*)malloc(s->size*sizeof(int));

    stktrav(s);
    printf(" %d\n", stackTop(s));
    printf(" %d\n", stackBottom(s));
    for(int i=0; i<=10; i++){
        push(s, i);
    }
    
    for(int i=0; i<=3; i++){
        printf("%d ", pop(s));
    }
    printf("\n");
    stktrav(s);
    printf("the top most element is %d\n", stackTop(s));
    printf("the bottom most element is %d\n", peek(s,1));
    return 0;
}