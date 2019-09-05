#include <map> 
#include <string>
#include <iostream>
using namespace std;

int main(){
	
	int total;
	map<string, int> m;
	
	cin >> total;
	
	while( total ){
		
		string ct, name;
		
		cin >> ct; 
		
		getline(cin, name);
		
		m[ct]++;
		
		total--;
	}
	for(map<string, int>::iterator it=m.begin(); it!=m.end(); it++)
		cout << it->first.c_str() <<" " << it->second << endl;
	
	return 0;
}
