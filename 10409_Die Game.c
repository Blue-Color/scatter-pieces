#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(){
	
	//set variable => command line -> int 
	//set variable => get "north" , "south", etc. -> string
	int com, i;
	char direct[5]={0};
	
	while(scanf("%d", &com) != EOF){
		
		if(com == 0){
			break;
		}
		
		int top=1, N=2, S=5, E=4, W=3, bot=6, tmp;
		
		for(i = 0; i < com; i++){
			
			scanf("%s", direct);
			
			if( strcmp(direct, "north") == 0){
				tmp=top;
				top=S; //original South number became the top number
				N=tmp; //original top number became North number
				S=bot; //original bottom number became South number
				bot=abs(7-top); //bottom number is always = |(7-top)| number
			}else if( strcmp(direct, "south") == 0){
				tmp=top;
				top=N;
				S=tmp;
				N=bot;
				bot=abs(7-top);
			}else if( strcmp(direct, "east") == 0){
				tmp=top; 
				top=W; //original West number became the top number
				E=tmp; //original top number became East number
				W=bot; //original bottom number became West number
				bot=abs(7-top);
			}else if( strcmp(direct, "west") == 0){
				tmp=top;
				top=E;
				W=tmp;
				E=bot;
				bot=abs(7-top);
			}
		}
		printf("%d\n", top);
		
	}
	
	
	return 0;
} 
