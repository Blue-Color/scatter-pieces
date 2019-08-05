/*2019.08.03 finished*/
#include <stdio.h>
#include <stdint.h>

int main(){
	
	int total, num, i;
	
	scanf("%d", &total);
	
	while(total != 0){
		
		scanf("%d", &num);
		
		int div[1000]={0}, count=0, res=0;
		
		for(i=1; i<=num; i++){
		//if num % i == 0 means it's a factor
			if(num%i == 0){
				div[count] = i;
				count++;
				
			}
		}
		//all of them plus together except the number itself
		for(i=0; i<count-1; i++){
			res += div[i];
		}
		//check whether the sum of factors is > OR < OR == the number
		if(res > num){
			printf("abundant\n");
		}else if(res < num){
			printf("deficient\n");
		}else{
			printf("perfect\n");
		}
		
		total--;
	} 
	
	return 0;
} 
