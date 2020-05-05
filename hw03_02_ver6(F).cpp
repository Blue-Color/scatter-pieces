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