/*2019.09.03 finished*/
#include <list>
#include <iostream>
using namespace std;

int main(){
	
	string w;
	int i;
	
	while( getline(cin, w) ){
		
		list<char> text; 
		list<char>::iterator it=text.begin();
	
		for(i=0; i < w.size(); i++){
		
			if(w[i] == '[')
				it=text.begin();
			else if (w[i] == ']')
				it=text.end();
			else
				text.insert(it, w[i]);
		
		}
		for(it=text.begin(); it != text.end(); it++){
			cout << *it;
		}
	}
	
	return 0;
}
