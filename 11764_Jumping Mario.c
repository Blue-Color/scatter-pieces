/*2019.07.26 finished*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	
	int t = 0;
	
	scanf("%d", &t);
	
	int n = 0, i = 0, c = 1;
	int num[50] = {0};
	
	while(t != 0){
		
		scanf("%d", &n);
		
		for(i = 0; i < n; i++){
			scanf("%d", &num[i]);
		}
		
		int high = 0, low = 0;
		
		for(i = 0; i < n-1; i++){
			if(num[i] > num[i+1]){
				low++;
			}
			else if(num[i] < num[i+1])
				high++;
			
		}
	
		
		printf("Case %d: %d %d\n", c, high, low);
		c++;
		t--;
	}
	
	return 0;	
}



/*2019.08.05 ADD*/

//IMPROVE VERSION

#include <stdio.h>

int main(){

	int t = 0;
	
	scanf("%d", &t);
	
	int n = 0, i = 0, c = 1;
	int wallLast, wallNow;
	
	while(t != 0){
	
		scanf("%d", &n);
		
		if(n==1 || n==0){
			printf("Case %d: 0 0\n", c);
			c++;
			t--;
			continue;
		}
		
		//**the part which is different**//
		scanf("%d", &wallLast);
		int high = 0, low = 0;
		for(i=0; i < n-1; i++){
			scanf("%d", &wallNow);
			
			if(wallLast < wallNow)
				high++;
			else if(wallLast > wallNow)
				low++;
			wallLast = wallNow;
		}
		//**the part which is different**//
		
		printf("Case %d: %d %d\n", c, high, low);
		c++;
		t--;
	}
	
	return 0;
}

