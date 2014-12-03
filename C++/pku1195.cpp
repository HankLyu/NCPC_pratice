#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

#define maxx 1100

using namespace std;

int tree[maxx][maxx];

int lowbit(int x){
	return x&(-x);
}
void change(int x,int y,int delta){
	for(int i=x;i<maxx;i+=lowbit(i))
		for(int j=y;j<maxx;j+=lowbit(j))
			tree[i][j]+=delta;
}
int getsum(int x,int y){
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i))
		for(int j=y;j>0;j-=lowbit(j))
			sum+=tree[i][j];
	return sum;
}
int main()
{
	int ins,n,x,y,d;
	int l,b,r,t,sum;
	while(scanf("%d",&ins) && ins!=3){
		switch(ins){
			case 1:	scanf("%d %d %d",&x,&y,&d);
					x++,y++;
					change(x,y,d);
					break;
			case 2:	scanf("%d %d %d %d",&l,&b,&r,&t);
					sum=0;
					l++,b++,r++,t++;
					sum=getsum(r,t)-getsum(l-1,t)-getsum(r,b-1)+
						getsum(l-1,b-1);
					printf("%d\n",sum);
					break;
			case 0:	scanf("%d",&n);
					memset(tree,0,sizeof(tree));
					break;
			default:	break;
		}
	}
	return 0;
}
