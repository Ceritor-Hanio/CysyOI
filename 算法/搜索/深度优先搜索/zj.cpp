#include<iostream>
using namespace std;
int n,size, s[20];

void search(int d){
	int i;
	if(d>n){   //ȫ�������� 
		cout<<'[';
		for (i=1; i<size; i++)
		   cout<<s[i]<<',';
		if(size>0) cout<<s[size];
	   cout<<']'<<endl;
	   return;
	}	
	search(d+1);//��d���������Ӽ� 
	size++;
	s[size]=d;
	search(d+1);//��d�������Ӽ� 
	size--;
	return;
} 
int main(){
	cin>>n;
	size=0;//�Ӽ�Ԫ�ظ��� 
	search(1);//��1��Ԫ�ؿ�ʼ���� 
	return 0;
} 
