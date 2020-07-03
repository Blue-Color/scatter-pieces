#include <bits/stdc++.h>
using namespace std;

/*參考至 : https://reurl.cc/ZO37el */
bool bfs(long **graph, int n, int start, int end, int pre[]){

	bool visited[n+1];
	for(int i=1; i<=n; i++){
		visited[i]=false;
		pre[i]=0;
	}

	queue<int> g;
	g.push(start);
	visited[start]=true;
	pre[start]=-1;

	while(!g.empty()){

		int vertex=g.front();
		g.pop();

		for(int i=1; i<=n; i++){
			if(!visited[i] && graph[vertex][i]>0){
				g.push(i);
				pre[i]=vertex;
				visited[i]=true;
			}
		}
	}
	if(visited[end])
		return true;
	else 
		return false;
}
long fordFulkerson(long **graph, int n, int s, int t){

	long maxFlow=0;


	int pre[n+1];

	bool stillHasPath=bfs(graph, n, s, t, pre);
	while(stillHasPath){
		long singleFlow=1000000;

		for(int i=t; i!=s; i=pre[i]){
			singleFlow=min(singleFlow, graph[pre[i]][i]);
		}

		for(int i=t; i!=s; i=pre[i]){
			graph[pre[i]][i] -= singleFlow;
			graph[i][pre[i]] += singleFlow;
		}

		maxFlow += singleFlow;

		stillHasPath=bfs(graph, n, s, t, pre);
	}

	return maxFlow;
}


int main(){

	int n, m, s, t;
	cin >> n >> m >> s >> t;

	int u, v, w;
	long **graph=(long **)malloc((n+1)*sizeof(long *));
	for(int i=1; i<=n; i++)
		graph[i]=(long *)malloc((n+1)*sizeof(long));



	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			graph[i][j]=0;


	for(int i=0; i<m; i++){
		cin >> u >> v >> w;
		graph[u][v]+=w;
		graph[v][u]+=w;
	}
	long ans=fordFulkerson(graph, n, s, t);

	cout << ans;
	return 0;
}