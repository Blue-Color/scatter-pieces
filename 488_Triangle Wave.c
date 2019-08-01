/*2019.07.20 finished*/
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
		//f = how many waves need to print
		while(f != 0){
			//when move to the next line, count +1
			count = 1;
			//the upper wave (line 1 - a)
			for(i = 1; i <= a; i++){
				for(j = 1; j <= i; j++){
					printf("%d", count);
				}
				printf("\n");
				count++;
			}
			//the downer wave (line a+1 - 2a-1)
			count -= 2; // cause above when jump out of the loop, count has + another 1, so -2
			for(i = a-1; i > 0; i--){
				for(j = i; j > 0; j--){
					printf("%d", count);
				}
				printf("\n");
				count--;
			}
				
			f--;
			//if need to print the next one, print enter
			if(f != 0)
				printf("\n");
		
		}
		//for other groups
		t--;
		if(t != 0)
			printf("\n");
	}
	return 0;	
}
