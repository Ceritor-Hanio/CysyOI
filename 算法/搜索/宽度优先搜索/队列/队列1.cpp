#include<iostream>
using namespace std;
const int MAXN=50;
int queue[MAXN];
int main(){
	int n, front,rear;
	cin>>n;
	for(int i=0;i<n;i++) queue[i]=i+1;//初始化队列 
	front=0;//队首元素的位置 
	rear=n;//队尾元素的后一个位置
	while(front<rear){//当队列非空
		cout<<queue[front++]<<' ';// 输出并抛弃队首元素
		queue[rear++]=queue[front++];//队首元素转移到队尾
	}
	return 0;
}



