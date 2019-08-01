/*2019.07.20 finished*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){
	
	int t = 0;
	scanf("%d", &t);
	
	printf("Lumberjacks:\n");
	
	int num[11] ={0};
	int i = 0, j = 0;
	
	
	while(t != 0){
		
		int unOrder = 0;
		
		for(i = 0; i < 10; i++){
			scanf("%d", &num[i]);
		}
		
		if(num[0] < num[1]){
			
			for(j = 1; j < 9; j++){
			
				if(num[j] > num[j+1])
					unOrder = 1;
			}
			if(num[8] > num[9])
				unOrder = 1;
				
			if(unOrder == 1)
				printf("Unordered\n");
			else
				printf("Ordered\n");
				
		}
		else if(num[0] > num[1]){
				
			for(j = 1; j < 9; j++){
				if(num[j] < num[j+1])
					unOrder = 1;
			}
			if(num[8] < num[9])
				unOrder = 1;
				
			if(unOrder == 1)
				printf("Unordered\n");
			else
				printf("Ordered\n");
			
		}
		
		t--;
	}
	return 0;
}
