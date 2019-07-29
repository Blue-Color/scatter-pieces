#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

int main(){
	
	char key[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;ZXCVBNM,./";
	int len = strlen(key);
	int i, correct;
	
	char str[1000] = {0};
	
	while( gets(str) != NULL){
		
		for(i = 0; str[i] != '\0'; i++){
			//if it's space, just print space
			if(str[i] == ' ')
				printf(" ");
			else{
				int j = 0;
				//check the character is the same as key[j+1] (j+1 because the result is its left, which is key[j])
				while(str[i] != key[j+1])
					j++;
			
				printf("%c", key[j]);
			} 
		}
		printf("\n");
	}
	
	return 0;
}
