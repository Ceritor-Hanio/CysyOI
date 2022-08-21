#include<iostream>  
#include<cstdio>  
#include<algorithm>  
using namespace std;  
const int maxn=2e5+5;  
int n, m, a[maxn];  
int dp[maxn][20];  
  
void ST() {  
    for(int i=1; i<=n; i++)//初始状态 
        dp[i][0]=a[i];  
    for(int j=1; (1<<j)<=n; j++) {//枚举区间长度2^j 
        for(int i=1; (i+(1<<j)-1)<=n; i++)//枚举起点 
            dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);  
    }  
}  
int RMQ(int l, int r) {  
    int k=0;  
    while((1<<(k+1))<=r-l+1) k++;//求出最大的k,满足2^k≤Ri-Li+1 
    return max(dp[l][k],dp[r-(1<<k)+1][k]);//有重叠部分 
}  
int main() {  
    scanf("%d", &n);  
    for(int i=1; i<=n; i++)  
        scanf("%d", &a[i]);  
    ST();  
    scanf("%d", &m);  
    while(m--) {  
        int l, r;  
        scanf("%d%d", &l, &r);  
        printf("%d\n", RMQ(l, r));  
    }  
    return 0;  
}  
