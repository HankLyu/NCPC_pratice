#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cstdlib>

#define maxx 105
#define maxl 1000
#define INF 1000000000

using namespace std;

struct Edge
{
	int t,w;
}tmp;
vector<Edge>edge[maxx];
int n,k,dis[maxx];

bool SPFA(int start)
{
	queue<int>v;
	int count[maxx],nowv,nextv;
	bool inqueue[maxx];

	memset(count,0,sizeof(count));
	memset(inqueue,0,sizeof(inqueue));
	for(int i=0;i<maxx;i++)
		dis[i]=INF;
	v.push(start);
	inqueue[start]=true;
	count[start]=1;
	dis[start]=0;

	while(!v.empty()){
		nowv=v.front();
		v.pop();
		inqueue[nowv]=false;
		for(int i=0;i<(int)edge[nowv].size();i++){
			nextv=edge[nowv][i].t;
			if(dis[nowv]+edge[nowv][i].w<dis[nextv]){
				dis[nextv]=dis[nowv]+edge[nowv][i].w;
				if(!inqueue[nextv]){
					v.push(nextv);
					inqueue[nextv]=true;
					count[nextv]++;
				}
				//if(count[nextv]>=n)
				//	return true;
			}
		}
	}
	return false;
}
int main()
{
	int t[6],a[maxl],m;
	char input[maxl],*p;
	while(scanf("%d %d",&n,&k) != EOF){
		for(int i=1;i<=n;i++)
			scanf("%d",&t[i]);
		getchar();
		for(int i=0;i<maxx;i++)	edge[i].clear();
		for(int i=1;i<=n;i++){
			gets(input);
			int m=0;
			for(p=strtok(input," ");p!=NULL;p=strtok(NULL," "))
				a[m++]=atoi(p);
			for(int j=1;j<m;j++)
				for(int k=0;k<j;k++){
					int cost=t[i]*(a[j]-a[k])+60;
					tmp.t=a[j],tmp.w=cost;
					edge[a[k]].push_back(tmp);
					tmp.t=a[k],tmp.w=cost;
					edge[a[j]].push_back(tmp);
				}
		}
		SPFA(0);
		if(dis[k] != INF){
			if(dis[k]==0) dis[k]+=60;
			printf("%d\n",dis[k]-60);
		}
		else	printf("IMPOSSIBLE\n");
	}
	return 0;
}
