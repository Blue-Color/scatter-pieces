#include <cstdio>
#include <iostream>
using namespace std;

int graph[250][250]= {0};
int visited[250]={0};
int biColor=1;

void DFS(int cur, int n){
	
	int dest;
	
//	printf("node = %d\n", n);
	//cout << "cur : " << visited[cur] << " " << cur << endl;
	
	for(dest=0; dest < n; dest++){
		
	//	cout << "dest : " << visited[dest] << " " << dest << endl;
		if( graph[cur][dest] == 1){
			
			if(visited[dest] == 0){
				
				if(visited[cur] == 1){
					visited[dest]=2;
					DFS(dest, n);
				}
				else if (visited[cur] == 2){
					visited[dest]=1;
					DFS(dest, n);
				}
			}
			else{
				if(visited[dest] == visited[cur] ){
					//cout << "\nfalse\n" ;
				//	printf("%d %d   %d %d\n\n", dest, visited[dest], cur, visited[cur]);
					biColor = 0;
					break;
				}
				
			}
			
		}
	}
}

int main(){
	
	int node, line, i, from, to, j;
	
	while(cin >> node && node != 0){
		
		biColor=1;
		
		for(i=0; i < 250; i++){
			for(j=0; j<250; j++)
				graph[i][j]=0;
		}
		for(i=0; i < 250; i++){
			visited[i] = 0;
		}
			
		cin >> line;
	
	//	printf("\nnode = %d  line = %d\n", node, line);
	
		for(i=0; i < line; i++){
		
			cin >> from >> to;
			graph[from][to]=1;
			graph[to][from]=1;
		}
		visited[0]=1;
		DFS(0, node);
	
		if(biColor == 0)
			cout << "NOT BICOLORABLE.\n";
		else
			cout << "BICOLORABLE.\n";
	}
	/*for(i=0; i<line; i++){
		for(j=0; j < line; j++)
			cout << graph[i][j];
		cout << '\n';
	}*/
	return 0;
} 
