/*2020.03.27 finished*/
/*FINAL VER.*/
//Result : one big number test wrong answer, others all right
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



/*OTHER PERSON VER.*/
//Result : ??Unknown, might be all right
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int havePage=0;

int main(){

	int n=0;
	long long d=0;

	scanf("%d%d", &n, &d);
	int *m = (int *)malloc(n*sizeof(int));
	
	for(int i=0; i<n; i++){
		scanf("%d", &m[i]);
	}
	
	int tmpS = 0, moveFor=1;
	long long sum=m[0];

	while( moveFor <= n && tmpS < moveFor ){
		if(sum == d){
			havePage=1;
			break;
		}
		else if(sum < d ){
			sum += m[moveFor];
			moveFor++;
		}
		else if(sum > d ){
			sum -= m[tmpS];
			tmpS++;
		}
	}

	if(havePage)
		printf("yes");
	else
		printf("no");

	free(m);
	return 0;
}



/*MY ORTIGINAL VER. 1*/
//Result : big number inputs time exceed
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){

	int n;
	long long d;

	scanf("%d%d", &n, &d);

	int *m = (int *)malloc(n*sizeof(int));
	int i;
	
	for(i=0; i<n; i++){
		scanf("%d", &m[i]);
	}
	i--;

	int count=n;
	int tempI=1;
	int havePage=0;
	long long sum=m[0];

	while(count > 0){
		int page=m[tempI];
		
		sum += page;
		if(sum == d){
			havePage=1;
			break;
		}
		if(sum > d ){
			i--;
			tempI=i;
			n--;
			count=n;
			sum = 0;
			continue;
		}
		count--;
		tempI--;
	}
	if(havePage)
		printf("yes");
	else
		printf("no");

	free(m);
	return 0;
}


/*MY ORTIGINAL VER. 2*/
//Result : some are right, some are wrong, 
//	forget the conditions when divide into arrays 
//	the last part of one array + the first one of another array might be the answer
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


int havePage=0;
int min(int x, int y){ 
	return (x<y)? x : y; 
}
void divide(int m[], int n, int d) { 
	
	int curSize, leftIndex;  
	int sum1, sum2;
	int mid, rightEnd;
	if(n==1){
		sum1=m[0];
		if(sum1==d){
			havePage=1;
		}
	
		return ;
	}

	for (curSize=1; curSize<=n; curSize = 2*curSize) { 
   		
       // Pick starting point of different subarrays of current size 
		for (leftIndex=0; leftIndex<n-1; leftIndex += 2*curSize) { 
			sum1=0, sum2=0;
       			//printf("curr_size = %d   left = %d\n", curSize, leftIndex);
			mid = min(leftIndex + curSize - 1, n-1); 
			rightEnd = min(leftIndex + 2*curSize - 1, n-1); 
  			//printf("mid = %d   rightEnd = %d\n", mid, rightEnd);
  			
  			for(int j=mid; j>=leftIndex; j--){
  				sum1 += m[j];
  				//printf("a[j] = %d    sum1 = %d\n\n", m[j], sum1);
  				if(sum1 == d){
  					havePage=1;
  					return;
  				}
  			}
  			/*//plus middle value
  			for(int i=mid+1; i<=rightEnd; i++){
  				sum1+=m[i];
  				printf("\n\nmiddle + \n\na[i] = %d    sum1 = %d\n\n", m[i], sum1);
  				if(sum1 == d){
  					havePage=1;
  					return;
  				}
  			}*/
  			//int tmpRight = mid+1;
  			for(int i=rightEnd; i>=mid+1; i--){
  				sum2 += m[i];
  				//printf("a[i] = %d    sum2 = %d\n\n", m[i], sum2);
  				if(sum2 == d){
  					havePage=1;
  					return;
  				}
  			}
  			/*//plus middle value
  			for(int i=rightEnd+1; i<n; i++){
  				sum2+=m[i];
  				printf("\n\nmiddle + \n\na[i] = %d    sum2 = %d\n\n", m[i], sum2);
  				if(sum2 == d){
  					havePage=1;
  					return;
  				}
  			}*/
		} 
	} 
  	//printf("curr_size = %d   left = %d   sum1 = %d   sum2 = %d   mid = %d right = %d\n", curr_size, left_start, sum1, sum2, mid, right_end);
	for(int k=mid+1; k <= rightEnd; k++){
		sum1+=m[k];
   		printf("a[j] = %d    sum1 = %d\n\n", m[k], sum1);
   		if(sum1 == d){
  			havePage=1;
  			return;
  		}
	}
	
}
/*
void test(int m[], int n, int d){

	for(int i=0; i<n; i++){
		printf("\nstart\n\n");
		divide(m, n, d);
		if(havePage)
			return ;
		n--;
	}
}*/
int main(){

	int n;
	int d;

	scanf("%d%d", &n, &d);
	printf("d = %d\n", d);
	//int tmp[]={4, 6, 3 ,1, 3, 7}; 
	//int tmp2[]={7, 3, 1, 3, 6, 4}; //4 6 3 1 3 7
	int *m = (int *)malloc(n*sizeof(int));
	int i;
	
	for(i=n-1; i>=0; i--){
		scanf("%d", &m[i]);
	}
	
	divide(m, n, d);
	if(havePage)
		printf("yes");
	else
		printf("no");

	return 0;
}



/*MY ORTIGINAL VER. 3*/
//Result : change it from iterative to recursive, still the same results as the iterative one 
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


int n;
int64_t d;

void sumDis(int m[], int start, int end){

	printf("start = %d   end = %d\n", start, end);

	int tmpS=start, movefor=0;
	int64_t sum=0;

	while(tmpS <= end){
		//printf("tmpS = %d   movefor = %d st+mf = %d  \nm[start+movefor] = %d\n\n", tmpS, movefor, start+movefor, m[start+movefor]);
		//printf("\nsum = %d\n", sum);
		if(sum == d){
			printf("yes");
			exit(0);
		}
		else if(sum < d && (start+movefor) <= end){
			sum += m[start+movefor];
			movefor++;
		}
		else if(sum > d && tmpS != movefor){
			sum -= m[tmpS];
			tmpS++;
		}
		else
			break;
	}
}
void divide(int m[], int start, int end){

	if(start < end){
		int middle = start + (end-start)/2;

		divide(m, start, middle);
		divide(m, middle+1, end);
	}
	sumDis(m, start, end);

}

int main(){
	
	scanf("%d%d", &n, &d);
	int *m = (int *)malloc(n*sizeof(int));
	
	for(int i=0; i<n; i++){
		scanf("%d", &m[i]);	
	}
	divide(m, 0, n-1);
	
	printf("no");
	return 0;
}
