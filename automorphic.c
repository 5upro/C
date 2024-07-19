#include "stdio.h"
#include "math.h"

#define sqr(n) (n*n)

int autonum( long long int i){
	int x=pow(10, floor(log10(i)+1));
	if(sqr(i)%x==i) return 1;
	return 0;
}

int main() {
	char col[3][10]={"\033[0m","\033[1;31m","\033[1;32m"};
	while (1) {
		long long int num;
		printf("Enter Number: ");
		scanf("%lld", &num);
		if(num==0) break;
		if(autonum(num)==1){
			printf("%s.%s\n",col[2],col[0]);
			continue;
		}
		else printf("%s.%s\n",col[1],col[0]);
	}
	return 0;
}