#include "stdio.h"

int Rec_binsrc(int *arr, int high, int sval){
    static int low = 0;
    int mid;
    if(low<=high){
        mid = (low+high)/2;
        if(arr[mid]<sval){
            low = mid+1;
            return Rec_binsrc(arr, high, sval);
        }
        else if(arr[mid]>sval){
            return Rec_binsrc(arr, mid-1, sval);
        }
        else if(arr[mid]==sval){
            low = 0;
            return mid;
        }
    }
    else{
        low = 0;
        return -1;
    }
}