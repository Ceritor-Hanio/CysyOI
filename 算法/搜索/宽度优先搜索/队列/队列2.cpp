#include<iostream>
#include<queue>//STL��ʵ����һ���Ƚ��ȳ�������
using namespace std;
const int MAXN=50;
int main(){
	int n;
	queue<int> q;
	cin>>n;	
	for(int i=1;i<=n;i++) q.push(i);//��ʼ������ 
	while(!q.empty()){//�����зǿ�
		cout<<q.front()<<' ';//�������Ԫ��
		q.pop();//ɾ����Ԫ�� 
		q.push(q.front());//����Ԫ�ش����β
		q.pop();//ɾ��ͷԪ�� 
	}
	return 0;
}



