#include "stdio.h"

int main(){
	int arr[5];
	int max1,min1,min2,max2;
	char r[12]="\033[31;1m",g[12]="\033[32;1m",e[12]="\033[0m";
	printf("Enter elements in the array separated by %senter/spaces%s:\n",r,e);

	for(int i=0; i<5; i++) scanf("%d", &arr[i]);
	
	if(arr[0] < arr[1]) max1 = max2 = arr[0], min1 = min2 = arr[1];
	else max1 = max2 = arr[1], min1 = min2 = arr[0];
	 
	for(int i=0; i<5; i++){
	    arr[i] > max1 ? max2 = max1, max1 = arr[i] : arr[i] > max2 && arr[i] < max1 ? max2 = arr[i] : max2;
	   	arr[i] < min1 ? min2 = min1, min1 = arr[i] : arr[i] < min2 && arr[i] > min1 ? min2 = arr[i] : min2;
	}

	printf("First largest number is %s%d%s and Smallest number is %s%d%s\nSecond largest number is %s%d%s and smallest number is %s%d%s", g,max1,e,g,min1,e,g,max2,e,g,min2,e);
    return 0;
}