#ifndef __GCD_PROCESS_
#define __GCD_PROCESS_

int isInt(char c){
    if((int)c>=48 && (int)c<=57) return 1;
    return 0;
}

int charToInt(char c){
    return (int)c-48;
}

void swap(int *a, int *b){
    *a = (*a)^(*b);
    *b = (*a)^(*b);
    *a = (*a)^(*b);
}

void rearrange(int *heap, int node, int len){
    int grtst = node, left = (node*2)+1, right = (node*2)+2;
    if(left < len && heap[grtst] < heap[left]) grtst = left;
    if(right < len && heap[grtst] < heap[right]) grtst = right;
    if(grtst != node){
        swap(heap+node, heap+grtst);
        rearrange(heap, grtst, len);
    }
}

void heapify(int *heap, int len){
    int current = (len/2)-1;
    for(; current>=0; current--) rearrange(heap, current, len);
}

int pop(int *heap, int *len){
    int ret;
    if(*len>0){
        ret = heap[0];
        (*len)--;
        heap[0] = heap[*len];
        rearrange(heap, 0, *len);
        return ret;
    }
}

void heapsort(int *heap, int len){
    while(len>0){
        int val = pop(heap, &len);
        heap[len] = val;
    }
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

int* strToarr(char *str, int len){
    int i=0, deg=1, flag=0, idx=0;
    int *arr = (int*)calloc(len, sizeof(int));

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
    heapify(arr, len);
    heapsort(arr, len);
    return arr;
}

void input(char *str, int len){
    printf("\t\t\t> ");
    fflush(stdin);
    fgets(str, len, stdin);
}

int primefac_count(int num){
    int j=0, div=2;
    while(num!=1){
        if(num%div==0){
            num/=div;
            j++;
        }
        else div++;
    }
    return ++j;
}

int* primefac(int num, int *ret_len){
    int len = primefac_count(num), *retarr = (int*)malloc(len * sizeof(int));
    for(int j=0, div=2; num!=1;){
        if(num%div==0){
            retarr[j]=div;
            num/=div;
            j++;
        }
        else div++;
    }
    *ret_len = len;
    return retarr;
}

int gcdcalculator(int *nums, int nums_len){
    int *pfac, pfac_len, max=0; 
    pfac = primefac(nums[0], &pfac_len);
    int *check = (int*)calloc(pfac_len-1, sizeof(int));

    for(int temp, i=0; i<nums_len; i++){
        temp = nums[i];
        if(max == nums_len) break;
        for(int y=0; y<pfac_len; y++){
            if(check[y] == 0){
                if(temp%pfac[y] == 0) temp/=pfac[y];
                else max+=check[y]=1;
            }
        }
    }
    free(nums);
    if(max == nums_len){
        free(pfac);
        free(check);
        return 1;
    }
    else{
        int retval = 1;
        for(int i=0; i<pfac_len; i++){
            if(!check[i]) retval*=pfac[i];
        }
        free(pfac);
        free(check);
        return retval;
    }
}

int lcmcalculator(char *str, int nums_len){
    int *arr = strToarr(str, nums_len), prod = 1;
    for(int i=0; i<nums_len; i++){
        prod*=arr[i];
    }
    return prod/gcdcalculator(arr, nums_len);
}

int options(char *str){
    if(selfcmp(str, "exit")) return 0;
    else if(selfcmp(str, "gcd")) return 1;
    else if(selfcmp(str, "lcm")) return 2;
    else if(selfcmp(str, "back")) return 3;
    else if(str[0]==0x0A) return 4;
    else return -1;
}
int gcdcal_menu(){
    char buf[1024];
    while(1){
        gcdscr();
        calMenu_txt();
        input(buf, 1024);
        int len = numscount(buf);
        if(len==0){
            if(options(buf)==0) return -1;
            else if(options(buf)==3) break;
            else inverr();
        }
        else if(len<2) inverr1();
        else{
            printf("\t\t\tGCD: %d\n", gcdcalculator(strToarr(buf, len), len));
            input(buf, 1024);
            if(options(buf)==0) return -1;
            else if(options(buf)==4) return gcdcal_menu();
            else if(options(buf)==3) break;
            else inverr();
        }
    }
}
int lcmcal_menu(){
    char buf[1024];
    while(1){
        lcmscr();
        calMenu_txt();
        input(buf, 1024);
        int len = numscount(buf);
        if(len==0){
            if(options(buf)==0) return -1;
            else if(options(buf)==3) break;
            else inverr();
        }
        else if(len<2) inverr1();
        else{
            printf("\t\t\tLCM: %d\n", lcmcalculator(buf, len));
            input(buf, 1024);
            if(options(buf)==0) return -1;
            else if(options(buf)==4) return lcmcal_menu();
            else if(options(buf)==3) break;
            else inverr();
        }
    }
}
int lcmMenu();
int gcdMenu(){
    char buf[1024];
    while(1){
        gcdscr();
        gcdopsscr();
        input(buf, 1024);
        if(options(buf)==0){
            return -1;
        }
        else if(options(buf)==2){
            return lcmMenu();
        }
        else if(options(buf)==3){
            break;
        }
        else if(options(buf)==4){
            int retval = gcdcal_menu();
            if(retval==-1) break;
        }
        else{
            inverr();
        }
    }
}
int lcmMenu(){
    char buf[1024];
    while(1){
        lcmscr();
        lcmopsscr();
        input(buf, 1024);
        if(options(buf)==0){
            return -1;
        }
        else if(options(buf)==1){
            return gcdMenu();
        }
        else if(options(buf)==3){
            break;
        }
        else if(options(buf)==4){
            int retval = lcmcal_menu();
            if(retval==-1) break;
        }
        else{
            inverr();
        }
    }
}


#endif