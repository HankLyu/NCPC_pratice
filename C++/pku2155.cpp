#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

#define maxx 1005

using namespace std;

int tree[maxx][maxx];

int lowbit(int x){
	return x &(-x);
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
	int test;
	int n,m;
	int a,b,c,d;
	char s[5];
	scanf("%d",&test);
	while(test--){
		memset(tree,0,sizeof(tree));
		scanf("%d %d",&n,&m);
		while(m--){
			scanf("%s",s);
			if(s[0]=='C'){
				scanf("%d %d %d %d",&a,&b,&c,&d);
				change(a,b,1);
				change(c+1,d+1,1);
				change(c+1,b,-1);
				change(a,d+1,-1);
			}
			else if(s[0]=='Q'){
				scanf("%d %d",&a,&b);
				int sum=0;
				//a++,b++;
				sum=getsum(a,b);
				printf("%d\n",sum%2);
			}
		}
		if(test)	printf("\n");
	}
	return 0;
}
