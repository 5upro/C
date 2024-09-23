#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "tttprocess.h"
#include "tttgui.h"

int main(){
    //wlcmscr();
    while(1){
        cls();
        frntscr();
        char buf[50];
        fflush(stdout);
        gets(buf);
        if(selfcmp(buf, "play")){
            cls();
            game();
            puts("> ");
            fflush(stdout);
            gets(buf);
        }
        else if(selfcmp(buf, "")) {
            endscr();
            break;
        }
    }
    return 0;
}