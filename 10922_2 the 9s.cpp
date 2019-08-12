#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;


int main(){
	
	char num[1000]={0};
	
	while( cin >> num ){
		
		int sum=0, i;
		
		if( strlen(num) == 1 && num[0] == '0' )
			break;
		
		for(i=0; i < strlen(num); i++)
			sum += (num[i]-'0');
		if(sum % 9 != 0)
			cout << num <<" is not a multiple of 9.\n";
		else{
			int count = 1;
			
			while(sum > 9){
				
				int s=0;
				
				while(sum != 0){
					s += sum%10;
					sum = sum/10;
				}
				sum = s;
				count++;
			}
			
			cout << num <<" is a multiple of 9 and has 9-degree " << count <<".\n";
		}
		
	}
	
	return 0;
}
