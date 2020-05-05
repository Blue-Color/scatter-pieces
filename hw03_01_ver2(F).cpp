#include <bits/stdc++.h>
using namespace std;


int  chooseErrands(int  v[], int n){

	int  **maxValue = (int  **)malloc(n*sizeof(int*));
	for (int i=0; i<n; i++) 
         maxValue[i] = (int *)malloc(n * sizeof(int )); 

	for(int iter=0; iter<n; iter++){

		for(int i=0, j=iter ; j<n; i++, j++){

			if(i==j)
				maxValue[i][j]=v[i];
			else if(i+1==j)
				maxValue[i][j]=max(v[i], v[j]);
			int a, b, c;
			if(i+2 <= j)
				a=maxValue[i+2][j];
			else a=0;

			if(i+1 <= j-1)
				b = maxValue[i+1][j-1];
			else b=0;

			if(i <= j-2)
				c=maxValue[i][j-2];
			else c=0;

			maxValue[i][j]=max( v[i]+ min(a, b), v[j]+ min(b, c) );
		}
	}

	return maxValue[0][n-1];
}


int main(){
	int n, k, j=0;
	cin >> n >> k;
	int  a[n];
	int  *s = (int *)malloc((n/k)*sizeof(int ));
	int  fullSum=0;

	for(int i=0; i<n/k; i++)
		s[i]=0;

	for(int i=0; i<n; i++){
		cin >> a[i];
		//cout << a[i] << endl;
		fullSum += a[i];
		//printf("full = %lld\n", fullSum);
		if(i/k!=j){
			j++;
		}
		s[j]+=a[i];
	//	printf("j = %d   s = %lld\n", j, s[j]);
	}
	//printf("j = %d   s = %lld\n", j, s[j]);
	int  count1, count2;

	count1 = chooseErrands(s, n/k);
	count2 = fullSum-count1;

	if(count1>count2)
		cout << "Bogay" << endl;
	else if(count1 < count2)
		cout << "aserf18766" << endl;
	else
		cout << "TIE" << endl;

	cout << count1 << " " << count2;

	return 0;
}