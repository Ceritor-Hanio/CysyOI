#include<iostream>
#include<algorithm>
using namespace std;
int a[2000],n;
void sift(int i, int m){//����A[i..n-1]��Ϊһ���ѣ�����������������һ���ѣ�
  int k;
  a[0]=a[i];
  k=2*i;//kΪi������
  while(k<=m){ //i�������� 
    if(k<m && a[k]<a[k+1])
      k++; //ʹkָ�����Һ����нϴ��һ�� 
    if(a[0]<a[k]){ //��a[k]���ƣ��Ա�����ɸ 
      a[i]=a[k];
      i=k;
      k=2*i;
    }
    else k=m+1; //���� 
  } 
  a[i]=a[0];
}
void createheap(){
  int i;
  for(i=n/2;i>0;i--)
    sift(i,n); //����a[1..n]ʹ֮Ϊһ����
}
void heapsort(){
  int i;
  createheap(); //��a����һ����
  for(i=n;i>1;i--){
    swap(a[1],a[i]); //��1��Ԫ�����i��Ԫ�ؽ���
    sift(1,i-1); //����a[0]~a[a[i-1]ʹ֮Ϊһ���� 
  } 
}
int main(){
  int i;
  cin>>n;
  for(i=1; i<=n; i++)
    cin>>a[i];
  heapsort();
  for(i=1;i<=n;i++)
    cout<<a[i]<<" ";cout<<endl;
  return 0;  
}

