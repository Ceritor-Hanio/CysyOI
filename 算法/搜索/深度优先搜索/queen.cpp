#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
int n,total=0
int x[8]; //��i�ʺ����ŵ�λ�� 
bool a[9]; //�� 
bool b[17]=;//���Խ���(����������
bool c[17]=; //�ӶԽ���(����������)
void output(){//������ 
	total++;
	cout<<total<<':';
	for(int i=1; i<=n; i++)
	   cout<<setw(3)<<x[i];
	cout<<endl;
	return;
}
void dfs(int i){
	int j;
	if(i==n+1) output(); //n���ʺ��Ѱ��� 
	for(j=1;j<=n;j++)
	  if (a[j] && b[j+i] && c[j-i+7]) {
	  	x[i]=j;
	  	a[j]=false;//���б�ռ
	  	b[j+i]=false;//���Խ��߱�ռ
	  	c[j-i+7]=false;//�ӶԽ��߱�ռ
	  	dfs(i+1);//��һ���ʺ�
	  	 //����
	  	a[j]=true;
	  	b[j+i]=true;
	  	c[j-i+7]=true;
	  }
	return;
}
int main(){
	cin>>n;
	for (int i=0;i<9; i++)
	  a[i]=true;
	for (int i=0;i<17;i++)
	   b[i]=c[i]=true;
	dfs(1);
	cout<<"total = "<<total<<endl;
	return 0;
}
