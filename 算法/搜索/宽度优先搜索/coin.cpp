#include<iostream>
using namespace std;
int n, front, rear;
int a[8010][3];//a[i][0]父结点，a[i][1]正面个数，a[i][2]翻了多少个正面朝向
bool b[810]={false};//正面朝上个数是否出现过，判重
bool flag=false;
void out(){//输出
	int i,j,k,L,h;
	int d[5010];
	char st[5010];
	cout<<"step 0:";
	for(i=1;i<=n;i++) cout<<'O';cout<<endl;	
	for(i=1;i<=n;i++) st[i]='O';
	j=0; i=rear-1;
	do{
	   d[++j]=i; i=a[i][0];//a[i,0]为父结点编号
	}while(i>0);
	for(i=j-1; i>0; i--){
		k=a[d[i]][2]; L=5-k;
		for(h=1;h<=n;h++)
		   if(st[h]=='O'){
		      if(k>0){k--; st[h]='*';} }
		      else if(L>0) { L--; st[h]='O';}
		cout<<"step "<<j-i<<':';
		for(h=1;h<=n;h++) cout<<st[h];
		cout<<endl;
	}
	flag=true;
	return;
}
	   
void calc(){
	int r,m;
	b[n]=true;
	front=1; rear=2;
	a[1][0]=0; a[1][1]=n; a[1][2]=0;
	do{
		m=a[front++][1];
		for(r=0;r<6;r++)
		  if(m>=r && n-m>=5-r && !b[m-r+5-r]){
		  	b[m-r+5-r]=true;//翻了r个面朝上，翻了5-r个面朝下
		  	a[rear][0]=front-1;
		  	a[rear][1]=m-r+5-r;
		  	a[rear][2]=r;
		  	if(a[rear++][1]==0) {out(); if(flag) break;}
		  }
	    if(flag) break; 
	}while(front<rear);
	if(!flag) cout<<"No answer"<<endl;
	return ;
}
int main(){
	cout<<"Input n：";
	cin>>n;
	calc();
	return 0;
}


 
