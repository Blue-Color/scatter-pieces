#include <stdio.h>
#include <stdint.h>

int square_sum(int n){
	
	int res = 0;
	
	while(n != 0){
		res += (n%10)*(n%10);
		n /= 10;
	}
	return res;
}

int length(int n){
	
	int len=0;
	while(n != 0){
		len++;
		n /= 10;
	}
	return len;
}

int main(){
	
	int total, count = 1;
	int num, origin;
	scanf("%d", &total);
	
	while(total != 0){
		
		scanf("%d", &num);
		origin=num;
		
		int len=0;
		
		while(len != 1){
			num=square_sum(num);
			len=length(num);
		}
		
		if(num == 1){
			printf("Case #%d: %d is a Happy number.\n", count, origin);
		}else {
			printf("Case #%d: %d is an Unhappy number.\n", count, origin);
		}
	
		count++;
		total--;
	}
	
	return 0;
}
