#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
int n,total=0
int x[8]; //第i皇后所放的位置 
bool a[9]; //列 
bool b[17]=;//主对角线(左上至右下
bool c[17]=; //从对角线(右上至左下)
void output(){//输出结果 
	total++;
	cout<<total<<':';
	for(int i=1; i<=n; i++)
	   cout<<setw(3)<<x[i];
	cout<<endl;
	return;
}
void dfs(int i){
	int j;
	if(i==n+1) output(); //n个皇后已安置 
	for(j=1;j<=n;j++)
	  if (a[j] && b[j+i] && c[j-i+7]) {
	  	x[i]=j;
	  	a[j]=false;//此列被占
	  	b[j+i]=false;//主对角线被占
	  	c[j-i+7]=false;//从对角线被占
	  	dfs(i+1);//下一个皇后
	  	 //重置
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
