#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

#define maxx 50005

using namespace std;

struct node{
	int beg,end, cmax,cmin;
}tree[3*maxx];
int num[maxx];

struct node2{
	int cmax,cmin;
};
void create(int id,int beg,int end){
	tree[id].beg=beg,tree[id].end=end;
	if(beg==end){
		tree[id].cmax=num[beg];
		tree[id].cmin=num[end];
		return ;
	}
	int mid=(beg+end)/2;
	create(2*id,beg,mid);
	create(2*id+1,mid+1,end);
	tree[id].cmax=max(tree[2*id].cmax, tree[2*id+1].cmax);
	tree[id].cmin=min(tree[2*id].cmin, tree[2*id+1].cmin);
}
node2 findans(int id,int beg,int end,int ita,int itb){
	node2 tmp;
	tmp.cmax=0,tmp.cmin=2e9;
	if(ita>end || itb<beg)	return tmp;
	if(ita<=beg && end<=itb){
		tmp.cmax=tree[id].cmax;
		tmp.cmin=tree[id].cmin;
		return tmp;
	}
	if(beg==end){
		tmp.cmax=tree[id].cmax;
		tmp.cmin=tree[id].cmin;
		return tmp;
	}
	int  mid=(beg+end)/2;
	node2 lf,rf;
	lf=findans(2*id,beg,mid,ita,itb);
	rf=findans(2*id+1,mid+1,end,ita,itb);
	tmp.cmax=max(lf.cmax,rf.cmax);
	tmp.cmin=min(lf.cmin,rf.cmin);
	return tmp;
}
/*
int findmax(int id,int beg,int end,int ita,int itb){
	if(ita>end || itb<beg)	return 0;
	if(ita<=beg && end<=itb)	return tree[id].cmax;
	if(beg==end)	return tree[id].cmax;
	int lf,rf,mid;
	mid=(beg+end)/2;
	lf=findmax(2*id,beg,mid,ita,itb);
	rf=findmax(2*id+1,mid+1,end,ita,itb);
	return max(lf,rf);
}
int findmin(int id,int beg,int end,int ita,int itb){
	if(ita>end || itb<beg)	return 2e9;
	if(ita<=beg && end<=itb)	return tree[id].cmin;
	if(beg==end)	return tree[id].cmin;
	int lf,rf,mid;
	mid=(beg+end)/2;
	lf=findmin(2*id,beg,mid,ita,itb);
	rf=findmin(2*id+1,mid+1,end,ita,itb);
	return min(lf,rf);
}*/
int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF){
		for(int i=1;i<=n;i++)
			scanf("%d",&num[i]);
		create(1,1,n);
		int a,b,cowmax,cowmin;
		node2 ans;
		for(int i=0;i<m;i++){
			scanf("%d %d",&a,&b);
			ans=findans(1,1,n,a,b);
			//cowmax=findmax(1,1,n,a,b);
			//cowmin=findmin(1,1,n,a,b);
			printf("%d\n",ans.cmax-ans.cmin);
		}
	}
	return 0;
}
