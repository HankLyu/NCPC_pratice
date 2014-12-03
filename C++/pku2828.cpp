#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

#define maxx 200005

using namespace std;

struct node{
	int beg,end,cnt;
}tree[maxx*8];
int queue[maxx];
int pos[maxx],value[maxx];
void build(int id,int beg,int end){
	tree[id].beg=beg,tree[id].end=end;
	tree[id].cnt=0;
	if(end>beg){
		build(id*2,beg,(beg+end)/2);
		build(id*2+1,(beg+end)/2+1,end);
	}
}
void insert(int id,int k){
	tree[id].cnt++;
	if(tree[id].beg==tree[id].end)	return ;
	if(k>(tree[id].beg+tree[id].end)/2)
		insert(id*2+1,k);
	else insert(id*2,k);
}
int query(int id,int k){
	if(tree[id].cnt==0)	return tree[id].beg+k-1;
	int tmp=tree[2*id].end-tree[2*id].beg-tree[2*id].cnt+1;
	if(k<=tmp)	query(2*id,k);
	else	query(2*id+1,k-tmp);
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		build(1,1,n);
		for(int i=0;i<n;i++)
			scanf("%d %d",&pos[i],&value[i]);
		for(int i=n-1;i>=0;i--){
			int m=query(1,pos[i]+1);
			queue[m]=i;
			insert(1,m);
		}
		for(int i=1;i<n;i++)
			printf("%d ",value[queue[i]]);
		printf("%d\n",value[queue[n]]);
	}
	return 0;
}
