#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;

struct argus{
	
	int qID;
	int time;
	int period;
	
	bool operator <(const argus &lhs) const{
		if(time == lhs.time){
			return lhs.qID < qID;
		}
		return lhs.time < time;
	}
};

int main(){
	
	priority_queue<argus> pq;
	string str;
	argus ar;
	
	while(cin >> str && str != "#"){
		cin >> ar.qID;
		cin >> ar.period;
		ar.time = ar.period;
		pq.push(ar);
	}
	int K, i;
	cin >> K;
	
	for(i=0; i<K; i++){
		
		ar = pq.top();
		pq.pop();
		cout << ar.qID << endl;
		ar.time += ar.period;
		pq.push(ar);
	}
	
	return 0;	
}
