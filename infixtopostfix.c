#include "stdio.h"
#include "stdlib.h"
/* this piece of program demonstrates how array
 * implimented stack can be used to convert 
 * infix expressions into postfix expressions.
 */
//definition of the stack ADT
typedef struct{
    int size, top;
    char *arr;
}stack;
/* pred function basically returns 
 * a certain operator precedence.
 * 
 * PARAM: @a, the character 
 */
int pred(char a){
    if(a=='*'||a=='/') return 2;
    else if(a=='+'||a=='-')return 1;
    else return 0;
}
/* isOprtr function checks whether a 
 * character is a operator or not.
 * 
 * PARAM: @a, the character 
 */
int isOprtr(char a){
    if(a=='+'||a=='-'||a=='*'||a=='/')return 1;
    return 0;
}
/* slen function checks how many characters 
 * are there in a string/character array.
 *
 * PARAM: @a, the character array/string pointer
 */
int slen(char *a){
    int len=0;
    while(a[len]!='\0') len++;
    return len;
}
/* isEmpty deduce whether the stack is empty 
 * or not.
 * 
 * PARAM: @ptr, the stack's address
 */
int isEmpty(stack *ptr){
    if(ptr->top == -1) return 1; 
    return 0;
}
/* push inserts new elements into the stack
 * from the top of the stack, following the
 * LIFO sequence.
 * 
 * PARAM: @ptr, the stack's address
 * PARAM: @data, the elements value that will be inserted
 */
void push(stack *ptr, char data){
    ptr->arr[ptr->top+1] = data;
    ptr->top++;
}
/* pop deletes the top most node and returns
 * its contents aka the element, following the
 * LIFO sequence.
 * 
 * PARAM: @ptr, the stack's address
 */
char pop(stack *ptr){
    if(!isEmpty(ptr)){
        char temp = ptr->arr[ptr->top];
        ptr->top--;
        return temp;
    }
    return '0';
}
/* stackTop returns the top most element of the 
 * stack, and there's no element aka the stack 
 * itself is empty it will return 0. 
 * 
 * PARAM: @ptr, the stack's address
 */
char stackTop(stack *ptr){
    if(ptr->top == -1) return '0';
    return ptr->arr[ptr->top];
}
/* infTOpsf function is converter which convertes
 * an infix expression into a postfix expression.
 *
 * PARAM: @str, the infix expression
*/
char* infTOpsf(char* str){
    int len = slen(str), i=0, j=0;
    char *outbuff = (char*)malloc(len*sizeof(char));
    stack* stk = (stack*)malloc(sizeof(stack));
    stk->size = 10;
    stk->top = -1;
    stk->arr = (char*)malloc(stk->size* sizeof(char));
    while(str[i]!='\0'){
        if(isOprtr(str[i])){
            if(pred(stackTop(stk)) >= pred(str[i])){
                outbuff[j] = pop(stk);
                j++;
            }
            else{
                push(stk, str[i]);
                i++;
            }
        }
        else{
            outbuff[j] = str[i];
            i++;
            j++;
        }
    }
    while(!isEmpty(stk)){
        outbuff[j] = pop(stk);
        j++;
    }
    outbuff[j] = '\0';
    return outbuff;
}

int main(){
    char inbuff[100];
    printf("Enter Any Expression: ");
    scanf("%[^\n]%*c", inbuff); 

    printf("%s", infTOpsf(inbuff));
    return 0;
}