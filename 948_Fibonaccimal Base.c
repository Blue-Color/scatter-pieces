/*2019.08.01 finished*/
#include <stdio.h>
#include <stdint.h>

int main(){
	
	int total, num, maxLen;
	
	scanf("%d", &total);
	
	int fib[40]={0}, i;
	fib[0]=1;
	fib[1]=2;
	
	//first save each Fibonacci number in array
	for(i=2; i<40; i++){
		fib[i]=fib[i-1] + fib[i-2];
	}
	
	while(total != 0){
		
		scanf("%d", &num);
		
		int flag=0;
		
		printf("%d = ", num);
		
		//start from the very last to the first
		for(i=39; i >= 0; i--){
			if(num/fib[i] == 1){
				printf("1");
				num -= fib[i];
				flag=1; //means can start print 0
			}else if(flag==1){
				printf("0");
			}
		}
		printf(" (fib)\n");
		
		total--;
	}
	
	return 0;
}
