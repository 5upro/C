#include "stdio.h"
#include "stdlib.h"
#include "stack.h"
#include "stack0.h"

int main(){
    node *top = NULL;

    stacktrav(top);
    for(int i=1; i<=5; i++){
        push(&top, i);
    }
    stacktrav(top);
    printf("the top most element of the stack is: %d\nthe bottom most element of the stack is: %d\n", stackTop(top), stackBottom(top));
    for(int i=0; i<5; i++){
        printf("%d ", pop(&top));
    }
    printf("\n");
    stacktrav(top);
    printf("the top most element of the stack is: %d\nthe bottom most element of the stack is: %d\n", stackTop(top), stackBottom(top));
    stacktrav(top);
    for(int i=1; i<=10; i++){
        push(&top, i);
    }
    stacktrav(top);
    for(int i=1; i<=10; i++){
        printf("%d ", peek(top, i));
    }
    return 0;
}