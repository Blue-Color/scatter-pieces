#include <stdio.h>
#include <stdint.h>


int main(){
	
	long long n = 0, sum = 0, c = 0;
	
	/*
	e.g.
		N = 3 => line : 3 5 7 
		find the last number of N = 3 : 7 = 1 + 3*2 (cause each needs +2 => 1 + 2 = 3, 3 + 2 = 5, ... )
		find the last number of N = n : 1 + 3*2 + 5*2 + ... + n*2 = 1+2(3+5+...+n) = 1+2*( (n-1)/2 * (3+n) )/2 = ( n*n+2*n-1 )/2 
		
		last three numbers total : 3*( n*n+2*n-1 )/2 - 6
	
	*/
	
	while( scanf("%d", &n) != EOF){

		c = (n*n + 2*n - 1) / 2; //calculate the last number 
		sum = 3*c-6;
		
		printf("%d\n", sum);
	}
	
	return 0;
} 

