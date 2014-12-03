#include<iostream>
#include<cstdio>
#include<cstring>

#define maxx 2005

using namespace std;

int n,m;
bool w[maxx][maxx],visit[maxx];
int cycle[maxx],depth,ans;

void DFS(int now)
{
	visit[now]=true;
	for(int i=1;i<=n;i++)
		if(w[now][i]>0 && !visit[i])
			DFS(i);
	cycle[depth++]=now;
}
void INDFS(int now)
{
	visit[now]=true;
	for(int i=1;i<=n;i++)
		if(w[i][now]>0 && !visit[i])
			INDFS(i);
}
int main()
{
	int a,b,p;
	while(scanf("%d %d",&n,&m)!=EOF){
		if(n==0 && m==0)	break;
		memset(w,0,sizeof(w));
		memset(visit,0,sizeof(visit));
		depth=ans=0;
		for(int i=0;i<m;i++){
			scanf("%d %d %d",&a,&b,&p);
			w[a][b]=1;
			if(p==2)	w[b][a]=1;
		}
		for(int i=1;i<=n;i++)
			if(visit[i]==0)	DFS(i);
		memset(visit,0,sizeof(visit));
		for(int i=depth-1;i>=0;i--)
			if(visit[cycle[i]]==0){
				ans++;
				INDFS(cycle[i]);
			}
		if(ans>1)	printf("0\n");
		else		printf("1\n");
	}
	return 0;
}
