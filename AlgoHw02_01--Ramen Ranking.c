/*2020.04.09 finished*/
/*FINAL VER.*/
//Result : all right
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



/*MY ORTIGINAL VER. 1*/
//Result : just got 1 or 2 answers right
#include <bits/stdc++.h> 
using namespace std;

int nBowls;

long invCount(long d[], int left, int mid, int end){
	long *tmp=(long *)malloc(nBowls*sizeof(long));
	long iCou=0;

	int i=left, j=mid, k=left;

	while( (i <= mid-1) && (j <=end)){
		//printf("i = %d   j = %d\nd[i] = %d    d[j] = %d\n", i, j, d[i], d[j]);
		if(d[i] <= d[j])
			tmp[k++] = d[i++];
		else{
			tmp[k++] = d[j++];
			iCou++;
			//printf("iCou = %d   mid-i = %d\n\n", iCou, mid-i);
		}
	}
	for(int m=i; m<=mid-1; m++)
		tmp[k++]=d[m];
	for(int m=j; m<=end; m++)
		tmp[k++]=d[m];
	for(int m=left; m<=end; m++)
		d[m]=tmp[m];

	return iCou;
}

long divide(long d[], int start, int end){
	int mid;
	long r=0;
	//printf("\nstart = %d    end = %d  \n\n", start, end);
	if(start < end){
		//printf("\n====\ncount = %d\n", r);
		mid = (start+end)/2;

		divide(d, start, mid);
		//printf("\n------\n");
		divide(d, mid+1, end);

		r += invCount(d, start, mid+1, end);
	}
	//cout << roundOfTaste << endl;
	return r;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> nBowls;
	
	long *d = (long *)malloc(nBowls*sizeof(long));

	for(int i=0; i<nBowls; i++){
		cin >> d[i];
		//cout << d[i]<<endl;
	}

	long roundOfTaste = divide(d, 0, nBowls-1);
	cout << roundOfTaste << endl;

	return 0;
}



/*MY ORTIGINAL VER. 2*/
//Result : just got 1 or 2 answers right
#include <bits/stdc++.h> 
using namespace std;

int nBowls, nCheck;
int roundOfTaste=0;
long *d = (long *)malloc(nBowls*sizeof(long));
long minD=1000000000, maxD=0;
int minI=0, maxI=0;

int max(int x, int y){
	return (x>=y)? x : y;
}
int invCount(int med, int index){
	if( (index > med) || index == med )
		return nCheck-index;
	return index;
}

void check(long d[], int minI, int maxI, int med){
	//printf("minI = %d     maxI = %d   med = %d\n", minI, maxI, med);
	int inv1 = invCount(med, minI);
	int inv2 = invCount(med, maxI);
	//printf("inv1 = %d     inv2 = %d\n", inv1, inv2);

	if( (minI+maxI)/2 == med ){
		//printf("\n1\n");
		roundOfTaste = inv1 + inv2;
	}else if(minI < med && maxI > med){
		roundOfTaste = maxI - minI + 1;
	}else{
		roundOfTaste = max(inv1, inv2);
	}
	return ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> nBowls;
	for(int i=0; i<nBowls; i++){
		//printf("\nn = %d\n", nBowls);
		//printf("min = %d  %d   max = %d  %d\n", minD, minI, maxD, maxI);
		scanf("%d", &d[i]);
		cout << d[i]<<endl;
		if(d[i] < minD){
			minD = d[i];
			minI = i;
		}
		if(d[i] > maxD){
			maxD = d[i];
			maxI = i;
		}
	}
	
	nCheck = nBowls-1;
	int med;
	if( nBowls%2 ){ //odd
		//printf("\nodd\n");
		med = nCheck/2;
	}else{ //even
		//printf("\neven\n");
		med = nCheck/2 + 1;
	}
	printf("med = %d\n", med);
	
	check(d, minI, maxI, med);
	cout << roundOfTaste;
	return 0;
}



/*MY ORTIGINAL VER. 3*/
//Result : got no right i think? but here is more and more close to the final ver.
#include <stdio.h>
#include <stdlib.h>

struct ramen{
	long del;
	int oldIndex;
	int newIndex=-1;
};

int nBowls, nCheck;
//long *d = (long *)malloc(nBowls*sizeof(long));
long minD=1000000000, maxD=0;
int minI=0, maxI=0;
ramen *d = (ramen *)malloc(nBowls*sizeof(ramen));

