#include<iostream>
using namespace std;
const int maxn=105,maxm=1005;
int n,m��w[maxn]��dist[maxm];
int queue[maxm];//����
void init(){
	int i;
	cin>>n>>m;
	for(i=1; i<=n; i++) cin>>w[i];
	return ;
}
void solve(){
	int front, rear, k, i;
	for(i=0; i<=maxm; i++)  dist[i]=-1;//����״̬�����ֹ�
	front=1; rear=2; dist[0]=0; queue[1]=0;//��ʼ����
	do{
		k=queue[front++];//����
		for(i=1; i<=n; i++)
                   //����������m����������û�ù�,���
		   if(k+w[i]<=m && dist[k+w[i]]==-1){
		   	dist[k+w[i]]=dist[k]+1;
		   	queue[rear++]=k+w[i];
		   }
	}while(front<rear);//���в���
	if(dist[m]==-1) cout<<"Impossible"<<endl;//������
	   else cout<<dist[m];
}
int main(){
	init();
	solve();
	return 0;
}
	
