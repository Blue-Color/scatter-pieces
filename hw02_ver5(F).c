#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int n;
long d;
int havePage=0;

int min(int x, int y) { return (x<y)? x : y; }

void sumDis(int m[], int start, int end){

	int tmpS = start, moveFor=0;
	long sum=0;

	while(tmpS <= end+1){
		if(sum == d){
			havePage=1;
			return ;
		}
		else if(sum < d && (start+moveFor) != end+1){
			sum += m[start+moveFor];
			moveFor++;
		}
		else if(sum > d && tmpS != moveFor){
			sum -= m[tmpS];
			tmpS++;
		}
		else
			break;
	}
	return ;

}
void divide(int m[], int n) { 
	
	int curSize, leftIndex, mid, rightEnd;  
	
	if(n==1){
		if(m[0]==d){
			havePage=1;
		}
		return ;
	}

	for (curSize=1; curSize<=n-1; curSize = 2*curSize) { 
   		
		for (leftIndex=0; leftIndex <=n-1; leftIndex += 2*curSize) { 

			rightEnd = min(leftIndex + 2*curSize - 1, n-1);
			mid = min(leftIndex + curSize - 1, n-1);
  			//printf("mid = %d   rightEnd = %d\n", mid, rightEnd);
  			
  			sumDis(m, leftIndex, mid);
  			if(havePage){
  				return ;
  			}
  			sumDis(m, mid, rightEnd);
  			if(havePage){
  				return ;
  			}

       } 
   } 
 	sumDis(m, 0, n-1);
 	if(havePage){
  		return ;
  	}
	
}
int main(){


	scanf("%d%d", &n, &d);
	int *m = (int *)malloc(n*sizeof(int));
	
	for(int i=n-1; i>=0; i--){
		scanf("%d", &m[i]);
	}
	
	divide(m, n);

	if(havePage)
		printf("yes");
	else
		printf("no");

	free(m);
	return 0;
}
