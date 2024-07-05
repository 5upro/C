#include "stdio.h"
#include "math.h"
#include "stdbool.h"

int isPalin(int x) {
    if(!(x<0)){
        int dig = log10(x);
        for(int i=0; i<(dig+1)/2; i++){
            if(!(x/(int)pow(10, dig-i)%10 == x/(int)pow(10, i)%10)) return 0;
        }
        return 1;
    }
    return 0;
}

int main(){ 
    isPalin(1234567899) ? printf("1234567899 is a Palindrome\n") : printf("1234567899 is not a Palindrome\n"); 
    isPalin(0) ? printf("0 is a Palindrome\n") : printf("0 is not a Palindrome\n"); 
    isPalin(12321) ? printf("12321 is a Palindrome\n") : printf("12321 is not a Palindrome\n"); 
    isPalin(-98189) ? printf("-98189 is a Palindrome\n") : printf("-98189 is not a Palindrome\n"); 
    return 0;
}