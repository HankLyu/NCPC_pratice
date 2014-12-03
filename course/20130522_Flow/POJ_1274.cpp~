/*
PKU 1274 Bipartite Matching
x=1~n y=1~n
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 205
using namespace std;
int nx, ny;             // X的點數目、Y的點數目
int mx[MAXN], my[MAXN];   // X各點的配對對象、Y各點的配對對象
bool vy[MAXN];           // 記錄Graph Traversal拜訪過的點
bool adj[MAXN][MAXN];     // 精簡過的adjacency matrix
int ini_matching()
{
    int cnt=0;
    for (int x=1; x<=nx; ++x)
        if (mx[x] == -1)
            for (int y=1; y<=ny; ++y)
                if (my[y] == -1&&adj[x][y])
                {
                    mx[x] = y; my[y] = x;
                    cnt++;
                    break;
                }
    return cnt;
}
// 以DFS建立一棵交錯樹
bool DFS(int x)
{
    for (int y=1; y<=ny; ++y)
        if (adj[x][y] && !vy[y])
        {
            vy[y] = true;
            // 找到擴充路徑
            if (my[y] == -1 || DFS(my[y]))
            {
                mx[x] = y; my[y] = x;
                return true;
            }
        }
    return false;
}

int bipartite_matching()
{
    // 全部的點初始化為未匹配點。
    memset(mx, -1, sizeof(mx));
    memset(my, -1, sizeof(my));
	int c=ini_matching();  // 能連的先連一連
    // 依序把X中的每一個點作為擴充路徑的端點，並嘗試尋找擴充路徑。
    for (int x=1; x<=nx; ++x)
        if (mx[x] == -1)    // x為未匹配點
        {
            // 開始Graph Traversal
            memset(vy, false, sizeof(vy));
            if (DFS(x)) c++;
        }
    return c;
}

int main()
{
    int i,j,a,N,M,n;
    while(scanf("%d%d",&nx,&ny)==2)
    {
		memset(adj,0,sizeof(adj));
    	for(i=1; i<=nx; i++)
    	{
			scanf("%d",&n);
			for(j=0;j<n;++j)
			{
    			scanf("%d",&a);
    			adj[i][a]=true;
			}
    	}
        printf("%d\n",bipartite_matching());
    }
    return 0;
}
