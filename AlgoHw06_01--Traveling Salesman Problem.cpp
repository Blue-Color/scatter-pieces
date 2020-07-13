/*2020.06.04 finished*/
/*FINAL.VER*/
// Result : all right
#include <bits/stdc++.h>
using namespace std;

/*參考至 : https://reurl.cc/4RGMKV & https://reurl.cc/WdVo65*/
void FloydWarshall(long **graph, int n){
	
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(graph[i][k]+graph[k][j] < graph[i][j])
					graph[i][j]=graph[i][k]+graph[k][j];
			}
		}
	}

	return ;
}

int main(){

	int n, m;
	cin >> n >> m;

	long **graph=(long **)malloc((n+1)*sizeof(long *));
	for(int i=0; i<=n; i++)
		graph[i] = (long *)malloc((n+1)*sizeof(long));


	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			graph[i][j]=500000;

	for(int i=0; i<m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		graph[u][v]=w;
	}

	FloydWarshall(graph, n);
	
	long min=500000;

	for(int i=1; i<=n; i++){
		if(graph[i][i]<min)
			min=graph[i][i];
	}
	if(min == 500000)
		cout <<"-1";
	else
		cout << min;
	return 0;
}
