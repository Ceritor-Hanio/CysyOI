#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5005;
void Read(int *A){
	string s;
	cin>>s;
	A[0]=s.length();
	for(int i=1; i<=A[0]; i++) A[i]=s[i-1]-48;
	reverse(A+1, A+A[0]+1);
	return ;
}
 
void devide(int *A, long b, int *C, long *d){
	int i,len,e=0;
	memset(C,0,sizeof(C));
	len=A[0];
	for(i=len; i>0; i--){
		e=e*10+A[i];
		C[i]=e/b;
		e %=b;
	}
	while(len>1 && C[len]==0) len--;
	C[0]=len; *d=e;
}
int main(){
	int A[MAXN], C[MAXN];
	long b,d;
	Read(A);cin>>b;
	devide(A,b,C,&d);
	for(int i=C[0]; i>0; i--) cout<<C[i]; cout<<endl;
	cout<<d<<endl;
	return 0;
}
