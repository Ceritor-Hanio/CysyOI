#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN=5005;
int A[MAXN],B[MAXN],Ans[MAXN],C[MAXN],Len_A,Len_B,Len_Ans;
void Read(int *A){
	string cur;
	cin>>cur;
	A[0]=cur.length();
	for(int i=1; i<=A[0]; i++) A[i]=cur[i-1]-48;
	reverse(A+1, A+A[0]+1);
}
bool Big(){
	if(C[0]>B[0]) return true;
	if(C[0]<B[0]) return false;
	for(int i=C[0]; i>=1; i--)
	  if(C[i]<B[i]) return false;
	  else if(C[i]>B[i]) return true;
	return true;
}
void Minus(){
	int c=0;
	for(int i=1; i<=C[0]; i++){
		C[i]-=B[i]+c;
		if(C[i]<0) {C[i]+=10; c=1;}
		else c=0;
	}
	while(C[0]>1 && C[C[0]]==0) C[0]--;
}
void output(int *A)
{
	for(int j=A[0]; j>=1; j--) cout<<A[j];
	cout<<endl;
}
int main(){
	Read(A);
	Read(B);
	C[0]=0;
	for(int i=A[0]; i>=1; i--){
		for(int j=C[0]; j>=1; j--) C[j+1]=C[j];
		C[1]=A[i];
		C[0]++;
		while(Big()){
			Minus();
			Ans[i]++;
		}
	}
	Ans[0]=A[0];
	while(Ans[0]>1 && Ans[Ans[0]]==0) Ans[0]--;
	output(Ans);
	output(C);
	return 0;
}
