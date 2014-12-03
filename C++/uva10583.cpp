#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define maxx 50005

using namespace std;

int m,n;
int p[maxx],rank[maxx];
bool haveRank[maxx];
void MakeSet()
{
	for(int i=0;i<maxx;i++)
		p[i]=i;
	memset(rank,0,sizeof(rank));
}
int FindSet(int x)
{
	if(x != p[x])
		p[x]=FindSet(p[x]);
	return p[x];
}
void Link(int x,int y)
{
	if(rank[x]>rank[y])
		p[y]=x;
	else{
		p[x]=y;
		if(rank[x]==rank[y])
			rank[y]++;
	}
}
void Union(int x,int y)
{
	Link(FindSet(x),FindSet(y));
}


int main()
{
	int test=1,a,b,ans;
	while(scanf("%d %d",&n,&m) != EOF){
		if(m==0 && n==0)	break;
		printf("Case %d: ",test);
		test++;
		MakeSet();
		memset(haveRank,false,sizeof(haveRank));
		ans=0;
		for(int i=0;i<m;i++){
			scanf("%d %d",&a,&b);
			Union(a,b);
		}
		for(int i=1;i<=n;i++){
			haveRank[FindSet(i)]=true;
		}
		for(int i=1;i<=n;i++)
			if(haveRank[i])
				ans++;
		printf("%d\n",ans);
	}//while scanf
	return 0;
}
