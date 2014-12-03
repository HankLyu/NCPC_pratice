#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define maxn 205

using namespace std;

int nx,ny;
int mx[maxn],my[maxn];
bool vy[maxn];
bool adj[maxn][maxn];

int ini_matching()
{
	int cnt=0;
	for(int x=1; x<=nx; x++)
		if(mx[x] == -1)
			for(int y=1; y<=ny;y++)
				if(my[y]==-1 && adj[x][y]){
					mx[x]=y;
					my[y]=x;
					cnt++;
					break;
				}
	return cnt;
}

bool DFS(int x)
{
	for (int y=1;y<=ny;y++)
		if(adj[x][y] && !vy[y]){
			vy[y]=true;
			if(my[x] == -1 || DFS(my[y]) ){
				mx[x]=y; my[y]=x;
				return true;
			}
		}
	return false;
}

int bipartite_matching()
{
	memset(mx, -1, sizeof(mx) );
	memset(my, -1, sizeof(my) );
	int c=ini_matching();
	for(int x=1;x<=nx;x++)
		if(mx[x] == -1){
			memset(vy, false, sizeof(vy) );
			if(DFS(x) ) c++;
		}
	return c;
}
int main()
{
	int a,N,M,n;
	while(scanf("%d %d",&nx,&ny)==2){
		memset(adj,0,sizeof(adj) );
		for(int i=1;i<=nx;i++){
			scanf("%d",&n);
			for(int j=0;j<n;j++){
				scanf("%d",&a);
				adj[i][a]=true;
			}
		}
		printf("%d\n",bipartite_matching() );
	}
	return 0;
}
