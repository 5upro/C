#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "unistd.h"
#include "gcdui.h"
#include "gcdprocess.h"

int main(){
    cls();
    while(1){
        fmsg();
        int *arr, len;
        char buf[1024];
        fflush(stdin);
        fgets(buf, 1024, stdin);
        
        int val = strcmp(buf, "exit"); 
        if(val==1){
            endscr();
            break;
        }
        else{
            arr = strToarr(buf, &len);
            for(int i=0; i<len; i++){
                printf("%d ",arr[i]);
            }
            //fflush(stdin);
            //fgets(buf, 1024, stdin);
            sleep(1);
        }
    }
    return 0;
}