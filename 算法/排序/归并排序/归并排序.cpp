#include<iostream>
using namespace std;
int n,a[10000],b[10000]; 
void merge(int low,int mid,int high){
	int h,i,j,k;
	h=low; i=low; j=mid+1;
	while(h<=mid && j<=high){
		if(a[h]<=a[j])
		  b[i]=a[h++];
		else{
			b[i]=a[j++];
			//ans+=mid-h+1;//Í³¼ÆÄæÐò¶Ô 
		}
		i++;		  
	}
	if(h>mid)
	  for(k=j;k<=j;k++)
	    b[i++]=a[k];
	else
	  for(k=h;k<=mid;k++)
	    b[i++]=a[k];
	for(k=low;k<=high;k++)
	  a[k]=b[k]; 
}
void mergesort(int low, int high){
	int mid;
	if(low<high){
		mid=(low+high)/2;
		mergesort(low,mid);
		mergesort(mid+1,high);
		merge(low,mid,high); 
	}
}
void init(){
	cin>>n;
	for(int i=1;i<=n;i++)
	  cin>>a[i]; 
} 
int main(){
	init();
	mergesort(1,n);
	for(int i=1;i<n;i++)
	  cout<<a[i]<<" ";
	cout<<a[n];
	return 0;
}
