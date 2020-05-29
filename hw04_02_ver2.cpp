#include <bits/stdc++.h>
using namespace std;

typedef struct Group{
	long come;
	long leave;
}G;
bool compareForC(G c, G l){
	return (c.come < l.come);
}
bool compareForL(G c, G l){
	return (c.leave < l.leave);
}

long long minTimeFirework(G *group, int n){

	long end=group[0].leave, start = group[0].come;
	long long count=2;
	bool onePoint=false;

	if(n==1)
		return count;

	for(int i=1; i<n; i++){
		printf("i = %d  come = %d   leave = %d    end = %d\n", i, group[i].come, group[i].leave, end);
		printf("count1 = %d\n", count);
	
		printf("count2 = %d\n\n", count);
	}
	if(onePoint){
		count += 1;
	}
	printf("count3 = %d\n\n", count);
	return count;
}

int main(){

	//ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);

	int n;
	cin >> n;

	long l, r;
	G *group=(G *)malloc(n*sizeof(G)); 

	for(int i=0; i<n; i++){
		cin >> l >> r;
		group[i].come=l;
		group[i].leave=r;
	}
	sort(group, group+n, compareForC);
	sort(group, group+n, compareForL);
	long long ans = minTimeFirework(group, n);

	cout << ans ;

	return 0;
}