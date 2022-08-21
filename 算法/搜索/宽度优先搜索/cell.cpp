#include<iostream>
using namespace std;
const int dx[4]={-1,0,1,0}, //������:���£��ң���
          dy[4]={0,1,0,-1}; //������:���£��ң���
string s;
int a[50][80]={0};//�洢ÿ��λ�õ�ϸ����� 
int m,n,i,j,num;
int h[4000][2]={0};//���У��洢ϸ����λ�� 
void bfs(int p, int q){
	int i, x,y, front,rear ,x0,y0;
	num++;
	a[p][q]=0;
	front=1; rear=2;
	h[1][0]=p; h[1][1]=q;
	while(front<rear){
		x0=h[front][0]; y0=h[front++][1];
		for(i=0; i<4; i++){
			x=x0+dx[i]; y=y0+dy[i];
			if(x>=0 && x<m && y>=0 && y<n && a[x][y]==1){
				h[rear][0]=x; h[rear++][1]=y; a[x][y]=0;
			}
		}
	}
	return;
}
int main(){
	num=0;
	cin>>m>>n;
	for(i=0;i<m;i++){//������� 
		cin>>s;
		for(j=0;j<n;j++)
		   if(s[j]=='0') a[i][j]=0;
		else a[i][j]=1;
	}
	for(i=0;i<m;i++)
	   for(j=0;j<n;j++)
	      if(a[i][j]==1) bfs(i,j);//�ھ�����Ѱ��ϸ�� 
	cout<<num<<endl;//���ϸ������ 
	return 0;
}
