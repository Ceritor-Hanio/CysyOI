#include<iostream>
#include<algorithm>
using namespace std;
int a[2000],n;
void sift(int i, int m){//调整A[i..n-1]成为一个堆（它的左右子树已是一个堆）
  int k;
  a[0]=a[i];
  k=2*i;//k为i的左孩子
  while(k<=m){ //i有左子树 
    if(k<m && a[k]<a[k+1])
      k++; //使k指向左右孩子中较大的一个 
    if(a[0]<a[k]){ //将a[k]上移，以便向下筛 
      a[i]=a[k];
      i=k;
      k=2*i;
    }
    else k=m+1; //结束 
  } 
  a[i]=a[0];
}
void createheap(){
  int i;
  for(i=n/2;i>0;i--)
    sift(i,n); //调整a[1..n]使之为一个堆
}
void heapsort(){
  int i;
  createheap(); //把a建成一个堆
  for(i=n;i>1;i--){
    swap(a[1],a[i]); //第1个元素与第i个元素交换
    sift(1,i-1); //调整a[0]~a[a[i-1]使之为一个堆 
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

