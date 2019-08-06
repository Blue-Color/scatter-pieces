#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	int i, num[4];
	
	while(1){
		
		for(i=0; i<4; i++)
			scanf("%d", &num[i]);
			
		if(!num[0] && !num[1] && !num[2] && !num[3] )
			break;
		
		int degree = 1080;
		
		degree += ( (num[0]-num[1]) + 40 )%40 *9;
		degree += ( (num[2]-num[1]) + 40 )%40 *9;
		degree += ( (num[2]-num[3]) + 40 )%40 *9;
		
		printf("%d\n", degree);	
	}
	
	return 0;	
}
