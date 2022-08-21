//�˳���ʵ�ֵ�ΪС���ѣ��������ʸ���Ҫ����С�� 
//����ʵ�ֵĹ����У��������Լ�ȡ��С��Ԫ��
//�������ս�����ɽ��� 
#include<iostream>
#include<algorithm>
using namespace std;
long n,size,a[2000];
void insert(long x){
  long p=++size;
  while(a[p/2]>x && p>1){
    a[p]=a[p/2];
    p=p/2;
  }
  a[p]=x;
}
void heapfy(long idx){
  long l,r,low;
  l=2*idx;
  r=l+1;
  if(a[l]<a[idx] && l<=size)
    low=l;
  else low=idx;
  if(a[r]<a[low] && r<=size)
    low=r;
  if(idx!=low){
    swap(a[idx],a[low]);
    heapfy(low);
  }
}
long getmin(){
  return a[1];
}
long pop(){
  long temp=a[1];
  a[1]=a[size];
  size--;
  heapfy(1);
  return temp;
}
int main(){
  cin>>n;
  size=0;
  long x;
  for(int i=1; i<=n; i++){
    cin>>x;
    insert(x);
  }
  for(int i=1; i<=n; i++)
    a[n-i+1]=pop();
  for(int i=1; i<=n; i++)
    cout<<a[i]<<" ";
  cout<<endl;
  return 0;     
}

