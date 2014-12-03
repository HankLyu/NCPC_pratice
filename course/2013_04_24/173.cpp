#include<cstdio>
#include<iostream>

#define MAXN 16
#define INF 1000000000

using namespace std;

int N, adj[MAXN][MAXN], dp[1<<MAXN][MAXN];
bool visited[1<<MAXN][MAXN];

int find(int set , int now)
{
    // basic
    if(set == 1) // 0000...01
        return adj[0][now];

    // visited
    if(visited[set][now] == true)
        return dp[set][now];

    dp[set][now] = INF;

    // Recursion
    for(int i=1;i<N;i++)
    {
        if(set & (1<<i))
        {
            int nset = set - (1<<i);
            dp[set][now] = min(dp[set][now], find(nset, i) + adj[i][now]);
        }
    }

    visited[set][now] = true;
    return dp[set][now];
}

int main()
{
    while(scanf("%d",&N)==1)
    {
        // Input
        for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d", &adj[i][j]);

        // Initialization
        memset(visited, false, sizeof(visited));

        // Top Down DP
        printf("%d\n", find((1<<N) - 1, 0) );
    }
    return 0;
}


