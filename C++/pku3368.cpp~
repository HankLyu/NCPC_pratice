#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

#define maxx 100005

using namespace std;

struct node{
	int l,r;
	int a,b,c;
}ln[maxx*3];
int n,q;
int num[maxx],pb[maxx];

void make(int l,int r,int id){
	ln[id].l=l,ln[id].r=r;
	int mid=(l+r)/2;
	ln[id].a=pb[l],ln[id].b=pb[r];
	if(l+1==r){
		ln[id].c=pb[r]-pb[l];
		return ;
	}
	make(l,mid,2*id);
	make(mid,r,2*id+1);
	ln[id].c=max(ln[2*id].c,ln[2*id+1].c);
}
int query(int a,int b,int id){
	if(a==ln[id].a && b==ln[id].b)	return ln[id].c;

	if(ln[id].l+1==ln[id].r)	return b-a;

	if(b<=ln[2*id+1].a)	return query(a,b,2*id);
	if(a>=ln[2*id+1].a)	return query(a,b,2*id+1);
	return max(query(a,ln[2*id+1].a,2*id),query(ln[2*id+1].a,b,2*id+1));
}
int main()
{
	while(scanf("%d",&n) && n){
		scanf("%d",&q);
		for(int i=0;i<n;i++)
			scanf("%d",&num[i]);
		int m=1;
		pb[0]=0;
		for(int i=1;i<n;i++)
			if(num[i]!=num[i-1])
				pb[m++]=i;
		pb[m]=n;
		make(0,m,1);
		int a,b;
		for(int i=0;i<q;i++){
			scanf("%d %d",&a,&b);
			printf("%d\n",query(a-1,b,1));
		}
	}
	return 0;
}
