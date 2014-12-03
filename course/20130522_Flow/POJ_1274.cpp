/*
PKU 1274 Bipartite Matching
x=1~n y=1~n
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 205
using namespace std;
int nx, ny;             // X���I�ƥءBY���I�ƥ�
int mx[MAXN], my[MAXN];   // X�U�I���t���H�BY�U�I���t���H
bool vy[MAXN];           // �O��Graph Traversal���X�L���I
bool adj[MAXN][MAXN];     // ��²�L��adjacency matrix
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
// �HDFS�إߤ@�ʥ����
bool DFS(int x)
{
    for (int y=1; y<=ny; ++y)
        if (adj[x][y] && !vy[y])
        {
            vy[y] = true;
            // ����X�R���|
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
    // �������I��l�Ƭ����ǰt�I�C
    memset(mx, -1, sizeof(mx));
    memset(my, -1, sizeof(my));
	int c=ini_matching();  // ��s�����s�@�s
    // �̧ǧ�X�����C�@���I�@���X�R���|�����I�A�ù��մM���X�R���|�C
    for (int x=1; x<=nx; ++x)
        if (mx[x] == -1)    // x�����ǰt�I
        {
            // �}�lGraph Traversal
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
