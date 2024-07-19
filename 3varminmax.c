#include "stdio.h"

int main(){
    int a, a1, a2, t=0;
    scanf("%d %d %d", &a, &a1, &a2);
    t = a>a1 ? a>a2 ? a : a2 : a1>a2 ? a1 : a2;
    printf("%d",t);
    return 0;
}