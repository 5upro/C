#include "stdio.h"
#include "math.h"
/* NARCISSISTIC NUMBERS:
 * in number theory, a Narcissistic Number 
 * (also known as a Pluperfect Digital Invariant (PPDI), 
 * an Armstrong Number (after Michael F. Armstrong) 
 * or a Plus Perfect Number) in a given number base b 
 * is a number that is the sum of its own digits each 
 * raised to the power of the number of digits.
 * source: https://en.wikipedia.org/wiki/Narcissistic_number
 * 
 * this piece of program decduces whether a number is
 * narcissistic number or not.
 * in our case, the base is 10
 */
/* isNarci function checks whether a integer is
 * narcissistic number or not. 
 * 
 * PARAM: @num, the integer that suppose to get
 * decuded 
 */
int isNarci(int num){
    int digit = log10(num)+1, val = 0;
    for(int i=0; i<digit; i++){
        val += pow(num/(int)pow(10, i)%10, digit);
    }
    return val;
}
int main(){
    int x;
    printf("Enter a number to Check whether the number is a narcissistic number or not.\nEnter the number: ");
    scanf("%d", &x);
    isNarci(x)==x ? printf("\033[1;49;42m%d \033[0m is a Narcissistic number.", x) : printf("\033[1;49;41m%d\033[0m is not a Narcissistic number.", x);
    return 0;
}