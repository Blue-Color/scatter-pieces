#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

int digit_sum (int s){
	
	int l = 0;
	
	while(s != 0){
		l += s%10;
		s = s/10;
	}

	return l;
}

int main(){
	
	int r = 0;
	int n = 0, rs = 0;
	
	scanf("%d", &n);
	
	while(n != 0){
		
		rs = n;
		while(rs >= 10){
			rs = digit_sum(rs);
		}
		printf("%d\n", rs);
		scanf("%d", &n);
	}
	
	return 0;
}
