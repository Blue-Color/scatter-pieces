/*2019.08.01 finished*/
#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(){

	char str[1000]={0};
	int i, flag=0;
	
	while( fgets(str, sizeof(str), stdin) != NULL){
		
		int count = 0;
		
		for(i=0; str[i] != '\0'; i++){
		
			if( ( str[i] >= 'A' && str[i] <= 'Z' ) || ( str[i] >= 'a' && str[i] <= 'z' )  ){
				flag=1;
			}
			//flag==1 => means there's an alphabet or word before -> count +1 
			else if(flag == 1){
				
				flag=0;
				count++;
			}
				
			
		}
		printf("%d\n", count);
	}

	return 0;	
}
