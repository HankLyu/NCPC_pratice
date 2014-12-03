//PKU 1724
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#define INF 1000000000
#define MAXN 102
using namespace std;

typedef struct EDGE_INFO{
	int t,w,c,d;

}EDGE;
struct NODE
{
    int d,id,c;
    bool operator<(const NODE& t)const
	{
	    if(d==t.d) return c>t.c;
	    return d>t.d;
	}
}TMP;
priority_queue<NODE> v;
vector<EDGE> edge[MAXN];
EDGE tmp;
int M,W,dis[MAXN];
int S,D,L,T,K,N,R;
int DD[MAXN];
int Dijkstra(int start){
	int nowv,nowd,nowc,nextv,i,cost[MAXN];
	for(i = 0; i < MAXN; ++i){
		dis[i] = INF;
	}
	TMP.id=start,TMP.d=0,TMP.c=0;
	v.push(TMP);
	dis[start] = 0;
	while(!v.empty())
	{
		TMP = v.top();
		nowv=TMP.id,nowd=TMP.d,nowc=TMP.c;
		dis[nowv]=nowd;
		if(nowv==N) return dis[N];
		v.pop();
		for(i = 0; i < (int)edge[nowv].size(); ++i)
		{
			nextv = edge[nowv][i].t;
			if(nowc+edge[nowv][i].c <=K)
			{
                TMP.id=nextv,TMP.d=nowd+edge[nowv][i].w,TMP.c=nowc+edge[nowv][i].c;
                v.push(TMP);
			}
		}
	}
    if(dis[N]==INF) return -1;
    else return dis[N];
}

int main()
{
    int i;
    scanf("%d%d%d",&K,&N,&R);
    for(i = 0; i < MAXN; ++i)
			edge[i].clear();
    for(i=0;i<R;++i)
    {
        scanf("%d%d%d%d",&S,&D,&L,&T);
        tmp.t=D;
        tmp.w=L;
        tmp.c=T;
        edge[S].push_back(tmp);
    }
    printf("%d\n",Dijkstra(1));
    return 0;
}
