#include<iostream>
using namespace std;
const int maxn=110;
const int dx[8]={-1,-2,-2,-1,1,2,2,1},dy[8]={2,1,-1,-2,-2,-1,1,2};
bool can[maxn][maxn]={0};
int dist[maxn][maxn];
int n,i,j,x0,y0;
void init(){
   string s;
   cin>>n>>x0>>y0;
   for(i=1;i<=n;i++){
      cin>>s;
      for(j=1;j<=n;j++) can[i][j]=(s[j]=='-');
   }   
   return ;
}
void bfs(){
   int q[maxn*maxn][2];
   int front,rear,k,x,y,xx,yy;
   front=0;rear=1; dist[x0][y0]=0; q[0][0]=x0;q[0][1]=y0;
   while(front<rear){
      x=q[front][0]; y=q[front++][1];
      for(k=0;k<8;k++){
         xx=x+dx[k]; yy=y+dy[k];
         if(can[xx][yy] && dist[xx][yy]==-1 && xx>0 && xx<=n && yy>0 && yy<=n){
            dist[xx][yy]=dist[x][y]+1;
            q[++rear][0]=xx; q[rear][1]=yy;
		 }
	  }
   }
   return;
}
void output(){
   for(i=1;i<=n;i++){
      for(j=1;j<=n;j++)
         cout<<dist[i][j]<<' ';
       cout<<endl;
   }
}
int main(){
   init();
   for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
         dist[i][j]=-1;
   output();
   bfs();
} 
