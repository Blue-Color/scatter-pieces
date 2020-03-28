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

    //printf("\nm = %d   %d   %d   %d\n\n", m[0][0], m[0][1], m[1][0], m[1][1]);
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