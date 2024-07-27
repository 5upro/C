#include "stdio.h"
#include "stdlib.h"
#include "stack0.h"
#include "math.h"

int isInt(char c){
    if((int)c>=48 && (int)c<=57) return 1;
    return 0;
}

int charToInt(char c){
    return (int)c-48;
}

int numscount(char *str){
    int count=0;
    for(int i=0, flag=0; str[i]!='\0'; i++){
        if(isInt(str[i])){
            if(!flag){
                count++;
                flag = 1;
            }
        }
        else{
            if(flag) flag=0;
        }
    }
    return count;
}

int* strToarr(char *str, int *returnlen){
    int i=0, deg=1, flag=0, idx=0, ncount=numscount(str);
    int *arr = (int*)calloc(ncount, sizeof(int));
    *returnlen = ncount;
    
    while(str[i]!='\0'){
        if(isInt(str[i])){
            arr[idx] = arr[idx]*deg + charToInt(str[i]);
            deg = 10;
            flag = 1;
        }
        else{
            if(flag){
                idx++;
                deg = 1;
                flag = 0;
            }
        }
        i++; 
    }
    return arr;
}

int main(){
    node *n = NULL;
    int *arr, j=0;
    char a[300];

    fflush(stdin);
    fgets(a, 300, stdin);    
    /*for(int i=0; a[i]!='\0'; i++){
        if(isInt(a[i])){
            push(&n, charToInt(a[i]));
        }
        else{
            if(!isEmpty(n)){
                for(int q=0; !isEmpty(n); q++){
                    arr[j] = arr[j] + (pop(&n)*pow(10, q));
                }
                j++;
            }
        }
    }
    if(!isEmpty(n)){
        for(int q=0; !isEmpty(n); q++){
            arr[j] = arr[j] + (pop(&n)*pow(10, q));
        }
        j++;
    }*/
    
    arr = strToarr(a, &j);
    printf("%d\n", j);
    for(int i=0; i<j; i++){
        printf("%d ", arr[i]);
    }
    //printf("%d", numscount(a));
    return 0;
}