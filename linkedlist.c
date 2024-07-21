#include "stdio.h"
#include "stdlib.h"
#include "linkedlist.h"

int main(){
	node *head;

	head = NULL;

	slltrav(head);
	for(int i=10; i>0; i--){
		head = insertatFirst(head, i);
	}
	slltrav(head);
	return 0;
}