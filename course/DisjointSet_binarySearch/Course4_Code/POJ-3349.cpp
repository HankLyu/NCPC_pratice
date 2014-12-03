//PKU 3349
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#define MAXN 100005
#define MAXL 60
using namespace std;
char in[MAXL];
struct SNOW
{
	int S[6],hv;
	bool operator<(const SNOW& t)const
	{
	    return hv<t.hv;
	}
}snow[MAXN];
int hash_value(int in[])
{
    int t1,t2,t3;
    t1 = in[0] & in[3];
    t2 = in[1] & in[4];
    t3 = in[2] & in[5];
    return t1^t2^t3;
}
bool same(int a[],int b[])
{
    for(int i=0;i<6;++i)
        if(a[i]!=b[i])
            return false;
    return true;
}
bool check(int a,int b)
{
    int tmp[6],n;
    for(int i=0;i<6;++i)
    {
        n=0;
        for(int j=i;j!=(i+5)%6;j=(j+1)%6)
            tmp[n++]=snow[b].S[j];
        tmp[n]=snow[b].S[(i+5)%6];
        if(same(tmp,snow[a].S)) return true;
        reverse(tmp,tmp+6);
        if(same(tmp,snow[a].S)) return true;
    }
    return false;
}
int main()
{
	int n,i,j,k;
	bool Y;
	while(scanf("%d",&n)==1)
	{
	    Y=0;
	    //getchar();
		for(i=0;i<n;++i)
		{
			for(j=0;j<6;++j)
                scanf("%d",&snow[i].S[j]);
		    /*gets(in);
            sscanf(in,"%d%d%d%d%d%d",&snow[i].S[0],&snow[i].S[1],&snow[i].S[2]
                   ,&snow[i].S[3],&snow[i].S[4],&snow[i].S[5]);*/
            snow[i].hv=hash_value(snow[i].S);
		}
		sort(snow,snow+n);
		bool isfind=0;
		for(i=0;i<n;++i)
		{
		    for(j=i+1;j<n;++j)
		    {
		        if(snow[i].hv!=snow[j].hv) break;
		        if(check(i,j)) isfind=1;
		        if(isfind) break;
		    }
		    if(isfind) break;
		}
		if(!isfind) printf("No two snowflakes are alike.\n");
		else printf("Twin snowflakes found.\n");
	}
	return 0;
}
