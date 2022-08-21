#include <iostream>
#include <iomanip>
using namespace std;
struct node{//������������
	int father,a,b;
};
int x,y,z;
bool flag=false;
node data[10010];  //���� 
int front,rear;
bool bl[110][110]={false};//����
void init(){
	cout<<"Input x,y,z:";
	cin>>x>>y>>z;
	return ;
}
void out(){//���
	int i,j;
	int d[10010];
	flag=true;
	j=0; i=--rear;
	do{
		d[++j]=i;//�ҳ���������
		i=data[i].father;
	} while(i!=0);cout<<endl;
	for(i=j;i>0;i--)
	    cout<<"step"<<setw(3)<<j-i<<":"<<setw(5)<<data[d[i]].a<<setw(5)<<data[d[i]].b<<endl;
	exit(0) ;
}
void evaluate(int i, int j){//���
	bl[i][j]=true;
	data[rear].a=i; data[rear].b=j;
	data[rear++].father=front-1;
	if(j==z) {out();}
	return ;
}
void bfs(){//����
	int i,j,k,L;
	front=1; rear=2;
	data[1].a=0; data[1].b=0; data[1].father=0;//��ʼ������
	bl[0][0]=true;
	if( z==0) out(); 
	do{
		i=data[front].a; j=data[front++].b;//���� 
		//��� 
		k=min(i,y-j); L=min(j,x-i);
		if(i>0 && j<y && !bl[i-k][j+k]) evaluate(i-k,j+k);
		if(j>0 && i<x && !bl[i+L][j-L]) evaluate(i+L,j-L);
		if(i>0 && !bl[0][j]) evaluate(0,j);
		if(j>0 && !bl[i][0]) evaluate(i,0);
		if(i<x && !bl[x][j]) evaluate(x,j);
		if(j<y && !bl[i][y]) evaluate(i,y);
	}while (front<rear);
	if(!flag) cout<<"Impossile"<<endl;
	return ;
}
int main(){
	init();
	bfs();
	return 0;
}
	
