#include <stdio.h>
#include<stdint.h>

int main(){
	
	int n = 0, r = 0, live = 0;
	int i = 0;
	int sur[10005] = {0};
	
	#if 0
	ORIGNAL CODE
	int n = 0, r = 0, tmp = 0, all_live = 1;
	int i = 0, j = 0;
	int sur[] = {0};

	while( scanf("%d %d", &n, &r) != EOF){
		for(i = 0; i < r; i++)
			scanf("%d", &sur[i]);
		
		if(n == r){
			printf("*");
		}
		else{
		//small to big
			for(i = 0; i < r; i++){
				for(j = r-1; j > i; j--){
					if(sur[j] < sur[j-1]){
						tmp = sur[j];
						sur[j] = sur[j-1];
						sur[j-1] = tmp;
					}
				}	
			}
			for(i = 0; i < n; i++){
				if(sur[i] != i+1){
					printf("%d ", i+1);
				}
			}
		}
		printf("\n");	
	}
	#endif
	
	while( scanf("%d %d", &n, &r) != EOF){
		//initialize 1 to n 
		for(i = 1; i <= n; i++)
			sur[i] = 0;
		//if live, value = 1; else, value = 0
		for(i = 0; i < r; i++){
			scanf("%d", &live);
			sur[live] = 1;
		}
		//if go and return people are the same, print *
		if(n == r)
			printf("*");
		
		else{
			//if value = 0, means didn't come back, print it out
			for(i = 1; i <= n; i++){
				if(sur[i] == 0)
					printf("%d ", i);
			}
		}
		printf("\n");
	}
	
	return 0;
} 
