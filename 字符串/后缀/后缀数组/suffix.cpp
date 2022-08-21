#include<iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

char ch[MAXN], All[MAXN];
int SA[MAXN], rk[MAXN], Height[MAXN], sum[MAXN], trk[MAXN], a[MAXN], n, m; 
char str[MAXN];
//rk[i] ��i����׺������; SA[i] ����Ϊi�ĺ�׺λ��; Height[i] ����Ϊi�ĺ�׺������Ϊ(i-1)�ĺ�׺��LCP
//sum[i] ��������������; trk[i] rk�ĸ�������(���������еĵڶ��ؼ���),��SA����һ����
//aΪԭ��
void RSort() { 
    //rk��һ�ؼ���,trk�ڶ��ؼ��֡�
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
    for (int i = n; i >= 1; i --) SA[sum[rk[trk[i]]] --] = trk[i]; //ȷ�������һ�ؼ��ֵ�ͬʱ��������ڶ��ؼ��ֵ�Ҫ��
    cout<<"SA[i]:";
	for(int j=1;j<=n;j++)
    	cout<<j<<","<<SA[j]<<";";
    cout<<endl;
} //��������,���µĶ�Ԫ������

int cmp(int *f, int x, int y, int w) { return f[x] == f[y] && f[x + w] == f[y + w]; } 
//ͨ����Ԫ�������±�ıȽϣ�ȷ�������Ӵ��Ƿ���ͬ

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
    
    m = 127 ,RSort(); //һ��ʼ���Ե����ַ�Ϊ��λ������(m = 127)

    for (int w = 1, p = 1, i; p < n; w += w, m = p) { //���Ӵ����ȷ���,����rk
cout<<endl<<"w="<<w<<" p="<<p<<" m="<<m<<endl;
        //w ��ǰһ���Ӵ��ĳ���; m ��ǰ��ɢ�������������
        //��ǰ��trk(�ڶ��ؼ���)��ֱ������һ�ε�SA�ĵõ�
        for (p = 0, i = n - w + 1; i <= n; i ++) trk[++ p] = i; //����Խ��,�ڶ��ؼ���Ϊ0
        for (i = 1; i <= n; i ++) if (SA[i] > w) trk[++ p] = SA[i] - w;
        //����SAֵ,����trk��ʱ������һ�ֵ�rk(����cmp�Ƚ�)
        RSort(), swap(rk, trk), rk[SA[1]] = p = 1;

        //���Ѿ���ɵ�SA���������������rk,����ɢrk
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
    //��ɢ������ȵ��ַ�����rk��Ϊ��ͬ��
    //LCP
    int j, k = 0;
    for(int i = 1; i <= n; Height[rk[i ++]] = k) 
        for( k = k ? k - 1 : k, j = SA[rk[i] - 1]; a[i + k] == a[j + k]; ++ k);
    //���֪��ԭ���ͱȽϺ�������
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


