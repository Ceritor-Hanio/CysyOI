#include<iostream>
using namespace std;
int n,a[9];
bool vis[9]; 
void search(int d){
	int i;
	if (d>n){ //������ 
		for(i=1; i<n; i++) cout<<a[i]<<' ';
		cout<<a[n]<<endl;
		return;  
    }
    for(i=1;i<=n;i++)//ö��dλ������ 
      if (!vis[i]){//�Ƿ�ʹ�ù� 
	    a[d]=i;    //��¼ 
		vis[i]=true;//������ʹ��
		search(d+1); //��һλ 
		vis[i]=false; //�ָ�״̬ 
	}
	return ;
}
int main(){
	cin>>n;
	for(int i=1;i<=n; i++)//ȫ��û�ù� 
	  vis[i]=false;
    search(1);
    return 0;
} 
	
