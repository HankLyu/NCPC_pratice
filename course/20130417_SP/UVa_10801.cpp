#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXN 105
#define MAXL 1000
#define INF 1000000000
using namespace std;
struct EDGE
{
	int t,w;
}tmp;
vector<EDGE>edge[MAXN];
int N,K,dis[MAXN];
bool SPFA(int start)
{
	queue<int>v;
	int count[MAXN],nowv,nextv;
	bool inqueue[MAXN];

	memset(count,0,sizeof(count));
	memset(inqueue,0,sizeof(inqueue));
	for(int i=0;i<MAXN;++i)
		dis[i]=INF;
	v.push(start);
	inqueue[start]=true;
	count[start]=1;
	dis[start]=0;

	while(!v.empty())
	{
		nowv=v.front();
		v.pop();
		inqueue[nowv]=false;
		for(int i=0;i<(int)edge[nowv].size();++i)
		{
			nextv=edge[nowv][i].t;
			if(dis[nowv]+edge[nowv][i].w<dis[nextv])
			{
				dis[nextv]=dis[nowv]+edge[nowv][i].w;
				if(!inqueue[nextv])
				{
					v.push(nextv);
					inqueue[nextv]=true;
					++count[nextv];
				}
				if(count[nextv]>=N)
					return true;
			}
		}
	}
	return false;
}
void ini()
{
    for(int i=0;i<MAXN;++i)
        edge[i].clear();
}
int main()
{
    int T[MAXN],a[MAXL],m;
    char input[MAXL],*p;
	while(scanf("%d%d",&N,&K)==2)
	{
        for(int i=1;i<=N;++i)
            scanf("%d",&T[i]);
        getchar();
        ini();
        for(int i=1;i<=N;++i)
        {
            gets(input);
            int m=0;
            for ( p=strtok( input," "); p!=NULL; p = strtok ( NULL, " " ) )
                a[m++] = atoi ( p );
            for(int j=1;j<m;++j)
            {
                for(int k=0;k<j;++k)
                {
                    int cost=T[i]*(a[j]-a[k])+60;
                    tmp.t = a[j], tmp.w = cost;
			        edge[a[k]].push_back(tmp);
			        tmp.t = a[k], tmp.w = cost;
			        edge[a[j]].push_back(tmp);
                }
            }
        }
        SPFA(0);
        if(dis[K]!=INF)
        {
            if(dis[K]==0) dis[K]+=60;
            printf("%d\n",dis[K]-60);
        }
        else printf("IMPOSSIBLE\n");
    }
	return 0;
}
