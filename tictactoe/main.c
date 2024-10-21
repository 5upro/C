#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "gui.h"
#include "process.h"

int main(){
    //wlcmscr();
    cls();
    while(1){
        frntscr();
        char buf[10];
        fflush(stdout);
        scanf(" %s", buf);
        if(selfcmp(buf, "play")){
            int8 retval = game();
            if(retval==0){
                endscr();
                break;
            }
            else if(retval==1){
                cls();
            }
        }
        else if(selfcmp(buf, "exit")) {
            endscr();
            break;
        }
        else{
            errtxt();
        }
    }
    return 0;
}