#include<iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

char ch[MAXN], All[MAXN];
int SA[MAXN], rk[MAXN], Height[MAXN], sum[MAXN], trk[MAXN], a[MAXN], n, m; 
char str[MAXN];
//rk[i] 第i个后缀的排名; SA[i] 排名为i的后缀位置; Height[i] 排名为i的后缀与排名为(i-1)的后缀的LCP
//sum[i] 计数排序辅助数组; trk[i] rk的辅助数组(计数排序中的第二关键字),与SA意义一样。
//a为原串
void RSort() { 
    //rk第一关键字,trk第二关键字。
    cout<<"trk[i]:";
	for(int j=1;j<=n;j++)
    	cout<<j<<","<<trk[j]<<";";
    cout<<endl;
    cout<<"rk[i]:";
	for(int j=1;j<=n;j++)
    	cout<<j<<","<<rk[j]<<";";
    cout<<endl;
    for (int i = 0; i <= m; i ++) sum[i] = 0;
    for (int i = 1; i <= n; i ++) sum[rk[trk[i]]] ++;
    cout<<"sum[i]:";
	for(int j=1;j<=m;j++)
	    if(sum[j]!=0 && j<99)
        	cout<<j<<","<<sum[j]<<";";
    cout<<endl;
    for (int i = 1; i <= m; i ++) sum[i] += sum[i-1];
    cout<<"sum[i]:";
	for(int j=1;j<=m;j++)
	    if(sum[j]!=0 && j<99)
        	cout<<j<<","<<sum[j]<<";";
    cout<<endl;
    for (int i = n; i >= 1; i --) SA[sum[rk[trk[i]]] --] = trk[i]; //确保满足第一关键字的同时，再满足第二关键字的要求
    cout<<"SA[i]:";
	for(int j=1;j<=n;j++)
    	cout<<j<<","<<SA[j]<<";";
    cout<<endl;
} //计数排序,把新的二元组排序。

int cmp(int *f, int x, int y, int w) { return f[x] == f[y] && f[x + w] == f[y + w]; } 
//通过二元组两个下标的比较，确定两个子串是否相同

void Suffix() {
    //SA
    for (int i = 1; i <= n; i ++) rk[i] = a[i], trk[i] = i;
    
    cout<<"trk[i]:";
	for(int j=1;j<=n;j++)
    	cout<<j<<","<<trk[j]<<";";
    cout<<endl;
    cout<<"rk[i]:";
	for(int j=1;j<=n;j++)
    	cout<<j<<","<<rk[j]<<";";
    cout<<endl;    	
    cout<<endl;
    
    m = 127 ,RSort(); //一开始是以单个字符为单位，所以(m = 127)

    for (int w = 1, p = 1, i; p < n; w += w, m = p) { //把子串长度翻倍,更新rk
cout<<endl<<"w="<<w<<" p="<<p<<" m="<<m<<endl;
        //w 当前一个子串的长度; m 当前离散后的排名种类数
        //当前的trk(第二关键字)可直接由上一次的SA的得到
        for (p = 0, i = n - w + 1; i <= n; i ++) trk[++ p] = i; //长度越界,第二关键字为0
        for (i = 1; i <= n; i ++) if (SA[i] > w) trk[++ p] = SA[i] - w;
        //更新SA值,并用trk暂时存下上一轮的rk(用于cmp比较)
        RSort(), swap(rk, trk), rk[SA[1]] = p = 1;

        //用已经完成的SA来更新与它互逆的rk,并离散rk
        for (i = 2; i <= n; i ++) rk[SA[i]] = cmp(trk, SA[i], SA[i - 1], w) ? p : ++ p;
    cout<<"trk[i]:";
	for(int j=1;j<=n;j++)
    	cout<<j<<","<<trk[j]<<";";
    cout<<endl;
    cout<<"rk[i]:";
	for(int j=1;j<=n;j++)
    	cout<<j<<","<<rk[j]<<";";
    cout<<endl;
/*    cout<<endl;
    cout<<endl;*/
    }
    //离散：把相等的字符串的rk设为相同。
    //LCP
    int j, k = 0;
    for(int i = 1; i <= n; Height[rk[i ++]] = k) 
        for( k = k ? k - 1 : k, j = SA[rk[i] - 1]; a[i + k] == a[j + k]; ++ k);
    //这个知道原理后就比较好理解程序
}

void Init() {
    scanf("%s", str);
    n = strlen(str);
    for (int i = 0; i < n; i ++) a[i + 1] = str[i];
}

int main() {
	freopen("rusult.txt","w",stdout); 
    Init();
    Suffix();

    int ans = Height[2];
    for (int i = 3; i <= n; i ++) ans += max(Height[i] - Height[i - 1], 0);
    printf("\n\n%d\n", ans);    
}


