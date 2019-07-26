#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){
	
	int t = 0;
	
	scanf("%d", &t);
	
	int i = 0, num[2] = {0}, j = 0, c = 1;
	int k1 = 0, k2 = 0;
	
	while(t != 0){
		
		for(i = 0; i < 2; i++){
			scanf("%d", &num[i]);
		}
		
		//if [a, b], a, b either are even => change it to odd by + OR - 1
		if(num[0]%2==0)
			num[0] +=1;
		if(num[1]%2 ==0)
			num[1] -=1;
		
		//if a == b
		if(num[0] == num[1]){
			
			if(num[0]%2 == 0){
				printf("Case %d: 0\n", c);
			}
			else
				printf("Case %d: %d\n", c, num[0]);
			
			t--;
			c++;
			continue;
		}
		
		// a = 2k - 1, calculate k for range
		k1 = (num[0]-1) / 2;
		k2 = (num[1]-1) / 2;
		
		int r = num[0];
		int tmp = num[0];
		
		for(j = k1; j < k2; j++){
			tmp += 2;
			r += tmp;
			
		}
		printf("Case %d: %d\n", c, r);
		t--;
		c++;
	}

	return 0;	
}
