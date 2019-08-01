#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	
	int v = 0, t = 0;
	int i = 0;
	
	int d = 0, a = 0;
	
	while(scanf("%d %d", &v, &t) != EOF){
		
		
		d = 2*v*t;
		
		printf("%d\n", d);
	}
	return 0;	
}
