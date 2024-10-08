#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "gcdui.h"
#include "gcdprocess.h"

int main(){
    wlcmscr();
    char buf[1024];
    while(1){
        fscr();
        input(buf, 1024);
    
        if(options(buf)==0){
            endscr();
            break;
        }
        else if(options(buf)==1){
            int retVal = gcdMenu();
            if(retVal==-1){
                endscr();
                break;
            }
        }
        else if(options(buf)==2){
            int retVal = lcmMenu();
            if(retVal==-1){
                endscr();
                break;
            }
        }
        else{
            inverr();
        }
    }
    return 0;
}