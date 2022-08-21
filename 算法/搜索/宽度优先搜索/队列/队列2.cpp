#include<iostream>
#include<queue>//STL中实现了一个先进先出的容器
using namespace std;
const int MAXN=50;
int main(){
	int n;
	queue<int> q;
	cin>>n;	
	for(int i=1;i<=n;i++) q.push(i);//初始化队列 
	while(!q.empty()){//当队列非空
		cout<<q.front()<<' ';//输出队首元素
		q.pop();//删队首元素 
		q.push(q.front());//队首元素存入队尾
		q.pop();//删队头元素 
	}
	return 0;
}



