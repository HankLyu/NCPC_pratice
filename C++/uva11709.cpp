#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<map>
#include<vector>

#define maxx 1005

using namespace std;

int w[maxx][maxx];
int visit[maxx],cycle[maxx];
int n,m,ans,depth;
map <string,int> qq;

void DFS(int now)
{
	visit[now]=true;
	for(int i=0;i<n;i++)
		if(w[now][i]>0 && !visit[i])
			DFS(i);
	cycle[depth++]=now;
}
void INDFS(int now)
{
	visit[now]=true;
	for(int i=0;i<n;i++)
		if(w[i][now]>0 && !visit[i])
			INDFS(i);
}
int main()
{
	char a[50],b[50];
	while(scanf("%d %d",&n,&m)!=EOF){
		if(n==0 && m==0)	break;
		qq.clear();
		ans=depth=0;
		memset(w,0,sizeof(w));
		memset(visit,0,sizeof(visit));
		memset(cycle,0,sizeof(cycle));
		gets(a);
		for(int i=0;i<n;i++){
			gets(a);
			qq[a]=i;
			//printf("%d %s\n",i,a);
		}
		for(int i=0;i<m;i++){
			gets(a);
			gets(b);
			w[ qq[a]][ qq[b]]=1;
		}
		for(int i=0;i<n;i++)
			if(visit[i]==0)
				DFS(i);
		memset(visit,0,sizeof(visit));
		for(int i=depth-1;i>=0;i--)
			if(visit[ cycle[i]] == 0){
				ans++;
				INDFS(cycle[i]);
			}
		printf("%d\n",ans);
	}
	qq.clear();
	return 0;
}
