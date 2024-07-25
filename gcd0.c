#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "unistd.h"
#define cls() system("cls")

void endscr(){
    printf("\n\t\t\t\033[1;91mTERMINATING!\033[0m");
    sleep(1);
    cls();
}

void fmsg(){
    puts("\033[1;91m\n\t   @@@@@@@@         @@@@@@       @@@@@@@     \n\t  @@      @@       @@    @@      @@    @@    \n\t @@               @@             @@     @@   \n\t @@               @@             @@     @@   \n\t @@    @@@@@      @@             @@     @@   \n\t  @@      @@  @@   @@    @@  @@  @@    @@  @@\n\t   @@@@@@@@   @@    @@@@@@   @@  @@@@@@@   @@ \n\033[0m");
        
}

int main(int argc, char *argv []){
    char en, col[5][10]={"\033[0m","\033[1;91m","\033[1;92m","\033[1;49;34m","\033["};
    cls();
    while(1){
        int *p, *h, *c;
        int n, s, ts, fi=1, sq, j=0, div=2;
        
        fmsg();
        printf("\033[1;49;34m\n[+] Number of Operands >%s ", col[0]);
        scanf("%d",&n);
        fflush(stdin);
        if (n==0){
            endscr();
            break;
        }
        else{
            p=(int*)calloc(n,sizeof(int));
    
            /*if(p==NULL){ //will be deleted later on
                printf("0.\n");
                exit(0);
            }
            else{
                printf("1.\n");
            }*/
            cls();
            fmsg();
            printf("\033[1;49;34m\n[+]Enter the Operands Separeted by Spaces!\n e.g. x y z\n>%s ", col[0]);
            for(int i=0; i<n; ++i){
                scanf("%d",&p[i]);
            }
            /*for(int i=0; i<n; ++i){ //will be deleted later on
                printf("%d, ",p[i]);
            }*/

            s=p[0];
            for(int i=0; i<n; ++i){
                s = p[i]<s ? p[i] : s;
            }

            ts=s;
            sq=sqrt(ts);
            h=(int*)calloc(sq,sizeof(int));
            /*if(h==NULL){ //will be deleted later on
                printf("\n0.\n");
                exit(0);
            }
            else{
                printf("\n1.\n");
            }*/

            while(ts!=1){
                if(ts%div==0){
                    h[j]=div;
                    ts=ts/div;
                    j++;
                    //printf("div: %d, ts: %d\n",div, ts);
                }
                else{
                    div++;
                    //printf(".div: %d\n",div);
                }
                //printf(".j: %d\n",j);
            }
            ts=s;

            /*for(int i=0; j>i; ++i){ //will be deleted later on
                printf("%d, ",h[i]);
            }
            printf("\n%d",j);*/
    
            c=(int*)calloc(j,sizeof(int));
            /*if(c==NULL){ //will be deleted later on
                printf("\n0.\n");
                exit(0);
            }
            else{
                printf("\n1.\n");
            }*/

            for(int tc, i=0;i<n;i++){
                tc=p[i];
                for(int y=0;y<j;y++){
                    if(c[y]==0){
                        if(tc%h[y]==0){
                            tc=tc/h[y];
                            continue;
                        }
                        else{
                            c[y]=1;
                        }
                    }
                    else{
                        continue;
                    }
                }
            }

            for(int i=0;i<j;i++){
                if(c[i]==0){
                    fi=fi*h[i];
                }
            }
            printf("the gcd is %d\n",fi);
            
            printf("> ");

            en = fgetc(stdin);
            en = getchar();
            
            if(en=='0'){
                endscr();
                break;
            }
            if (en==0x0A){
                cls();
                continue;
            }
            else{
                printf("invalid input\n");
                sleep(1);
                en = getchar();
                cls();
                continue;
            }
        }
    }
    return 0;
}