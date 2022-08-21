#include<iostream>
using namespace std;
int n,a[9];
bool vis[9]; 
void search(int d){
	int i;
	if (d>n){ //输出结果 
		for(i=1; i<n; i++) cout<<a[i]<<' ';
		cout<<a[n]<<endl;
		return;  
    }
    for(i=1;i<=n;i++)//枚举d位的数字 
      if (!vis[i]){//是否使用过 
	    a[d]=i;    //记录 
		vis[i]=true;//设置已使用
		search(d+1); //下一位 
		vis[i]=false; //恢复状态 
	}
	return ;
}
int main(){
	cin>>n;
	for(int i=1;i<=n; i++)//全部没用过 
	  vis[i]=false;
    search(1);
    return 0;
} 
	
