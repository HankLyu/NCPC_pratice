#include<iostream>
#include<cstdio>
#include<cstring>

#define maxx 900

using namespace std;

int weight[maxx][maxx],n;
int depth[maxx],low[maxx];
int used[maxx];
int cutBridge[maxx][maxx];

int DFS(int node,int d,int parent)
{
	int back=1000,tmp;
	depth[node]=d;
	for(int i=0;i<n;i++){
		if(weight[node][i]==1){
			if(used[i]==0){
				used[i]=1;
				tmp=DFS(i,d+1,node);
				//printf("tmp=%d ",tmp);
				if(tmp>d){
					cutBridge[node][i]=1;
					cutBridge[i][node]=1;
				}
				back=min(back,tmp);
			}
			else{
				if(i != parent)	back=min(back,depth[i]);
			}
			//printf("node=%d i=%d d=%d back=%d\n",node,i,d,back);
		}
	}
	low[node]=back;
	return low[node];
}
int main()
{
	int x,y,m,Case=0;
	while(scanf("%d",&n) !=EOF){
		memset(weight,0,sizeof(weight));
		memset(depth,0,sizeof(depth));
		memset(low,0,sizeof(low));
		memset(used,0,sizeof(used));
		memset(cutBridge,0,sizeof(cutBridge));
		for(int i=0;i<n;i++){
			scanf("%d (%d)",&x,&m);
			while(m--){
				scanf("%d",&y);
				weight[x][y]=weight[y][x]=1;
			}
		}
		for(int i=0;i<n;i++)
			if(used[i]==0){
				used[i]=1;
				DFS(i,1,-1);
			}
		int ans=0;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(cutBridge[i][j]!=0)	ans++;
		printf("%d critical links\n",ans);
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(cutBridge[i][j] != 0)
					printf("%d - %d\n",i,j);
		printf("\n");
	}
	return 0;
}
