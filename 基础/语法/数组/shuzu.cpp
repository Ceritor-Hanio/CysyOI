#include<iostream>
using namespace std;
const int MAXN=10001;
int main(){
    int a[MAXN];      //定义10001个数组元素
    int i,n,maxa,k;
    cin>>n;
    for(i=0;i<n;i++)
      cout<<i<<' ';
    cout<<endl;
    for(i=n-1;i>=0;i--)
      cout<<i<<' ';
    cout<<endl;
    for(i=0;i<n;i++)
      cin>>a[i];
    for(i=0;i<n;i++)
      cout<<a[i]<<' ';
    cout<<endl;
    for(i=n-1;i>=0;i--)
      cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}
