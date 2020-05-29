#include <bits/stdc++.h>
using namespace std;

/*參考至 : https://reurl.cc/QdN9rp*/
void checkPre(vector<int> list[], int vertex, int pre[], bool visited[]){

	visited[vertex]=true;

	for(int i=0; i<list[vertex].size(); i++){

		int v = list[vertex][i];
		//printf("\nv = %d\n", v);
		if(!visited[v]){
			pre[v]=vertex;
			//printf("\n=====\npre = %d\n\n", pre[v]);
			checkPre(list, v, pre, visited);
		}
	}
}

void dfs(vector<int> list[], int start, int n, int pre[], bool visited[]){
	

	int verIndex=start;
	for(int i=1; i<=n; i++){
		//printf("index = %d\n", verIndex);
		if(!visited[verIndex]){
			checkPre(list, verIndex, pre, visited);
		}
		verIndex=i;
	}
}

int main(){

	int n;
	cin >> n;

	int u, v, w;
	int **graph=(int **)malloc((n+1)*sizeof(int *));
	for(int i=0; i<=n; i++)
		graph[i] = (int *)malloc((n+1)*sizeof(int));

	vector<int> list[n+1];

	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			graph[i][j]=0;


	for(int i=0; i<n-1; i++){
		cin >> u >> v >> w;
		graph[u][v]=w;
		graph[v][u]=w;
		list[u].push_back(v);
		list[v].push_back(u);
		//printf("u = %d   v = %d   %d\n", u, v, graph[u][v]);
	}
	int s, t;
	cin >> s >> t;
	//printf("s = %d   t = %d  \n", s, t);

	bool *visited=(bool *)malloc((n+1)*sizeof(bool));
	int *pre=(int *)malloc((n+1)*sizeof(int));

	for(int i=1; i<=n; i++){
		visited[i]=false;
		pre[i]=0;
	}


	dfs(list, s, n, pre, visited);

	int min=graph[t][pre[t]], fv = pre[t];

	for(int i=1; pre[fv]!=0; i++){
		//printf("1   fv = %d   pre = %d\n", fv, pre[fv]);
		if(graph[fv][pre[fv]] < min){
			min = graph[fv][pre[fv]];
		}
		fv=pre[fv];
		//printf("2   fv = %d   pre = %d\n", fv, pre[fv]);
	}
	cout << min;
	return 0;
}