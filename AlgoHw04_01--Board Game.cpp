/*2020.05.12 finished*/
/*FINAL.VER*/
// Result : all right
#include <bits/stdc++.h>
using namespace std;

/*source from data structure ppt (chapter 6 part 1) */
void dfs(vector<int> vil[], int v, bool visited[]){
	visited[v]=true;
	cout << v << " ";
	for(int i=0; i<vil[v].size(); i++){
		if(!visited[ vil[v][i] ])
			dfs(vil, vil[v][i], visited);
	}
	return ;
}
void graph(vector<int> village[], int u, int v){
	village[u].push_back(v);
	village[v].push_back(u);
	return ;
}

int main(){

	int n, u, v;
	cin >> n;


	vector<int> village[n+1];
	bool *visited=(bool *)malloc((n+1)*sizeof(bool));

	/*source for below : https://reurl.cc/exMEob*/
	for(int i=0; i<n-1; i++){
		cin >> u >> v;
		graph(village, u, v);
		visited[i+1]=false;
	}
	visited[n]=false;
	/*source for below : https://reurl.cc/b5WXoy*/
	for(int i=1; i<=n; i++){
		sort(village[i].begin(), village[i].end(), greater<int>());
	}

	dfs(village, n, visited);

	/*
	for(int i=1; i<=n; i++){
		printf("\ni=%d\n", i);
		for(int j=0; j<village[i].size(); j++)
			cout << village[i][j] << endl;
		printf("\n\n====\n\n");
	}
*/
	//free(route);
	free(visited);
	//free(priority);
	return 0;
}
