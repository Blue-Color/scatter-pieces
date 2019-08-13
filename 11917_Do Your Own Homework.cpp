#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

typedef struct subGoodAt{
	char sub[100][20];
	int needTime[100];
}SGA;

int main(){
	
	int total, num, i, day, count=0;
	char needSub[20]={0};
	
	SGA sga = {0};
	
	cin >> total;
	
	while( total ){
		
		bool good_at = false;
		
		cin >> num;
		for(i=0; i < num; i++){
			cin >> sga.sub[i] >> sga.needTime[i];
			//printf("sub = %s  time = %d\n", sga.sub[i], sga.needTime[i]);
		}
		cin >> day >> needSub;
		
		
		for(i=0; i<num; i++){
			if( !strcmp(needSub, sga.sub[i]) ){
				
				good_at = true;
				if(sga.needTime[i] <= day){
					cout << "Case " << ++count <<": Yesss"<< endl;
				}else if( sga.needTime[i] <= day+5){
					cout << "Case " << ++count <<": Late"<< endl;
				}else
					good_at = false;
					
				break;
			}
		}
		if(!good_at)
			cout << "Case " << ++count <<": Do your own homework!"<< endl;
		
		total--;
	}
	
	return 0;
}
