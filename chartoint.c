#include "stdio.h"
#include "stdlib.h"
#include "stack0.h"
#include "math.h"
#include "limits.h"

int isInt(char a){
    if((int)a>=48 && (int)a<=57) return 1;
    return 0;
}

int charToInt(char c){
    return (int)c-48;
}

int main(){
    node *n = NULL;
    int arr[10] = {0}, j=0;
    char a[] = "12 24 6 48  60  60 6";
    
    for(int i=0; a[i]!='\0'; i++){
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
    //for(int i=0; a[i]!='\0'; i++){
    //    if(isInt(a[i])){
    //        push(&n, charToInt(a[i]));
    //    }
    //    else{
    //        if(!isEmpty(n)){
    //            for(int q=0; !isEmpty(n); q++){
    //                arr[j] = arr[j] + (pop(&n)*pow(10, q));
    //            }
    //            j++;
    //        }
    //    }
    //}
    if(!isEmpty(n)){
        for(int q=0; !isEmpty(n); q++){
            arr[j] = arr[j] + (pop(&n)*pow(10, q));
        }
        j++;
    }

    for(int i=0; i<j; i++){
        printf("%d %d\n", arr[i], arr[i]/2);
    }

    printf("%d", INT_MAX);
    
    return 0;
}