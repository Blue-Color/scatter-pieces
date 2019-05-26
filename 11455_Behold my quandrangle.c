#include<stdio.h>
#include<stdint.h>

int main(){
	
	int total = 0, tmp = 0;
	int num[4] = {0};
	int i = 0, j = 0, k = 0;
	scanf("%d", &total);
	
	
	while(total != 0){
		
		for(i = 0; i < 4; i++)
			scanf("%d", &num[i]);
		
		//to rearrange the array (from small to big) 
		//bubble sort
		for(k = 0; k < 4; k++){
			for( j = 3; j > k; j--){
				if(num[j] < num[j-1]){
					tmp = num[j];
					num[j] = num[j-1];
					num[j-1] = tmp;
				}
				
			}
		}
		
		if(num[0] == num[1] && num[1] == num[2] && num[2]== num[3]) //if all of the edges are the same => square
			printf("square\n");
			
		else if(num[0] == num[1] && num[2] == num[3]) // if parallel edges are the same => rectangle
			printf("rectangle\n");
			
		else if(num[0]+num[1]+num[2] > num[3] ) // if the biggist edge is smaller than the sum of other 3 edges => quadrangle
			printf("quadrangle\n");
		else
			printf("banana\n"); // if neither above => banana
		
		total--;
	}
	
	return 0;
	
} 