void swap(int x, int y){
    long tmpD = d[x].del;
    d[x].del = d[y].del;
    d[y].del = tmpD;

    int tmpOi = d[x].oldIndex;
    d[x].oldIndex = d[y].oldIndex;
    d[y].oldIndex = tmpOi;

    int tmpNi = d[x].newIndex;
    d[x].newIndex = d[y].newIndex;
    d[y].newIndex = tmpNi;

    printf("\nx :  del = %d   old = %d   new = %d  \n",  d[x].del,  d[x].oldIndex, d[x].newIndex);
    printf("\ny :  del = %d   old = %d   new = %d  \n",  d[y].del,  d[y].oldIndex, d[y].newIndex);
}
void merge(long *arr, int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 

    printf("\n\nl = %d   m = %d   r = %d \n\n", l, m, r);
    /* create temp arrays */
    int L[n1], R[n2]; 
    int tmpLi[n1], tmpRi[n2];
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++){ 
        L[i] = arr[l + i]; 
        tmpLi[i]=l+i;
        printf("L = %d  l+i = %d   index = %d   arr = %d \n", L[i], l+i, tmpLi[i], arr[l+i]);
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1+ j];
        tmpRi[j] = m + 1+ j; 
        printf("R = %d  m + 1+ j = %d   index = %d   arr = %d \n", R[j], m + 1+ j, tmpRi[j], arr[m + 1+ j]);
    }
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) { 
    	printf("\ni = %d   j = %d\n", i, j);
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            d[tmpLi[i]].newIndex = k;
            //swap(tmpLi[i], tmpRi[j]);
             printf("k = %d  index = %d  new_index = %d   d = %d    L = %d\n", k, tmpLi[i], d[tmpLi[i]].newIndex, d[tmpLi[i]].del, L[i]);
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            d[tmpRi[j]].newIndex = k;
            swap(tmpRi[j], tmpLi[i]);
             printf("k = %d   index = %d  new_index = %d   d = %d    R = %d\n", k,  tmpRi[j], d[tmpRi[j]].newIndex, d[tmpRi[j]].del, R[j]);
            j++; 
        } 
        k++; 
    }
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        d[tmpLi[i]].newIndex = k;

        printf("k = %d   new_index = %d   d = %d    L = %d\n", k,  d[tmpLi[i]].newIndex, d[tmpLi[i]].del, L[i]);
        i++; 
        k++; 
    }
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        if( d[tmpRi[j]].del == R[j])
        	d[tmpRi[j]].newIndex = k;
         printf("k = %d   new_index = %d   d = %d    R = %d\n", k,  d[tmpRi[j]].newIndex, d[tmpRi[j]].del, R[j]);
        j++; 
        k++; 
    } 
} 
void mergeSort(long *m, int start, int end){ 
	
	if (start < end) { 
    		//printf("\n\n=======\n\n");
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        	int mid = start+(end-start)/2; 
  		//printf("s = %d   m = %d   l = %d \n", start, mid, end);
        	// Sort first and second halves 
        	mergeSort(m, start, mid); 
        	mergeSort(m, mid+1, end); 
  
        	merge(m, start, mid, end); 
    	} 
} 

int main(){

	scanf("%d", &nBowls);
	long *m = (long *)malloc(nBowls*sizeof(long));
	for(int i=0; i < nBowls; i++){
		//printf("\nn = %d\n", nBowls);
		printf("min = %d  %d   max = %d  %d\n", minD, minI, maxD, maxI);
		scanf("%d", &d[i].del);
		m[i] = d[i].del;
		d[i].oldIndex = i;
		printf("i = %d   del = %d   m = %d\n", i, d[i].del, m[i]);
	}

	mergeSort(m, 0, nBowls-1);
	printf("\n\n\n\n");
	for(int i=0; i<nBowls;i++){
		printf("d = %d     old index = %d   new index = %d\n", d[i], d[i].oldIndex, d[i].newIndex);
	}
	return 0;
}



/*MY ORTIGINAL VER. 4*/
//Result : this is definitely the closest to the final ver. , but when i code this there are still some small details that
//			i haven't truely understand
#include <stdio.h>
#include <stdlib.h>

struct ramen{
	long del;
	int oldIndex;
	int newIndex=-1;
};

//long *d = (long *)malloc(nBowls*sizeof(long));
long minD=1000000000, maxD=0;
int minI=0, maxI=0;
ramen *d = (ramen *)malloc(nBowls*sizeof(ramen));
ramen *ori = (ramen *)malloc(nBowls*sizeof(ramen));

