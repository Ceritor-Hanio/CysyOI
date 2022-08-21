#include<iostream>
using namespace std;
struct node{
	long left,right,delta,sum;
	node* lchild, *rchild;
};
void build(node *cur, long l, long r){
	cur->left=l; cur->right=r;
	cur->delta=0;  cur->sum=0;
	if(l+1==r){
		cur->lchild=NULL; cur->rchild=NULL;
	}
	else {
		cur->lchild=new node;
		cur->rchild=new node;
		build(cur->lchild,l,(l+r)/2);
		build(cur->rchild,(l+r)/2,r);
	}
}
void update(node *cur,long l,long r, long t){
	node *lc, *rc;
	lc=cur->lchild; rc=cur->rchild;
	if(l<=cur->left && cur->right<=r)
	  if(t==0) (cur->delta)--;
	  else (cur->delta)++;
	else{
		if(l<(cur->left+cur->right)/2) update(lc,l,r,t);
		if(r>(cur->left+cur->right)/2) update(rc,l,r,t);
		if(lc->delta>0) cur->sum=lc->right-lc->left;
		  else cur->sum=lc->sum;
		if(rc->delta>0) cur->sum+=rc->right-rc->left;
		  else cur->sum+=rc->sum;
	}
}
int main(){
	struct node2{
		long h1,h2;
		node2 *next;
	};
	long i, n, sum, x1,x2,y1,y2;
	node *tree;
	node2 *add[30001], *del[30001], *p;
	for(i=0;i<=30000;i++){
		add[i]=NULL; del[i]=NULL;
	}
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>x1>>y1>>x2>>y2;
		p=new node2; p->h1=y1; p->h2=y2;
		p->next=add[x1]; add[x1]=p;
		p=new node2; p->h1=y1; p->h2=y2;
		p->next=del[x2]; del[x2]=p;
	}
	tree=new node; build(tree,0,30000);sum=0;
	for(i=0;i<30000;i++){
		p=del[i];
		while(p!=NULL){
			update(tree,p->h1,p->h2,0); p=p->next;
		}
		p=add[i];
		while(p!=NULL){
			update(tree,p->h1,p->h2,1); p=p->next;
		}
		if(tree->delta>0) sum+=30000;
		else sum+=tree->sum;
	}
	cout<<sum<<endl;
	return 0;
}
 


