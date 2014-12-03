#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAXN 105
#define MAXL 1000
#define INF 1000000000
using namespace std;
int N,K,dis[MAXN];
struct EDGE
{
	int t,w;
}tmp;
struct NODE
{
    int d,id;
    bool operator<(const NODE& t)const
	{
	    return d>t.d;
	}
}TMP;
vector<EDGE>edge[MAXN];
int Dijkstra(int start){
	int nowv,nowd,nextv;
    priority_queue<NODE>pq;
	for(int i = 0; i < MAXN; ++i)
	    dis[i]=INF;
	TMP.id=start,TMP.d=0;
	pq.push(TMP);
	dis[start]=0;
	while(!pq.empty())
	{
		TMP = pq.top();
		nowv=TMP.id,nowd=TMP.d;
		dis[nowv]=nowd;
		if(nowv==K) return nowd;
		pq.pop();
		for(int i=0;i<(int)edge[nowv].size();++i)
		{
			nextv = edge[nowv][i].t;
			if(dis[nowv]+edge[nowv][i].w<dis[nextv])
			{
			    dis[nextv]=dis[nowv]+edge[nowv][i].w;
                TMP.d=dis[nextv];
                TMP.id=nextv;
                pq.push(TMP);
			}
		}
	}
	return -1;
}
void ini()
{
    for(int i=0;i<MAXN;++i)
        edge[i].clear();
}
int main()
{
    int T[MAXN],a[MAXN],m;
    char input[MAXL],*p;
	while(scanf("%d%d",&N,&K)==2)
	{
        ini();
        for(int i=1;i<=N;++i)
            scanf("%d",&T[i]);
        getchar();
        for(int i=1;i<=N;++i)
        {
            gets(input);
            m=0;
            for ( p=strtok( input," "); p!=NULL; p = strtok ( NULL, " " ) )
                a[m++]=atoi(p);
            for(int j=1;j<m;++j)
            {
                for(int k=0;k<j;++k)
                {
                    int cost=T[i]*(a[j]-a[k]);
                    tmp.t = a[j], tmp.w = cost+T[i]*max(a[m-1]-a[k],a[k]-a[0])+5;
			        edge[a[k]].push_back(tmp);
			        tmp.t = a[k], tmp.w = cost+T[i]*max(a[m-1]-a[j],a[j]-a[0])+5;
			        edge[a[j]].push_back(tmp);
                }
            }
        }
        int ans=Dijkstra(0);
        if(ans!=-1)
        {
            if(ans==0) ans+=5;
            printf("%d\n",ans-5);
        }
        else printf("IMPOSSIBLE\n");
    }
	return 0;
}
