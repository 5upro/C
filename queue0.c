#include "stdio.h"
#include "queue0.h"

int main(){
    node *front=NULL, *rear=NULL;
    queTrav(front);
    for(int i=0; i<11; i++){
        enqueue(&front, &rear, i+1);    
    }
    queTrav(front);
    printf("first %d\nlast %d\n", firstVal(front), lastVal(rear));
    for(int i=0; i<5; i++) printf("%d ", dequeue(&front, &rear));
    printf("\n");
    queTrav(front);
    printf("first %d\nlast %d\n", firstVal(front), lastVal(rear));
    for(int i=0; i<13; i+=2) enqueue(&front, &rear, i+1);
    queTrav(front);
    printf("first %d\nlast %d\n", firstVal(front), lastVal(rear));
    return 0;
}