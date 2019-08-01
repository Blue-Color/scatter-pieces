#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	
	int t = 0;
	
	scanf("%d", &t);
	
	
	int a = 0, f = 0, count = 1, tmp = 0;
	int i = 0, j = 0;
	
	while(t != 0 && scanf("%d%d", &a, &f) != EOF){
	
		tmp = f;
		while(f != 0){
			
			count = 1;
			for(i = 1; i <= a; i++){
				for(j = 1; j <= i; j++){
					printf("%d", count);
				}
				printf("\n");
				count++;
			}
			count -= 2;
			for(i = a-1; i > 0; i--){
				for(j = i; j > 0; j--){
					printf("%d", count);
				}
				printf("\n");
				count--;
			}
				
			f--;	
			if(f != 0)
				printf("\n");
		
		}
		
		t--;
		if(t != 0)
			printf("\n");
	}
	return 0;	
}
