#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#define MAXN 300
#define INF 1000000000
using namespace std;
int Vnum, Enum;
int cap[MAXN][MAXN], flow[MAXN][MAXN];

/* Subroutine: Initialize the capacity graph */
void ini()
{
    memset(cap, 0, sizeof(cap));
    memset(flow, 0, sizeof(flow));
}
/* Find the flow */
int fordFulkerson(int source, int sink)
{
    int i, now, next, MAX_FLOW = 0;
    int p[MAXN], minf; 	        //p is the parent of vertex i.
    bool visited[MAXN];
    queue<int>BFS;              //Find the augmenting path.
    while(1)
    {
        memset(visited, false, sizeof(visited));
        while(!BFS.empty())BFS.pop();
        BFS.push(source), visited[source] = true; //from the source.
        while(!BFS.empty())
        {
            now = BFS.front();
            for(next=1; next<=Vnum; next++)
            {
                if(visited[next])continue;

                // Positive direction
                if(cap[now][next]-flow[now][next]>0)
                {
                    p[next] = now, visited[next] = true;
                    BFS.push(next);
                }
                // Opposite direction
                else if(flow[next][now]>0)
                {
                    p[next] = -now, visited[next] = true;
                    BFS.push(next);
                }
            }
            BFS.pop();
        }
        //If not find the augmenting path.
        if(!visited[sink]) break;
        //Else update the flow.
        for(minf=INF, i=sink; i!=source; i=abs(p[i]))
            if(p[i]>=0) minf = min(minf, cap[p[i]][i]-flow[p[i]][i]);
            else		minf = min(minf, flow[i][-p[i]]);
        for(i=sink; i!=source; i=abs(p[i]))
            if(p[i]>=0)	flow[p[i]][i]  += minf;
            else		flow[i][-p[i]] -= minf;
    }
    for(i=1; i<=Vnum; i++)	MAX_FLOW += flow[source][i];
    return MAX_FLOW;
}
int main()
{
    int i, a, b, c, s, t,Case=0;
    while(scanf("%d",&Vnum),Vnum)
    {
        scanf("%d%d%d",&s,&t,&Enum);
    	ini();
    	for(i=0; i<Enum; i++)
    	{
    		scanf("%d %d %d",&a,&b,&c);
    		cap[a][b]+=c;
    		cap[b][a]+=c;
    	}
        printf("Network %d\nThe bandwidth is %d.\n\n",++Case,fordFulkerson(s,t));
    }
    return 0;
}
