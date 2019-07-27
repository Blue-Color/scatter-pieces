#include <stdio.h>
#include <stdint.h>
#include <string.h> 
#include <stdlib.h>

int main() {

	int n, count = 1;
	int i;
	
	while(scanf("%d", &n) != EOF && n != -1){
		
		if(n<0){
			break;
		}
		
		int ans = 0, two = 1;
		
		//if n is <= 2*2*..., run the loop till n is > 2^ans
		while(n > two ){
			two *= 2;
			ans++;	
		}
		
		printf("Case %d: %d\n", count, ans);
		count++;
	}

	return 0;
}
