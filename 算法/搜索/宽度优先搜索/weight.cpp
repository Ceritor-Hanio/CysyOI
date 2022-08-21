#include<iostream>
using namespace std;
const int maxn=105,maxm=1005;
int n,m，w[maxn]，dist[maxm];
int queue[maxm];//队列
void init(){
	int i;
	cin>>n>>m;
	for(i=1; i<=n; i++) cin>>w[i];
	return ;
}
void solve(){
	int front, rear, k, i;
	for(i=0; i<=maxm; i++)  dist[i]=-1;//所有状态不出现过
	front=1; rear=2; dist[0]=0; queue[1]=0;//初始队列
	do{
		k=queue[front++];//出队
		for(i=1; i<=n; i++)
                   //重量不超过m且这种重量没用过,入队
		   if(k+w[i]<=m && dist[k+w[i]]==-1){
		   	dist[k+w[i]]=dist[k]+1;
		   	queue[rear++]=k+w[i];
		   }
	}while(front<rear);//队列不空
	if(dist[m]==-1) cout<<"Impossible"<<endl;//不可能
	   else cout<<dist[m];
}
int main(){
	init();
	solve();
	return 0;
}
	
