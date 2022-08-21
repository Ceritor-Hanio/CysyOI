#include <iostream>
#include <fstream >  //要使用文件输入输出流必须的头文件
using namespace std;
ifstream fin("data.in"); //定义文件输入流fin，并关联到input.txt
ofstream fout("test.out");//定义文件输出流ouf，并关联到output.txt
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
