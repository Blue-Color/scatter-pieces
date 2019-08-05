/*2019.08.04 finished*/
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
		}
		
		//start to find the max of frequency
		int max=0;
		
		for(i='A'; i<='Z'; i++){
			max = MAX(max, key[i]);
		}
		for(i='a'; i<='z'; i++){
			max = MAX(max, key[i]);
		}
		
		//first display upper alphabets, then lower ones
		//check if the numbers in array is the same as max => means it's the same max frequency
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
