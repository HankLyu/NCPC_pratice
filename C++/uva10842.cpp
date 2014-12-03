#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define maxx 105
#define INF -1
#define INFB 10000

using namespace std;

int n,m,g[maxx][maxx],p[maxx],pa;
	//g weight		p parent
void prim()
{
	int d[maxx],v,mi;
	bool vis[maxx];
	for(int i=0;i<=n;i++)
		d[i]=p[i]=-1;
	memset(vis,false,sizeof(vis));
	d[0]=0,pa=0;
	for(int u=0;u<n;u++){
		mi=INF;
		for(int i=0;i<n;i++)
			if(!vis[i] && d[i]>mi)
				mi=d[i],v=i;
		vis[v]=true;
		pa += mi;
		for(int i=0;i<n;i++)
			if(!vis[i] && d[i]<g[v][i])
				p[i]=v,d[i]=g[v][i];
	}
}
int main()
{
	int test,t=1;
	scanf("%d",&test);
	while(test--){
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				g[i][j]=-1;
		for(int i=0;i<m;i++){	
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			if(a != b){
				g[a][b]=g[b][a]=max(c,g[a][b]);
			}
		}
		prim();
		int ans=INFB;
		for(int i=1;i<n;i++)
			ans=min(ans,g[i][p[i]]);
		printf("Case #%d: %d\n",t++,ans);
	}
	return 0;
}
