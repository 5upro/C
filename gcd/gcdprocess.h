#ifndef __GCD_PROCESS_
#define __GCD_PROCESS_

int isInt(char c){
    if((int)c>=48 && (int)c<=57) return 1;
    return 0;
}

int charToInt(char c){
    return (int)c-48;
}

int selfcmp(const char *a, const char *b){
    int i=0;
    while(a[i]!='\0'&& b[i]!='\0'){
        if(!(a[i]==b[i])) return 0;
        i++;
    }
    return 1;
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

void input(char *str, int len){
    printf("\t\t\t");
    fflush(stdin);
    fgets(str, len, stdin);
}
int options(char *str){
    if(selfcmp(str, "exit")) return 0;
    else if(selfcmp(str, "gcd")) return 1;
    else if(selfcmp(str, "lcm")) return 2;
    else if(selfcmp(str, "back")) return 3;
    else return -1;
}
int gcd(){
    char buf[1024];
    while(1){
        gcdscr();
        input(buf, 1024);
        if(options(buf)==0){
            return -1;
        }
        else if(options(buf)==2){
            return lcm();
        }
        else if(options(buf)==3){
            break;
        }
        else{
            inverr();
        }
    }
}
int lcm(){
    char buf[1024];
    while(1){
        lcmscr();
        input(buf, 1024);
        if(options(buf)==0){
            return -1;
        }
        else if(options(buf)==1){
            return gcd();
        }
        else if(options(buf)==3){
            break;
        }
        else{
            inverr();
        }
    }
}

#endif