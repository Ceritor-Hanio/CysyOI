#include <iostream>
#include <fstream >  //Ҫʹ���ļ���������������ͷ�ļ�
using namespace std;
ifstream fin("data.in"); //�����ļ�������fin����������input.txt
ofstream fout("test.out");//�����ļ������ouf����������output.txt
int  main(){
    int a[100000],i,j,k,temp,n;
    fin>>n;
    for (i=0;i<n;i++)
          fin>>a[i];
    for (i=0;i<n-1;i++)   {
          k=i;
          for (j=i+1;j<n;j++)
                if (a[j]<a[k]) k=j;
          if (k!=i) {
            temp=a[i];
 	   a[i]=a[k]; 
              a[k]=temp;
           }
     }   
   for (i=0;i<n-1;i++)
          fout << a[i] <<" ";
   fout <<a[n-1]<<endl<<"1"; 
   return 0;
}