void swap(int x, int y){
    int tmp = x;
    //d[].oldIndex=x;
    printf("\nx :  del = %d   old = %d   new = %d  \n",  d[x].del,  d[x].oldIndex, d[x].newIndex);
    printf("\ny :  del = %d   old = %d   new = %d  \n",  d[y].del,  d[y].oldIndex, d[y].newIndex);
}
void merge(ramen *d, int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 

    printf("\n\nl = %d   m = %d   r = %d \n\n", l, m, r);
  // d[l]
    /* create temp arrays */
    ramen L[n1], R[n2]; 
    int tmpLi[n1], tmpRi[n2];
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++){ 
        L[i].del = d[l + i].del; 
        L[i].oldIndex=d[l+i].oldIndex;
        printf("L = %d  l+i = %d   index = %d   arr = %d \n", L[i].del, l+i, L[i].oldIndex, d[l + i].del);
    }
    for (j = 0; j < n2; j++){
        R[j].del = d[m + 1+ j].del;
        R[j].oldIndex = d[ m + 1+ j].oldIndex; 
        printf("R = %d  m + 1+ j = %d   index = %d   arr = %d \n", R[j].del, m + 1+ j, R[j].oldIndex,d[m + 1+ j].del);
    }
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
    	printf("\ni = %d   j = %d\n", i, j);
        if (L[i].del <= R[j].del) 
        { 
            d[k].del = L[i].del; 
            d[k].newIndex = k;
            d[k].oldIndex = L[i].oldIndex;
            //swap(tmpLi[i], tmpRi[j]);
             printf("k = %d  index = %d  new_index = %d   d = %d    L = %d\n", k, d[k].oldIndex, d[k].newIndex, d[k].del, L[i].del);
            i++; 
        } 
        else
        { 
            d[k].del = R[j].del; 
            d[k].newIndex = k;
            d[k].oldIndex = R[j].oldIndex;
            //swap(tmpRi[j], tmpLi[i]);
             printf("k = %d   index = %d  new_index = %d   d = %d    R = %d\n", k,  d[k].oldIndex, d[k].newIndex, d[k].del, R[j].del);
            j++; 
        } 
        k++; 
    } 
 
    while (i < n1) 
    { 
        d[k].del = L[i].del; 
        d[k].newIndex = k;
        d[k].oldIndex = L[i].oldIndex;
        printf("k = %d  index = %d  new_index = %d   d = %d    L = %d\n", k, d[k].oldIndex, d[k].newIndex, d[k].del, L[i].del);
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        d[k].del = R[j].del; 
        d[k].newIndex = k;
        d[k].oldIndex = R[j].oldIndex;
         printf("k = %d   index = %d  new_index = %d   d = %d    R = %d\n", k,  d[k].oldIndex, d[k].newIndex, d[k].del, R[j].del);
        j++; 
        k++; 
    } 
} 
void mergeSort(ramen*d, int start, int end){ 

	if (start < end) 
    { 
    	printf("\n\n=======\n\n");
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int mid = start+(end-start)/2; 
  	//printf("s = %d   m = %d   l = %d \n", start, mid, end);
        // Sort first and second halves 
        mergeSort(d, start, mid); 
        mergeSort(d, mid+1, end); 
  
        merge(d, start, mid, end); 
    } 
} 

int main(){

	scanf("%d", &nBowls);

	for(int i=0; i < nBowls; i++){
		//printf("\nn = %d\n", nBowls);
		//printf("min = %d  %d   max = %d  %d\n", minD, minI, maxD, maxI);
		scanf("%d", &d[i].del);
		d[i].oldIndex = i;
       // ori[i].oldIndex=i;
		//printf("i = %d   del = %d   \n", i, d[i].del);
	}

	mergeSort(d, 0, nBowls-1);
	//printf("\n\n\n\n");
    int max=0, ans;
	for(int i=0; i<nBowls;i++){
		//printf("d = %d     old index = %d   new index = %d\n", d[i], d[i].oldIndex, d[i].newIndex);
        ans = abs(d[i].oldIndex-d[i].newIndex);
        if(ans >= max)
            max = ans;
	}
    printf("\n");
    printf("%d", max-1);
	return 0;
}



/*MY ORTIGINAL VER. 5*/
//Result : got small number's right, but big numbers' test no ( cause the time complexity is O(n^2) )
//			this is after i got some tips from my classmates, but still not fully grasped the idea
#include <stdio.h>
#include <stdlib.h>

int main(){

	int nBowls;
	scanf("%d", &nBowls);
	
	long long *d = (long long *)malloc(nBowls*sizeof(long long));
	//long countFront[nBowls];
	//long countBack[nBowls];
	long long counter[nBowls];
	for(int i=0; i<nBowls; i++){
		scanf("%lld", &d[i]);
		//printf("d = %lld\n", d[i]);
		counter[i]=0;
	}
	//printf("n = %d\n", nBowls);
	
	
	for(int i=0; i<nBowls; i++){
		
		int j=0;
		for( j=0; j < i; j++){
			if( d[j] > d[i])
				counter[i]++;	
			//printf("\ncount front = %d\n", countFront[i]);
		}
		// here i just realize i dont need to count the index bigger than d[i]
		// cause it'll always be smaller than the counts from smaller than d[i]
/*
		int metBig=0;
		for(int k=j+1; k < nBowls; k++){
			//printf("\nd[k] = %lld  i = %d next = %lld   back = %d\n", d[k], i, d[i], metBig);
			if(d[k] < d[i]){
				if(metBig){
					countBack[i]++;
					metBig=0;
				}
			}
			else{
				metBig=1;
			}
			//printf("\ncount back = %d\n", countBack[i]);
		}*/
		//printf("count front = %ld    back = %ld\n", countFront[i], countBack[i]);
	}
	
/*
	for(int i=0; i<nBowls;i++)
		counter[i] = countFront[i] + countBack[i];
*/
	long long max = counter[0];

	for(int i=0; i<nBowls;i++){
		if(counter[i] > max){
			max = counter[i];
		}
	}
	printf("%lld", max);

	free(d);
	return 0;
}
