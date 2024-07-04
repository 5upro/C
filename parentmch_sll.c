#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/* this piece of program demonstrates how can stacks
 * be used to check whether a expression's parentheses
 * are is in balanced order or not.
 */
//definition of the node/Stack ADT 
typedef struct node{
    char data;
    struct node* next;
}node;
/* isEmpty deduce whether stack is empty or not.
 * 
 * PARAM: @tp, the stack's top most node's address 
 */
int isEmpty(node* ptr){
    if(ptr==NULL) return 1;
    return 0;
}
/* pop deletes the top most node and returns
 * its contents aka the element, following the
 * LIFO sequence.
 * 
 * PARAM: @ptr, the (main's) local variable's address
 * where the stack's top most node's address is stored
 */
int pop(node** ptr){
    if(isEmpty(*ptr)){
        return 0;
    }
    node* temp = *ptr;
    *ptr = (*ptr)->next;
    free(temp);
    return 1;
}
/* push inserts new elements into the stack
 * from the top of the stack, following the
 * LIFO sequence.
 * 
 * PARAM: @ptr, the (main's) local variable's address
 * where the stack's top most node's address is stored
 * PARAM: @data, the elements value that will be inserted
 */
void push(node** ptr, char data){
    node* nw = (node*)malloc(sizeof(node));
    nw->data = data;
    nw->next = *ptr;
    *ptr = nw;
}
/* stackTop returns the top most element of the 
 * stack, and there's no element aka the stack 
 * itself is empty it will return 0 and a error. 
 * 
 * PARAM: @ptr, the stack's top most node's address
 */
int stackTop(node* ptr){
    if(isEmpty(ptr)) return 0;
    return ptr->data;
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
 * in a expression in a balanced order or not.
 * 
 * PARAM: @buff, the expression string
 */
int multipren(char *buff){ 
	node* stk = NULL;
	for(int i=0; buff[i]!='\0'; i++){
		if(isPren(buff[i]) == 1){
			push(&stk, buff[i]);
		}
		else if(isPren(buff[i]) == 2){
			if(!match(stackTop(stk), buff[i])){
				return 0;
			}
			pop(&stk);
		}
	}
	if(!isEmpty(stk)) return 0;
	return 1;
}
int main(){
    char buff[1000];
    int flag=1;
    
    printf("Enter Any Expression: ");
    fgets(buff, 1000, stdin);

    multipren(buff) ? printf("Balanced Expression") : printf("Unabalanced Expression");
    return 0;
}