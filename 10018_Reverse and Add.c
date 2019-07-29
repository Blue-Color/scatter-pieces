#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

//reverse the number
uint64_t reverse(uint64_t n){
	
	uint64_t r = 0;
	
	while(n != 0){
		r = r*10 + n%10;
		n /= 10;
	}
	
	return r;
}

int main(){
	
	int total;
	
	scanf("%d", &total);
	
	uint64_t num, rev;
	
	
	while(total != 0){
		
		int count = 0;
		
		scanf("%ld", &num);
		
		rev = reverse(num);
		
		//if num == rev, means it's palindrome
		while( num != rev){
			
			num += rev;
			rev = reverse(num);
			count++;
			
		}
	
		printf("%d %ld\n", count, num);
		
		total--;
	}
	
	return 0;
} 
