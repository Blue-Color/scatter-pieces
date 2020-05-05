/*2020.04.06 finished*/
/*FINAL VER.*/
//Result :all right ( this question is easier, so i only have one version )
#include <stdio.h>
#include <stdlib.h>

int n;

long merge(long long arr[], int l, int m, int r) { 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
	long invC=0;

    long L[n1], R[n2]; 
 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
 
    i = 0; 
    j = 0;
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else{ 
            arr[k] = R[j]; 
            j++; 
            invC += n1-i;
        } 
        k++; 
    } 
 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
     
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
    return invC;
} 
  
long mergeSort(long long arr[], int l, int r) { 
	long invCount=0;
	//printf("\nl = %d   r = %d\n", l, r);
    if (l < r) { 
        int m = l+(r-l)/2; 
        // Sort first and second halves 
       invCount += mergeSort(arr, l, m); 
        invCount += mergeSort(arr, m+1, r); 
  
        invCount += merge(arr, l, m, r); 
    } 
    return invCount;
} 

int main(){

	scanf("%d", &n);

	long long*odd = (long long *)malloc(n*sizeof(long long));
	long long*even = (long long *)malloc(n*sizeof(long long));
	long long*ori = (long long *)malloc(n*sizeof(long long));
	long long*final = (long long *)malloc(n*sizeof(long long));
	
	int n1=0, n2=0;

	for(int i=0; i<n; i++){

		scanf("%lld", &ori[i]);
		if(i%2){// odd
			odd[n1++]=ori[i];	
		}else{
			even[n2++]=ori[i];
		}
		
	}
	
	long inv1, inv2;
	long long ans;
	mergeSort(ori, 0, n-1);
	inv1=mergeSort(odd, 0, n1-1);
	inv2=mergeSort(even, 0, n2-1);

	int a1=0, a2=0;
	for(int i=0; i<n; i++){
		if(i%2){//odd
			final[i]=odd[a1++];
		}
		else{
			final[i]=even[a2++];
		}
	}
	int right=1;
	for(int i=0; i<n; i++){
		if(ori[i]!=final[i]){
			right=0;
			break;
		}
	}
	if(right)
		printf("yes\n");
	else
		printf("no\n");
	ans = inv1+inv2;
	printf("%lld", ans);

	free(odd);
	free(even);
	free(ori);
	free(final);
	return 0;
}
