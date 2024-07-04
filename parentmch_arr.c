#include "stdio.h"
#include "string.h"
#include "stdlib.h"
/* this piece of program demonstrates how array 
 * implimented stacks can be used to check whether
 * a expression's parentheses are in a balanced 
 * order or not.
 */
//definition of the stack ADT
typedef struct stack{
    int size, top;
    char *arr;
}stack;
/* isEmpty deduce whether the stack is empty 
 * or not.
 * 
 * PARAM: @ptr, the stack's address
 */
int isEmpty(stack *ptr){
    if(ptr->top==-1) return 1;
    return 0;
}
/* push inserts new elements into the stack
 * from the top of the stack, following the
 * LIFO sequence.
 * 
 * PARAM: @ptr, the stack's address
 */
void push(stack *ptr, char data){
    ptr->top++;
    ptr->arr[ptr->top] = data;
}
/* pop deletes the top most node and returns
 * its contents aka the element, following the
 * LIFO sequence.
 * 
 * PARAM: @ptr, the stack's address
 */ 
char pop(stack *ptr){
    if(isEmpty(ptr)){
        return 0;
    }
    char data = ptr->arr[ptr->top];
    ptr->arr[ptr->top] = '0';
    ptr->top--;
    return data;
}
/* stackTop returns the top most element of the 
 * stack, and there's no element aka the stack 
 * itself is empty it will return 0 and a error.
 * 
 * PARAM: @ptr, the stack's address
 */
char stackTop(stack *ptr){
    if(isEmpty(ptr)) return 0;
    return ptr->arr[ptr->top];
}
/* isPren function returns 0 if it's not a parenthesis
 * if its a opening parenthesis it will return 1 or 
 * it's a closing parenthesis it will return 2.
 * 
 * PARAM: @a, the characters that will be inserted
 */
int isPren(char a){
	if(a=='('||a=='{'||a=='[') return 1;
	else if(a==')'||a=='}'||a==']') return 2;
	return 0;
}
/* match function checks whethers, the first character  
 * is a opening parenthesis and the second is a closing 
 * parenthesis or not.
 * 
 * PARAM: @a, opening parenthesis, the stackTop character
 * PARAM: @b, closing parenthesis, the buff[i] character
 */
int match(char a, char b){
	if((a=='('&&b==')') || (a=='{'&&b=='}') || (a=='['&&b==']')) return 1;
	return 0;
}
/* multipren function checks whether, the prentheses 
 * in a expression are in a balanced order or not.
 * 
 * PARAM: @exp, the expression string
 */
int multipren(char *exp){
    stack *ptr = (stack*)malloc(sizeof(stack));
    ptr->size = 10;
    ptr->top = -1;
    ptr->arr = (char*)malloc(ptr->size * sizeof(char));
    for(int i=0; exp[i]!='\0'; i++){
        if(isPren(exp[i])==1){
            push(ptr, exp[i]);
        }
        else if(isPren(exp[i])==2){
            if(!match(stackTop(ptr), exp[i])){
                return 0;
            }
            pop(ptr);
        }
    }
    if(!isEmpty(ptr)) return 0;
    return 1;
}

int main(){
    char buff[100];
    printf("Enter any Expresion: ");
    fgets(buff, 100, stdin);
    printf("%d", multipren(buff));
    multipren(buff) ? printf("Balanced Expression") : printf("Unbalanced Expression");
    return 0;
}