#include <iostream>
#include <queue>
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
int fordFulkerson(int n, int mat[][MAXN], int source, int sink)
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
		    for(next=0; next<n; next++)
		    {
		        if(visited[next])continue;

		        	// Positive direction
		        if(mat[now][next]-flow[now][next]>0)
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
		    if(p[i]>=0) minf = min(minf, mat[p[i]][i]-flow[p[i]][i]);
		    else		minf = min(minf, flow[i][-p[i]]);
		for(i=sink; i!=source; i=abs(p[i]))
		    if(p[i]>=0)	flow[p[i]][i]  += minf;
		    else		flow[i][-p[i]] -= minf;
	}
	for(i=0; i<n; i++)	MAX_FLOW += flow[source][i];
	return MAX_FLOW;
};

int main()
{
    int i, a, b, c, s, t;
    while(scanf("%d %d %d %d", &Vnum, &Enum, &s, &t)==4)
    {
    	/* Initialization */
    	ini();

    	for(i=0; i<Enum; i++)
    	{
    		scanf("%d %d %d", &a, &b, &c);
    		cap[a][b] = c;
    	}
        printf("%d\n", fordFulkerson(Vnum, cap, s, t));
        /* my.flow array store the information of flow */
    }
    return 0;
}
