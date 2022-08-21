#include<iostream>
using namespace std;
struct node{
	long left,right;
	long delta,max,min;
	node *lchild, *rchild;
};
void build(node *cur, long l, long r){//����������(l,r)���cur 
	cur->left=l; cur->right=r;
	cur->delta=0; cur->max=0;//������� 
	if(l==r){//Ҷ�˽�� 
		cur->lchild=NULL; cur->rchild=NULL;
	} else{//�������������� 
		cur->lchild=new node; cur->rchild=new node;
		build(cur->lchild,l,(l+r)/2);
		build(cur->rchild,(l+r)/2+1,r);
	}
}
void update(node* cur, long l, long r, long delta){//�޸� 
	node *lc, *rc;
	lc=cur->lchild; rc=cur->rchild;
	if(l<=cur->left && r>=cur->right){//�ڵ�cur�ǲ�ѯ����Ĳ��� 
		cur->delta+=delta;cur->max+=delta;
	} else{
		if(l<=(cur->left+cur->right)/2) update(lc,l,r,delta);//������ 
		if(r>(cur->left+cur->right)/2) update(rc,l,r,delta);//������ 
		cur->max=max(lc->max,rc->max)+cur->delta;
	}
}
long querymax(node *cur, long l, long r){
	node *lc, *rc;
	long ret=0;
	lc=cur->lchild; rc=cur->rchild; 
	if(l<=cur->left && cur->right<=r) ret=cur->max;//�������� 
	else {//�ֱ����������� 
		lc->delta+=cur->delta; rc->delta+=cur->delta;
		lc->max+=cur->delta; rc->max+=cur->delta;
		cur->delta=0;
		if(l<=(cur->left+cur->right)/2) ret=querymax(lc,l,r);
		if(r>(cur->left+cur->right)/2) ret=max(ret,querymax(rc,l,r));
	}
	return ret;
}
int main(){
	long c,s,r,i, a,b,x;
	cin>>c>>s>>r;
	node *tree=new node;
	build(tree,1,c);
	for(i=1;i<=r;i++){
		cin>>a>>b>>x;
		if(querymax(tree,a,b-1)+x>s) cout<<"NO"<<endl;
		else {
			cout<<"YES"<<endl;
			update(tree,a,b-1,x);
		}
	}
	return 0;
}
