#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#define MAXN 16
#define INF 1000000000
using namespace std;
int N,M;
int dis[MAXN];
int sp[MAXN][MAXN];
int dp[1<<MAXN];
int pair_sum;
struct EDGE
{
    int t,w;
}tmp;
vector<EDGE>e[MAXN];
int odd[MAXN];
void ini()
{
    for(int i=0;i<MAXN;++i)
        e[i].clear();
    for(int i=0;i<MAXN;++i)
        for(int j=0;j<MAXN;++j)
            sp[i][j]=INF;
    memset(odd,0,sizeof(odd));
    memset(dp,-1,sizeof(dp));
}
/*void floyd()
{
    for(int k=1;k<=N;++k)
    {
        for(int i=1;i<=N;++i)
        {
            for(int j=1;j<=N;++j)
            {
                if(sp[i][k]!=INF && sp[k][j]!=INF && sp[i][k]+sp[k][j]<sp[i][j])
                    sp[i][j]=sp[i][k]+sp[k][j];
            }
        }
    }
}*/
struct NODE
{
    int d,id;
    bool operator<(const NODE& t)const
	{
	    return d>t.d;
	}
}TMP;
void Dijkstra(int start){
	int nowv,nowd,nextv;
    priority_queue<NODE>pq;
	for(int i = 0; i < MAXN; ++i)
	    dis[i]=INF;
	TMP.id=start,TMP.d=0;
	pq.push(TMP);
	dis[start]=0;
	int cnt=0;
	while(!pq.empty())
	{
		TMP = pq.top();
		cnt++;
		nowv=TMP.id,nowd=TMP.d;
		pq.pop();
		for(int i=0;i<(int)e[nowv].size();++i)
		{
			nextv = e[nowv][i].t;
			if(dis[nowv]+e[nowv][i].w<dis[nextv])
			{
			    dis[nextv]=dis[nowv]+e[nowv][i].w;
                TMP.d=dis[nextv];
                TMP.id=nextv;
                pq.push(TMP);
			}
		}
	}
}
int match(int bit,int num)
{
    if(bit==0) return 0;
    if(dp[bit]!=-1) return dp[bit];
    dp[bit]=INF;
    for(int i=0;i<num;++i)
    {
        if(bit&(1<<i))
        {
            for(int j=i+1;j<num;++j)
            {
                if(bit&(1<<j))
                {
                    int cost=match(bit-(1<<i)-(1<<j),num);
                    dp[bit]=min(dp[bit],cost+sp[odd[i]][odd[j]]);
                }
            }
        }
    }
    return dp[bit];
}
int main()
{
    int a,b,c;
    while(scanf("%d",&N),N)
    {
        scanf("%d",&M);
        ini();
        int len=0;
        for(int i=0;i<M;++i)
        {
            scanf("%d%d%d",&a,&b,&c);
            tmp.t=b,tmp.w=c;
            e[a].push_back(tmp);
            tmp.t=a,tmp.w=c;
            e[b].push_back(tmp);
            //sp[a][b]=min(sp[a][b],c);
            //sp[b][a]=min(sp[b][a],c);
            len+=c;
        }
        //count odd degree point
        int num=0;
        for(int i=1;i<=N;++i)
            if(e[i].size()&1)
                odd[num++]=i;
        //floyd();
        //dijkstra
        for(int i=0;i<num;++i)
        {
            Dijkstra(odd[i]);
            for(int j=0;j<num;++j)
            {
                if(i==j) continue;
                sp[odd[i]][odd[j]]=dis[odd[j]];
            }
        }
        //odd point min cost match
        pair_sum=match((1<<num)-1,num);
        printf("%d\n",len+pair_sum);
    }
    return 0;
}
