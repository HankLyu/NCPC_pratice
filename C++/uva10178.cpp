#include<iostream>
#include<cstdio>
#include<cstring>

#define maxx 300

using namespace std;

char parent[maxx],rank[maxx];
int ans;

char FindSet(char x)
{
	if(x!=parent[x])	parent[x]=FindSet(parent[x]);
	return parent[x];
}
void Link(char x,char y)
{
	if(x==y)	ans++;
	if(rank[x]>rank[y])		parent[y]=x;
	else{
		parent[x]=parent[y];
		if(rank[x]==rank[y])	rank[y]++;
	}
}
void Union(char x,char y)
{
	Link(FindSet(x),FindSet(y));
}
int main()
{
	int n,e;
	char a,b;
	while(scanf("%d %d",&n,&e) != EOF){
		ans=0;
		for(int i=0;i<maxx;i++)	parent[i]=(char)i;
		memset(rank,0,sizeof(rank));
		for(int i=0;i<e;i++){
			cin>>a>>b;
			Union(a,b);
		}
		printf("%d\n",ans+1);
	}
	return 0;
}
