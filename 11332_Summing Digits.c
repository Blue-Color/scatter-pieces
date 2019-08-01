/*2019.07.20 finished*/ 
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

int digit_sum (int s){
	
	int res = 0;
	
	while(s != 0){
		res += s%10; //start from the right
		s = s/10;
	}

	return res;
}

int main(){
	
	int r = 0;
	int n = 0, rs = 0;
	
	scanf("%d", &n);
	
	while(n != 0){
		
		rs = n;
		//run the loop till there is just one number (0-9)
		while(rs >= 10){
			rs = digit_sum(rs);
		}
		printf("%d\n", rs);
		scanf("%d", &n);
	}
	
	return 0;
}
