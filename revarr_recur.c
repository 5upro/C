/* this piece of program demonstrates an array reversal using
 * a recursive approach
 */
#include "stdio.h"
#include "stdlib.h"

/* arrRev function (abbreviation for array reversal) reverses
 * an array using recursion
 * 
 * PARAM: @arr, array's first/0'th index's address
 * PARAM: @end, said array's last index
 */
void arrRev(int* arr, int end){
    static int dec = 0;
    int begin = 0+dec;
    if(begin < end){
        arr[begin] = arr[begin]^arr[end];
        arr[end] = arr[begin]^arr[end];
        arr[begin] = arr[begin]^arr[end];
        dec++;
        arrRev(arr, end-1);
    }
}
/* travArr function (abbreviation for Array Traversal) traverses
 * whole array and prints individual elements one by one
 * 
 * PARAM: @ptr, array's first/0'th index's address
 * PARAM: @size, said array's total number of elements
 */
void travArr(int *ptr, int size){
    for(int i=0; i<size; i++){
        printf("%d ", *(ptr+i));
    }
    printf("\n");
}

int main(){
    int *arr, size;
    
    printf("Enter the size of the Array: ");
    scanf("%d", &size);
    arr = (int*)malloc(size * sizeof(int));
    printf("Enter the %d elements(separated by spaces): ", size);
    for(int i=0; i<size; i++){
        scanf("%d", arr+i);
    }

    printf("Array elements before the reversal: ");
    travArr(arr, size);
    arrRev(arr, size-1);
    printf("Array elements after the reversal: ");
    travArr(arr, size);
    return 0;
}