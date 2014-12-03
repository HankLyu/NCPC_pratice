#include <iostream>
#include <cmath>
#define MAXN 16000001
using namespace std;
bool hash[MAXN]={false};
int w[128];
char c[1000000];
int main()
{
    int N,NC,i,j,p,k,cnt,q,l;
    scanf("%d%d",&N,&NC);
    scanf("%s",c);
    cnt=0;
    l=strlen(c);
    p=NC;
    q=int(pow(p,(double)N));
    k=0;
    int x=int(pow(p,N-1.0)),a=-1;
    memset(w,-1,sizeof(w));
    for(i=0;i<l;++i)
        if(w[int(c[i])]==-1)
            w[int(c[i])]=++a;
    for(i=0;i<=l-N;++i)
    {
        if(i==0)
        {
            for(j=0;j<N;++j)
            {
                k*=p;
                k+=w[int(c[j])];
            }
            k%=q;
            hash[k]=true;
            ++cnt;
        }
        else
        {
            k-=w[int(c[i-1])]*x;
            k*=p;
            k+=w[int(c[i+N-1])];
            k%=q;
            if(!hash[k])
            {
                cnt++;
                hash[k]=true;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
