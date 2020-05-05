/*2020.05.03 finished*/
/*FINAL VER.*/
//Result :all right
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long long Csum(int n){

	long long ans=1;
	for(int i=0; i<n; i++)
		ans = (ans << 1) % MOD;
	return ans;
}

long long LHS(int a[], int n, int m, long long sum[]){


	long long *dp=(long long*)malloc((n+1)*sizeof(long long));
	long long count=0;

	for(int i=0; i<n; i++)
		dp[i]=0;

	for(int i=1; i<n; i++){
		for(int j=i-1; j>=0; j--){
			//printf("\n\na[%d] = %d    a[%d] = %d\n", i, a[i], j, a[j]);
			if(abs(a[i]-a[j])<=m){
				dp[i] = (dp[i] + sum[j] ) % MOD;
				//printf("<= m   dp[%d] = %d    dp[%d] = %d  \n", i, dp[i], j, dp[j]);
			}else{
				dp[i] = (dp[i] + dp[j] ) % MOD;
				//printf("> m   dp[%d] = %d    dp[%d] = %d  \n", i, dp[i], j, dp[j]);
			}
		}
		count = (count + dp[i]) % MOD;
	}
	
	
	return count ;
}

int main(){

	int n, m;
	cin >> n >> m;

	int *a=(int *)malloc(n*sizeof(int)); 

	for(int i=0; i<n; i++){
		cin >> a[i];
	}

	long long *sum = (long long  *)malloc(n*sizeof(long long )); 
	sum[0]=1;
	for(int i=1; i<n; i++){
		sum[i] = (sum[i-1] << 1) % MOD;
		//printf("%d\n", sum[i]);
	}
	long long ans;
	ans=LHS(a, n, m, sum);
	cout << ans;


	return 0;
}



/*VER. 1*/
//Result : some right, most wrong
/* 
start from i=n-2, j=i+1
check if abs(a[i]-a[j])<=m, there will be [ a[i] a[j] + (n-j) numbers ] 
	=> just consider 1 number + a[i] a[j], will have n nums(Cn0 + Cn1 + ... + Cnn) + a[i] a[j] 
else +dp[j] for [ a[i] + dp[j] numbers ] 
*/
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long LHS(long a[], int n, int m){

	long *dp=(long *)malloc(n*sizeof(long));

	for(int i=0; i<n ; i++)
		dp[i]=0;

	for(int i=n-2; i>=0; i--){
		for(int j=i+1; j<n; j++){
			bool exist=false;
			if( abs(a[i]-a[j])<=m){
				dp[i]+=n-j;
				exist=true;
			}
			if(dp[j]>0 && !exist)
				dp[i]+=dp[j];
		}
		dp[i]+=dp[i+1];
	}
	return dp[0];
}

int main(){

	int n, m;
	cin >> n >> m;

	long *a=(long *)malloc(n*sizeof(long)), count=0; 

	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	long ans;
	ans=LHS(a, n, m);
	cout << ans;
	return 0;
}



/*VER. 2*/
//Result : some right, most wrong

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long LHS(long a[], int n, int m){

	long *dp=(long *)malloc(n*sizeof(long));
	long *noUse=(long *)malloc(n*sizeof(long));

	for(int i=0; i<n ; i++){
		dp[i]=0;
		noUse[i]=0;
	}

	for(int i=n-2; i>=0; i--){

		dp[i]=(dp[i] % MOD + dp[i+1] % MOD) % MOD;
		for(int j=i+1; j<n; j++){
			
			//printf("a dp i = %d   %d  %d  a dp j = %d   %d  %d\n", a[i], dp[i], i, a[j], dp[j], j);
			if( abs(a[i]-a[j])<=m){
				dp[i] = ( dp[i] % MOD + (1+noUse[j]) % MOD ) % MOD;
				//printf("a dp i = %d   %d  %d  noUse = %d \n", a[i], dp[i], i, noUse[j]);
			}else{
				noUse[i]+= 1;
				//printf("\na noUse = %d   %d \n",  a[i], noUse[i]);
			}
		}
		dp[i]= (dp[i] % MOD + dp[i+1] % MOD) % MOD;
		//printf("\na dp i = %d   %d  %d \n\n=====\n\n", a[i], dp[i], i);
	}

	
	return dp[0];
}

int main(){

	int n, m;
	cin >> n >> m;

	long *a=(long *)malloc(n*sizeof(long)); 

	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	long ans;
	ans=LHS(a, n, m);
	cout << ans;
	return 0;
}
