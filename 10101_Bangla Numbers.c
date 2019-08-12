#include <stdio.h>
#include <stdint.h>

//・kuti・ (10000000), ・lakh・ (100000), ・hajar・ (1000), ・shata・ (100)
void banglaNum(uint64_t n){
	
	if(n/10000000){
		
		banglaNum(n/10000000);
		printf(" kuti");
		
		n %= 10000000;
		
	}
	if(n/100000){
		
		banglaNum(n/100000);
		printf(" lakh");
		
		n %= 100000;
		
		
	}
	if(n/1000){
		
		banglaNum(n/1000);
		printf(" hajar");
			
		n %= 1000;
		
	}
	if(n/100){
		banglaNum(n/100);
		printf(" shata");
			
		n %= 100;
	
	}
	if(n != 0){
		printf(" %lld", n);
		
	}
	
}

int main(){
	
	uint64_t num;
	int count=1;
	
	while(scanf("%lld", &num) != EOF){
		
		printf("%4d.", count);
		
		if( num )
			banglaNum(num);
		else
			printf(" 0");
		printf("\n");
		count++;
	}
	
	return 0;
} 
