#include <bits/stdc++.h>
using namespace std;

typedef struct position{
	int X;
	int Y;
	int count;
}P;

void floodFill(char **land, int x, int y, int n, int m, int k){

	queue<P> lava;
	if(x+1 < n)
		lava.push(P{x+1, y, 1});
	if(x-1 >= 0)
		lava.push(P{x-1, y, 1});
	if(y+1 < m)
		lava.push(P{x, y+1, 1});
	if(y-1 >= 0)
		lava.push(P{x, y-1, 1});
	int c=0;
	while(!lava.empty()){
		P tmp = lava.front();
		lava.pop();
		//printf("c = %d\n\n", tmp.count);
		

		int nowX=tmp.X, nowY=tmp.Y;
	//	printf("x = %d   y = %d  c= %d\n", nowX, nowY, c);
		if(land[nowX][nowY] == 'C')
			land[nowX][nowY] = 'X';
		else if(land[nowX][nowY] == 'X' || land[nowX][nowY] == 'O')
			continue;

		c=tmp.count;
		c++;
		if(c > k)
			continue;

		if(nowX+1 < n)
			lava.push(P{nowX+1, nowY, c});
		if(nowX-1 >= 0)
			lava.push(P{nowX-1, nowY, c});
		if(nowY+1 < m)
			lava.push(P{nowX, nowY+1, c});
		if(nowY-1 >= 0)
			lava.push(P{nowX, nowY-1, c});
	}
}

int main(){

	int n, m, k;
	cin >> n >> m >> k;

	char **land=(char **)malloc(n*sizeof(char *));
	for(int i=0; i<n; i++)
		land[i]=(char *)malloc(m*sizeof(char));

	char tmp;
	int x, y;
	for(int i=0; i<n;i++){
		for(int j=0; j<m; j++){
			cin >> tmp;
			if(tmp == 'L'){
				x=i;
				y=j;
			}
			land[i][j]=tmp;
			//printf("%c", land[i][j]);
		}
		//printf("\n");
	}
	floodFill(land, x, y, n, m, k);
	for(int i=0; i<n;i++){
		for(int j=0; j<m; j++){
			printf("%c", land[i][j]);
		}
		printf("\n");
	}
	return 0;
}