/*2019.09.04 finished*/
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

vector<int> next2[6005];
int pre[6005];
int visit[6005];
int DP[6005][2];

void tree(int cur){
	
	int i;
	visit[cur] = 1;
	
	for(i=0; i < next2[cur].size(); i++){
		
		//check if the cur's next node has already visited
		if(visit[ next2[cur][i] ])
			continue;
		
		tree(next2[cur][i]);

		DP[cur][0] += max( DP[ next2[cur][i] ][0], DP[ next2[cur][i] ][1] );
		DP[cur][1] += DP[ next2[cur][i] ][0];
	}
	
}

int main(){
	
	int emNum, i;
	
	while(cin >> emNum){
	
		//init
		memset(visit, 0, sizeof(visit));
		memset(DP, 0, sizeof(DP));
		
		//save conviviality ( 氣氛值 )
		for(i=1; i<=emNum; i++){
			next2[i].clear(); //remember to initialize
			cin >> DP[i][1];
		}
		
		//init
		memset(pre, 0, sizeof(pre));
		
		int L, K, lead=1;
		
		//save supervisor-employee relationship ( 上下屬關係 )
		while(cin >> L >> K &&  ( L != 0 && K != 0 ) ){
			next2[K].push_back(L); // = K->L
			pre[L] = K; //= K->L , the previous node of L is K
		}
		
		//find the root ( 找根點 )
		while(pre[lead] != 0)
			lead = pre[lead];
			
		tree(lead);
		
		//find which result is maximum
		cout << max(DP[lead][0], DP[lead][1]) << endl;
	}
	return 0;
} 
