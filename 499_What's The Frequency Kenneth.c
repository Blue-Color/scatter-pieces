#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

#define MAX(x, y) (x>y ? x : y)


int main(){
	
	char str[1000]={0};
	int  i, j;
	
	
	while( fgets(str, sizeof(str), stdin) != NULL){
		
		int key[256]={0};
		
		for(i=0; str[i] != '\0'; i++){
			
			if(str[i] == ' ')
				continue;
				
			key[(int)str[i]]++;
			//printf("str : %d\n", key[(int)str[i]]);
		}
		
		int max=0;
		
		for(i='A'; i<='Z'; i++){
			max = MAX(max, key[i]);
			//printf("max : %d\n", max);
		}
		for(i='a'; i<='z'; i++){
			max = MAX(max, key[i]);
			//printf("max : %d\n", max);
		}
		

		
		for(i='A'; i<='Z'; i++){
			if(key[i] == max)
				printf("%c", i);
		}
		for(i='a'; i<='z'; i++){
			if(key[i] == max)
				printf("%c", i);
		}
		printf(" %d\n", max);
	}
	
	

	return 0;	
} 
