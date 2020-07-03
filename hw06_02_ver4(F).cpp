#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000000000
typedef struct Node{
	long vertex;
	long weight;
}node;

/*參考至 : https://reurl.cc/exgvdb && https://reurl.cc/4RO5Wv*/
void dijkstraPQ(list<node> road[], long n, long start, long *dist){

	priority_queue< pair<long, long>, vector<pair<long, long> >, greater<pair<long, long> > > pqueue;
	

	dist[start]=0;
	pqueue.push(make_pair(0, start));

	while(!pqueue.empty()){

		long from=pqueue.top().second;
		pqueue.pop();

		//printf("from = %d\n\n\n", from);
		list<node>::iterator i=road[from].begin();

		for(i; i!=road[from].end(); i++){
			long to=(*i).vertex;
			long w=(*i).weight;
			//printf("to = %d   w = %d\n", to, w);

			if(dist[from] + w < dist[to]){
				dist[to] = dist[from] + w;
				pqueue.push(make_pair(dist[to], to));
			}
			//printf("dist %d = %d   dist %d = %d\n", to, dist[to], from, dist[from]);
		}
	}


	return ;
}

int main(){

	long n, m, home, s1, s2, cus;
	cin >> n >> m;
	cin >> home >> s1 >> s2 >> cus;
	

	list<node> road[n+1];
	long u, v, w;	

	for(int i=0; i<m; i++){	
		cin >> u >> v >> w;
		road[u].push_back(node{v, w});
		road[v].push_back(node{u, w});
	}

	long *dist=(long *)malloc((n+1)*sizeof(long));

	for(int i=1; i<=n; i++)
		dist[i]=MAX;
	dijkstraPQ(road, n, home, dist);

	long long ans=0;
	/*for(int i=1 ; i<=n ;i++){
		printf("dist %d = %d\n", i, dist[i]);
	}
	printf("\n===\n\n");*/
	ans += dist[s1]+dist[cus];

	for(int i=1; i<=n; i++)
		dist[i]=MAX;
	dijkstraPQ(road, n, s1, dist);

	ans += dist[s2];

	for(int i=1; i<=n; i++)
		dist[i]=MAX;
	dijkstraPQ(road, n, s2, dist);

	ans += dist[cus];

	cout << ans;
	return 0;
}