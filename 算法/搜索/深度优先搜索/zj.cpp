#include<iostream>
using namespace std;
int n,size, s[20];

void search(int d){
	int i;
	if(d>n){   //全部都决定 
		cout<<'[';
		for (i=1; i<size; i++)
		   cout<<s[i]<<',';
		if(size>0) cout<<s[size];
	   cout<<']'<<endl;
	   return;
	}	
	search(d+1);//第d个不属于子集 
	size++;
	s[size]=d;
	search(d+1);//第d个属于子集 
	size--;
	return;
} 
int main(){
	cin>>n;
	size=0;//子集元素个数 
	search(1);//第1个元素开始决定 
	return 0;
} 
