#include <iostream>
#include<cstdio>
using namespace std;
#define N 2500
#define inf (1<<25)
struct eage
{
  int a,b,len;
}e[3*N];
int d[N+1],pre[N+1];
bool bellman(int s,int n,int t)
{
    int i,j;bool b;
    for(i=1;i<=n;i++)d[i]=inf;
    d[s]=0;//源设置为0
    for(i=1;i<n;i++)
        {
            b=false;
            for(j=0;j<t;j++)//对于每个集合中元素
                {
                    if(d[e[j].b]>d[e[j].a]+e[j].len)d[e[j].b]=d[e[j].a]+e[j].len,b=true;
                }
            if(!b)break;
        }
    for(i=0;i<t;i++)
        {//如果找到了负环
            if(d[e[i].b]>d[e[i].a]+e[i].len)return true;
        }
    return false;
}
int main()
{
    int n,t,i,tt,tmp,x,y,len,l;
    cin>>tt;
    while(tt--)
        {
        cin>>n>>t>>tmp;
        l=0;
        for(i=0;i<t;i++)
            {//注意这里是无向图
                scanf("%d%d%d",&x,&y,&len);
                e[l].a=x;e[l].b=y;e[l].len=len;
                l++;
                e[l].a=y;e[l].b=x;e[l].len=len;
                l++;
            }
        for(i=0;i<tmp;i++)
            {//注意这里是有向图,边权需要*-1
                scanf("%d%d%d",&x,&y,&len);
                len*=-1;
                e[l].a=x;e[l].b=y;e[l].len=len;
                l++;
            }
        if(bellman(0,n,l))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}

