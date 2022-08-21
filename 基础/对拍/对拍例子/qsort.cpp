#include <iostream>
#include <fstream >  //Ҫʹ���ļ���������������ͷ�ļ�
using namespace std;
ifstream fin("data.in"); //�����ļ�������fin����������input.txt
ofstream fout("right.out");//�����ļ������ouf����������output.txt
long a[100010];
void qsort(long l, long r){
	long t,mid,i,j;
	i=l; j=r;
	mid=a[(l+r)/2];  
	do{
		while (a[i]<mid) i++;
		while (a[j]>mid) j--;
		if(i<=j){
			t=a[i]; a[i]=a[j]; a[j]=t;
			i++; j--; 
		}
	} while(i<=j);
	if(l<j) qsort(l,j);
	if(i<r) qsort(i,r);
}
int main(){
   long i,n;
   fin>>n;
   for(i=1; i<=n; i++)
      fin>>a[i];
    qsort(1,n);
    for(i=1; i<n; i++)
       fout<<a[i]<<' ';
    fout<<a[n]<<endl;
    return 0;
}
