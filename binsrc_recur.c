#include "stdio.h"

int binsrc_recur(int *arr, int high, int sval){
    static int low = 0;
    int mid;
    if(low<=high){
        mid = (low+high)/2;
        if(arr[mid]<sval){
            low = mid+1;
            return binsrc_recur(arr, high, sval);
        }
        else if(arr[mid]>sval){
            return binsrc_recur(arr, mid-1, sval);
        }
        else{
            low = 0;
            return mid;
        }
    }
    else{
        low = 0;
        return -1;
    }
}
int main(){
    int arr[]={9, 13, 24, 25, 32, 39, 44, 49}, n=8;
    
    for(int i=0; i<n; i++){
        printf("%d : %d\n", i, arr[i]);
    }
    
    for(int i=0; i<18; i++){
        printf("%d ", binsrc_recur(arr, n, arr[i]));
    }printf("\n");

    for(int i=0; i<18; i++){
        printf("%d ", binsrc_recur(arr, n, arr[i]));
    }printf("\n");
    
    return 0;
}