#include<iostream>
using namespace std;
const int MAXN=50;
int queue[MAXN];
int main(){
	int n, front,rear;
	cin>>n;
	for(int i=0;i<n;i++) queue[i]=i+1;//��ʼ������ 
	front=0;//����Ԫ�ص�λ�� 
	rear=n;//��βԪ�صĺ�һ��λ��
	while(front<rear){//�����зǿ�
		cout<<queue[front++]<<' ';// �������������Ԫ��
		queue[rear++]=queue[front++];//����Ԫ��ת�Ƶ���β
	}
	return 0;
}



