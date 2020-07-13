/*2020.06.27 finished*/
// Result : all right
#include <bits/stdc++.h>
using namespace std;

/*參考至 : https://reurl.cc/ZO37el */
bool bfs(long **graph, int n, int start, int end, int pre[]){

	bool visited[n+2];
	for(int i=0; i<=n+1; i++){
		visited[i]=false;
		pre[i]=-1;
	}

	queue<int> g;
	g.push(start);
	visited[start]=true;
	pre[start]=0;

	while(!g.empty()){

		int vertex=g.front();
		g.pop();

		for(int i=0; i<=n+1; i++){
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


	int pre[n+2];

	bool stillHasPath=bfs(graph, n, s, t, pre);
	while(stillHasPath){
		long singleFlow=1000000000;

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

	int n, m;
	cin >> n >> m;

	long **graph=(long **)malloc((n+2)*sizeof(long *));
	for(int i=0; i<=n+1; i++)
		graph[i]=(long *)malloc((n+2)*sizeof(long));

	for(int i=0; i<=n+1; i++)
		for(int j=0; j<=n+1; j++)
			graph[i][j]=0;


	int u, t;
	for(int i=0; i<n; i++){
		cin >> u;
		graph[0][i+1]=u;
		graph[i+1][0]=u;
	}
	for(int i=0; i<n; i++){
		cin >> t;
		graph[n+1][i+1]=t;
		graph[i+1][n+1]=t;
	}
	
	
	int a, b, c;
	for(int i=0; i<m; i++){
		cin >> a >> b >> c;
		graph[a][b]=c;
		graph[b][a]=c;
	}

	long ans=fordFulkerson(graph, n, 0, n+1);

	cout << ans;


	return 0;
}
