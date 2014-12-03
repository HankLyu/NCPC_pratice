#include<iostream>
#include<cstdio>
#include<cstring>

#define maxx 1005

using namespace std;

int w[maxx][maxx],inver[maxx][maxx];
int visit[maxx],invis[maxx];
int cycle[maxx],n,m,depth,ans;

void DFS(int now)
{
	visit[now]=true;
	for(int i=1;i<=n;i++){
		if(w[now][i]>0 && !visit[i]){
			DFS(i);
		}
	}
	cycle[depth++]=now;
}
void INDFS(int now)
{
	invis[now]=true;
	for(int i=1;i<=n;i++)
		if(w[i][now]>0 && !invis[i])
			INDFS(i);
}
int main()
{
	int test,a,b;
	scanf("%d",&test);
	for(int t=0;t<test;t++){
		depth=0,ans=0;
		memset(w,0,sizeof(w));
		memset(visit,0,sizeof(visit));
		memset(invis,0,sizeof(invis));
		memset(cycle,0,sizeof(cycle));
		scanf("%d %d",&n,&m);
		for(int i=0;i<m;i++){
			scanf("%d %d",&a,&b);
			w[a][b]=1;
		}
		scanf("%d",&a);
		for(int i=1;i<=n;i++)
			if(visit[i]==0)
				DFS(i);
		for(int i=depth-1;i>=0;i--){
			if(invis[ cycle[i] ]==0){
				ans++;
				INDFS( cycle[i] );
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
