#include<iostream>
using namespace std;
int tot,m,i;
int t[102], v[102];
long sumV, sumT, best;
void search(int d){
	if(sumT>tot) return;//超时 
	if(d==m+1) {
	  if (sumV>best) best=sumV;//更优 
	  return;
	} 
	search(d+1);//不取 
	sumV=sumV+v[d];
	sumT=sumT+t[d]; 
	search(d+1);//取 
	sumV=sumV-v[d];
	sumT=sumT-t[d];
	return;
}
int main(){
	cin>>tot>>m;
	for(int i=1; i<=m; i++)
	  cin>>t[i]>>v[i];
	search(1);
	cout<<best<<endl;
	return 0;
}

 
