#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

#define maxx 1005

using namespace std;

struct node{
	int e,w;
}e[maxx*maxx];
int s[maxx*maxx];

bool cmp(node a,node b){
	if(a.e==b.e)	return a.w>b.w;
	return a.e>b.e;
}
int lowbit(int x){
	return x&(-x);
}
int getsum(int end){
	int tmp=0;
	for(int i=end;i>0;i-=lowbit(i))
		tmp+=s[i];
	return tmp;
}
void change(int end,int delta){
	for(int i=end;i<maxx;i+=lowbit(i))
		s[i]+=delta;
}
int main()
{
	int test;
	scanf("%d",&test);
	for(int t=1;t<=test;t++){
		int m,n,k;
		int a,b;
		memset(s,0,sizeof(s));
		scanf("%d %d %d",&n,&m,&k);
		for(int i=0;i<k;i++)
			scanf("%d %d",&e[i].e,&e[i].w);
		int sum=0;
		sort(e,e+k,cmp);
		for(int i=0;i<k;i++){
			sum+=getsum(e[i].w-1);
			change(e[i].w,1);
		}
		printf("Test case %d: %d\n",t,sum);
	}
	return 0;
}
