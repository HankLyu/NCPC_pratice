//UVa 515
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define MAXN 105
#define INF 1000000000
using namespace std;
struct EDGE
{
    int t,w;
}tmp;
vector<EDGE>edge[MAXN];
int dis[MAXN],N;
bool SPFA(int start)
{
    int nextv,nowv,i,cnt[MAXN];
    queue<int>v;
    bool inqueue[MAXN];
    memset(inqueue,0,sizeof(inqueue));
    memset(cnt,0,sizeof(cnt));
    for(i=0;i<MAXN;++i)
    {
        dis[i]=INF;
    }
    v.push(start);
    dis[start]=0;
    inqueue[start]=true;
    cnt[start]++;
    while(!v.empty())
    {
        nowv=v.front();
        v.pop();
        inqueue[nowv]=false;
        for(i=0;i<(int)edge[nowv].size();++i)
        {
            nextv=edge[nowv][i].t;
            if(dis[nowv]+edge[nowv][i].w<dis[nextv])
            {
                dis[nextv]=dis[nowv]+edge[nowv][i].w;
                if(!inqueue[nextv])
                {
                    v.push(nextv);
                    inqueue[nextv]=true;
                    cnt[nextv]++;
                }
                if(cnt[nextv]>N+1) return true;
            }
        }
    }
    /*for(int i=0;i<=N;++i)
        if(dis[i]==INF)
            return false;*/
    return false;
}
void ini()
{
    for(int i=0;i<MAXN;++i)
        edge[i].clear();
}
int main()
{
    int M,s,n,k;
    char o[5];
    while(scanf("%d",&N),N)
    {
        scanf("%d",&M);
        ini();
        for(int i=0;i<M;++i)
        {
            scanf("%d%d%s%d",&s,&n,o,&k);
            if(o[0]=='g')
            {
                tmp.t=s-1;
                tmp.w=-k-1;
                edge[s+n].push_back(tmp);
            }
            else
            {
                tmp.t=s+n;
                tmp.w=k-1;
                edge[s-1].push_back(tmp);
            }
        }
        for(int i=0;i<=N;++i)
        {
            tmp.t=i;
            tmp.w=INF/1000;
            edge[i+1].push_back(tmp);
        }
        if(!SPFA(N+1))
            printf("lamentable kingdom\n");
        else printf("successful conspiracy\n");
    }
    return 0;
}
