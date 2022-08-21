#include<cstdio>
#include<algorithm>
#define MAXN 100005
using namespace std;
int a[MAXN],b[MAXN],n,tot,root[MAXN],q,l,r,k,link[MAXN],t;
struct Node{
  int ls,rs,size;
};
Node tree[MAXN*20];
struct cmp{
  bool operator () (int i,int j){
    return (a[i]<a[j]);
  }
};
cmp x;
void discretize(){
  sort(link+1,link+n+1,x); // 以link作为中转站，对a进行排序?
  for (int i=1;i<=n;i++) b[link[i]]=i;//b[x]表示第x个为第b[x]名
}
void insert(int &now,int l,int r,int x){
  tree[++tot]=tree[now]; now=tot;
  tree[now].size++;
  if (l==r) return;
  int mid=(l+r)>>1;
  if (x<=mid) insert(tree[now].ls,l,mid,x);
  else insert(tree[now].rs,mid+1,r,x);
}
int query(int nl,int nr,int l,int r,int k){//第k小
  if (l==r) return l;
  int size=tree[tree[nr].ls].size-tree[tree[nl].ls].size,mid=(l+r)>>1;
  if (size>=k) return query(tree[nl].ls,tree[nr].ls,l,mid,k);
  else return query(tree[nl].rs,tree[nr].rs,mid+1,r,k-size);
}
int main(){
  //freopen("HDU2665.in","r",stdin);
  //freopen("HDU2665.out","w",stdout);
  scanf("%d",&t);
  for (int j=1;j<=t;j++){
    root[0]=0; tot=0;
    scanf("%d %d",&n,&q);
    for (int i=1;i<=n;i++) { scanf("%d",&a[i]); link[i]=i; }
    discretize(); // 离散化
    for (int i=1;i<=n;i++){
      root[i]=root[i-1];
      insert(root[i],1,n,b[i]);
    }
/*    for(int i=1; i<=n; i++)
    	printf("%d ",root[i]);
    printf("\n");
    printf("%d %d\n",tree[13].ls,tree[13].rs);
    printf("%d %d\n",tree[17].ls,tree[17].rs);
    for (int i=1;i<=q;i++){
      scanf("%d %d %d",&l,&r,&k);
      printf("%d\n",a[link[query(root[l-1],root[r],1,n,k)]]);
    }*
  }
  return 0;
}
/*
1
8 0
134 23 98 178 289 83 918 100
*/

