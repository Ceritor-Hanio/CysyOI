#include<iostream>
using namespace std;
int road[][8]={{1,0,0,0,0,0,0,0},{0,1,1,1,1,0,1,0}, {0,0,0,0,1,0,1,0}, {0,1,0,0,0,0,1,0}, {0,1,0,1,1,0,1,0}, {0,1,0,0,0,0,1,1}, {0,1,0,0,1,0,0,0}, {0,1,1,1,1,1,1,0}};
int fangxiang[][2]={{1,0},{0,1},{-1,0},{0,-1}};
int wayin[]={1,1}, wayout[]={8,8};
long i,j,total;
void output(){
	int i,j;
	for(i=1; i<=8; i++)
	  for(j=0; j<8; i++){
	  	if (road[i][j]==1) cout<<1;
	  	if (road[i][j]==2) cout<<2;
	  	if (road[i][j==3]) cout<<3;
	  	if (road[i][j]==0) cout<<4;
	  }
	total++; 
}
bool ok(int x, int y, int i){
    int newx,newy; 
    newx=x+fangxiang[i][0];
	newy=y+fangxiang[i][1];
	if(newx<1 || newx>8 || newy<1 || newy>8)
	  return false;
    if(road[newx][newy]==3) return false;
	if(road[newx][newy]==1) return false;
	return true;
}
void howgo(int x, int y){
	int newx,newy;
	for(i=0;i<4; i++)
	   if (ok(x,y,i)) {
	   	  newx=x+fangxiang[i][0];
	   	  newy=y+fangxiang[i][1];
	   	  road[newx][newy]=3;
	   	  if(newx==wayout[0] && newy==wayout[1]) output;
	   	    else howgo(newx,newy);
	   	  road[newx][newy]=0;
	   }
}
int main(){
	total=0;
	road[wayin[0]][wayin[1]]=3;
	howgo(wayin[0],wayin[1]);
	cout<<"Total is "<<total<<endl;
	return 0;
}
