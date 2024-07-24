#include "stdio.h"
#include "stdlib.h"

int binsrc_ite(int *arr, int high, int sval){
   int low = 0, mid;
   high--;
   while(low<=high){
       mid = (low+high)/2;
       if(arr[mid]<sval){
           low = (mid)+1;
           continue;
       }
       else if(arr[mid]>sval){
           high = (mid)-1;
           continue;
       }
       else{
           return mid;
       }
   }
   return -1;
}

int main(){
    int arr[]={9, 13, 24, 25, 32, 39, 44, 49}, n=8;
    for(int i=0; i<n; i++){
        printf("%d : %d\n", i, arr[i]);
    }
    
    for(int i=0; i<18; i++){
        printf("%d ", binsrc_ite(arr, n, arr[i]));
    }printf("\n");

    for(int i=-10; i<18; i++){
        printf("%d ", binsrc_ite(arr, n, arr[i]));
    }printf("\n");
    return 0;
}