#include<iostream>
using namespace std;
int n, front, rear;
int a[8010][3];//a[i][0]����㣬a[i][1]���������a[i][2]���˶��ٸ����泯��
bool b[810]={false};//���泯�ϸ����Ƿ���ֹ�������
bool flag=false;
void out(){//���
	int i,j,k,L,h;
	int d[5010];
	char st[5010];
	cout<<"step 0:";
	for(i=1;i<=n;i++) cout<<'O';cout<<endl;	
	for(i=1;i<=n;i++) st[i]='O';
	j=0; i=rear-1;
	do{
	   d[++j]=i; i=a[i][0];//a[i,0]Ϊ�������
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
		  	b[m-r+5-r]=true;//����r���泯�ϣ�����5-r���泯��
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
	cout<<"Input n��";
	cin>>n;
	calc();
	return 0;
}


 
