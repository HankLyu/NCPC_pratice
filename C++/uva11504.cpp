#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>

#define maxx 100005

using namespace std;

int n,m;
//int w[maxx][maxx];
bool visit[maxx],v[maxx];
int next[maxx];
vector<int>ans,edge[maxx],edge2[maxx];

int DFS(int now)
{
	int ans=0,tmp=0,len=edge[now].size();
	visit[now]=true;
	for(int i=0;i<len;i++){
	//	printf("edge[%d][%d]=%d visit:%d\n",now,i,edge[now][i],
	//		visit[edge[now][i]]);
		if(!visit[edge[now][i]]){
			tmp=1+DFS(edge[now][i]);
			if(ans<tmp){
				ans=tmp;
				next[now]=edge[now][i];
			}
		}
	}
	return ans;
}
int back(int now)
{
	int ans=0,tmp=0,len=edge2[now].size();
	v[now]=true;
	for(int i=0;i<len;i++){
		if(!v[edge2[now][i]]){
			tmp=1+back(edge2[now][i]);
			if(ans<tmp){
				ans=tmp;
				next[now]=edge2[now][i];
			}
		}
	}
}
int main()
{
	int test,a,b,tmp,x;
	scanf("%d",&test);
	while(test--){
		memset(next,-1,sizeof(next));
		memset(visit,0,sizeof(visit));
		memset(v,0,sizeof(v));
		scanf("%d %d",&n,&m);
		for(int i=0;i<m;i++){
			scanf("%d %d",&a,&b);
			edge[b].push_back(a);
			edge2[a].push_back(b);
		}
		for(int i=1;i<=n;i++)
			if(!visit[i]){
				//ans.push_back(i);
				DFS(i);
				tmp=i;
				/*printf("next:");
				for(int i=0;i<n;i++)
					printf("%2d",next[i]);
				printf("\n");*/
				while(next[tmp] != -1){
					//visit[tmp]=0;
					x=tmp;
					tmp=next[tmp];
					next[x]=-1;
				}
				ans.push_back(tmp);
				back(tmp);
				for(int i=1;i<=n;i++)	
					visit[i]=v[i];
				/*for(int i=1;i<=n;i++)
					printf("%2d",visit[i]);
				printf("\n");*/
			}
		/*for(int i=0;i<ans.size();i++)
			printf("%2d",ans[i]);
		printf("\n");*/
		printf("%d\n",ans.size());
		ans.clear();
		for(int i=1;i<=n;i++)	edge[i].clear(),edge2[i].clear();
	}
	return 0;
}
