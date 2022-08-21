#include <iostream>
using namespace std;

struct SAMPLE{
    int x;
    int y;
}s1;

int main(){
	SAMPLE s2;
    s1.x = 3;
    s1.y = 4;
    cout<<s1.x<<" "<<s1.y<<endl;
    s2.x=s1.y;
    s2.y=100;
    cout<<s2.x<<" "<<s2.y<<endl;
    
    SAMPLE s[10];
    for(int i=0; i<10; i++)
    	cin>>s[i].x>>s[i].y;
    	
    for(int i=9; i>=0; i--)
    	cout<<s[i].x<<" "<<s[i].y<<endl; 

    return 0;
}
/*
1 2
3 4
5 6
7 8
9 10
11 12
13 14
15 16
17 18
19 20
*/
