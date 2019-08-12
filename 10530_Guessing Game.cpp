/*2019.08.11 finished*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX(x, y) x>y ? x : y
#define MIN(x, y) x<y ? x : y

int main(){
	
	//num, str "too high" "too low" "right on" -> strcmp
	int num;
	char str[10]={0};
	
	while(scanf("%d", &num) != EOF && num != 0){
		
		//cause the range : 1 - 10
		int max=10, min=1;
		
		while( cin.getline(str, 10) && strcmp(str, "right on") ){
			
			if(strcmp(str, "too high") == 0)
				max = MIN(max, num-1);
			
			else if(strcmp(str, "too low") == 0)
				min = MAX(min, num+1);
			
			scanf("%d", &num);
			
		}
		if(num >= min && num <= max)
			cout << "Stan may be honest\n";
		else
			cout << "Stan is dishonest\n";
	}
	
	return 0;
}
