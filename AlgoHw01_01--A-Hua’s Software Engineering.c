/*2020.03.24 finished*/
/*FINAL VER.*/
//Result : all right
#include <stdio.h>
#include <stdint.h>

uint32_t a1, a2, x, y, n;

void matrixMulti(uint64_t m[2][2], uint64_t m2[2][2]);
uint64_t power(uint64_t m[2][2], uint32_t);

int main(){

    uint64_t m[2][2];
    uint64_t ans;
    scanf("%d%d%d%d%d", &a1, &a2, &x, &y, &n);

    if(n==3){
        ans = (x*a2 + y*a1)%1000000007;
        printf("\n%d %d %d %d %d\n", a1, a2, x, y,n);
        printf("%ld", ans);
        return 0;
    }
    m[0][0]=x;
    m[0][1]=y;
    m[1][0]=1;
    m[1][1]=0;

     //n starts from 3
    power(m, n-2);

    ans = ( (m[0][0]*a2)%1000000007 + (m[0][1]*a1)%1000000007 )%1000000007;
    printf("%ld", ans);

    return 0;
    
}

void matrixMulti(uint64_t m[2][2], uint64_t m2[2][2]){
    uint64_t newX = ( (m[0][0]%1000000007*m2[0][0]%1000000007)%1000000007 + (m[0][1]%1000000007*m2[1][0]%1000000007)%1000000007 )%1000000007;
    uint64_t newY = ( (m[0][0]%1000000007*m2[0][1]%1000000007)%1000000007 + (m[0][1]%1000000007*m2[1][1]%1000000007)%1000000007 )%1000000007;
    uint64_t new1 = ( (m[1][0]%1000000007*m2[0][0]%1000000007)%1000000007 + (m[1][1]%1000000007*m2[1][0]%1000000007)%1000000007 )%1000000007;
    uint64_t new0 = ( (m[1][0]%1000000007*m2[0][1]%1000000007)%1000000007 + (m[1][1]%1000000007*m2[1][1]%1000000007)%1000000007 )%1000000007;

    m[0][0] = newX;
    m[0][1] = newY;
    m[1][0] = new1;
    m[1][1] = new0;

}
uint64_t power(uint64_t m[2][2], uint32_t n){

    uint64_t ori[2][2]={ {x, y}, {1, 0} };
    
    if(n == 1)
        return m[0][0];

    power(m, n/2);
    matrixMulti(m, m);

    if(n%2)
        matrixMulti(m, ori);
    

    return m[0][0];
}




/*MY ORIGINAL VER.*/
//Result : small number tests (3 <= n <= 10^6) all right, big number tests (3 <= n <= 2^31-1) time excceeded
#include <stdio.h>
#include <stdint.h>

uint32_t a1, a2, x, y, n;

int main(){

	uint64_t m[2][2];
	uint64_t newY, newX, newM1, newM2, ans;
	scanf("%d%d%d%d%d", &a1, &a2, &x, &y, &n);

	if(n==3){
		ans = (x*a2 + y*a1)%1000000007;
		printf("\n%d %d %d %d %d\n", a1, a2, x, y,n);
		printf("%ld", ans);
		return 0;
	}
	m[0][0]=x;
	m[0][1]=y;
	m[1][0]=1;
	m[1][1]=0;
    
	 //n starts from 3
	for(int i=0; i<n-3; i++){
		newX = ( (m[0][0]%1000000007*x%1000000007)%1000000007 + (m[0][1]%1000000007*1)%1000000007 )%1000000007;
		newY = (m[0][0]%1000000007*y%1000000007)%1000000007;
		newM1 = ( (m[1][0]%1000000007*x%1000000007)%1000000007 + (m[1][1]%1000000007*1)%1000000007 )%1000000007;
		newM2 = (m[1][0]%1000000007*y%1000000007)%1000000007;

		m[0][0] = newX;
		m[0][1] = newY;
		m[1][0] = newM1;
		m[1][1] = newM2;
		//printf("\nm = %d   %d   %d   %d\n\n", m[0][0], m[0][1], m[1][0], m[1][1]);
	}
	ans = ( (m[0][0]*a2)%1000000007 + (m[0][1]*a1)%1000000007 )%1000000007;
	printf("%ld", ans);

	return 0;
}



/*TA's code*/

/*
#include <iostream>
#define IOS() ios_base::sync_with_stdio(0); cin.tie(0)
#define MOD 1000000007
using namespace std;
typedef long long ll;

//二維矩陣
struct matrix{
    ll m[2][2];
};

//矩陣乘法
inline matrix mul(const matrix &a, const matrix &b, ll mod){
    matrix c;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            c.m[i][j] = 0;
            for (int k = 0; k < 2; k++)
                c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j] % mod) % mod;
        }
    }
    return c;
}

//矩陣快速冪 for a^n
inline matrix matrixexp(const matrix &a, ll n, ll mod){
    matrix ans = {
        1, 0,
        0, 1};
    matrix base = a;
    while (n > 0){
        if (n & 1)
            ans = mul(ans, base, mod);
        base = mul(base, base, mod);
        n >>= 1; //n = n /2
    }
    return ans;
}

int main(){
    IOS();
    ll a1, a2, x, y, n;
    cin >> a1 >> a2 >> x >> y >> n;

    matrix a = {
        x, y,
        1, 0};

    matrix c = matrixexp(a, n - 2, MOD);
    cout << (c.m[0][0] * a2 % MOD + c.m[0][1] * a1 % MOD) % MOD << endl;
    return 0;
}
*/
