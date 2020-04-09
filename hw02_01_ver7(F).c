#include <stdio.h>
#include <stdlib.h>

typedef struct r{
	long long del;
	int oldIndex;
	int newIndex;
}ramen;

int nBowls;

void merge(ramen *d, int l, int m, int r) { 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 

    ramen L[n1], R[n2]; 
 
    for (i = 0; i < n1; i++) {
        L[i].del = d[l + i].del;
        L[i].oldIndex=d[l+i].oldIndex; 
    }
    for (j = 0; j < n2; j++) {
        R[j].del = d[m + 1+ j].del; 
        R[j].oldIndex = d[ m + 1+ j].oldIndex; 
    }
  
   
    i = 0; 
    j = 0;
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i].del <= R[j].del) { 
            d[k].del = L[i].del; 
            d[k].newIndex = k;
            d[k].oldIndex = L[i].oldIndex;
            i++;
        } 
        else{ 
            d[k].del = R[j].del; 
            d[k].newIndex = k;
            d[k].oldIndex = R[j].oldIndex;
             j++;
        } 
        k++; 
    } 
  
    while (i < n1) { 
        d[k].del = L[i].del; 
        d[k].newIndex = k;
        d[k].oldIndex = L[i].oldIndex;
        i++; 
        k++; 
    } 
  
    
    while (j < n2) { 
        d[k].del = R[j].del; 
        d[k].newIndex = k;
        d[k].oldIndex = R[j].oldIndex;
        j++; 
        k++; 
    } 
    return ;
} 
  
void mergeSort(ramen*d, int start, int end){ 

	if (start < end) { 
        int mid = start+(end-start)/2; 
  		
        mergeSort(d, start, mid); 
        mergeSort(d, mid+1, end); 
  
        merge(d, start, mid, end); 
    } 
} 


int main(){

	
	scanf("%d", &nBowls);

	ramen *d = (ramen *)malloc(nBowls*sizeof(ramen));
	for(int i=0; i<nBowls; i++){
		scanf("%lld", &d[i].del);
		d[i].oldIndex = i;
		d[i].newIndex = -1;
	}

	mergeSort(d, 0, nBowls-1);

	long long ans, max=0;
	for(int i=0; i<nBowls;i++){
        ans = d[i].oldIndex-d[i].newIndex;
        if(ans >= max && ans > 0)
            max = ans;
	}
	printf("%lld", max);
	
	free(d);
	return 0;
}