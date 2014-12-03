//UVa 10004
#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 205
using namespace std;
int y,n,m,color[MAXN];
bool node[MAXN][MAXN];
bool v[MAXN];
void dfs(int x,int count)
{
    v[x]=true;
    color[x]=count;
    for(int i=0;i<n;++i)
    {
        bool next=node[x][i];
        if(next)
        {
            if(v[i])
            {
                if(v[i]&&(color[x]^color[i])%2==0)
                {
                    y=1;
                    return;
                }
            }
            else
                dfs(i,count+1);
        }
        if(y==1) return;
    }
}
int main()
{
    int a,b,i,j;
    while(scanf("%d",&n),n)
    {
        memset(v,0,sizeof(v));
        memset(color,0,sizeof(color));
        memset(node,0,sizeof(node));
        scanf("%d",&m);
        y=0;
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            node[a][b]=true;
            node[b][a]=true;
        }
        if(n<=m) y=1;
        if(y==1)
        {
            y=0;
            dfs(0,1);
        }
        if(y==1) printf("NOT BICOLORABLE.\n");
        else printf("BICOLORABLE.\n");
    }
    return 0;
}
