#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;
struct NODE{
    int v;
    bool operator < (const NODE &in) const
    {
	   return v > in.v;		 // max heap, just remember this section of codes
    }
};

int main()
{
    int n,i,a[5001],sum,x,y;
    priority_queue<NODE> pq;
    NODE tmp;
    while(scanf("%d",&n),n)
    {
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            tmp.v=a[i];
            pq.push(tmp);
        }
        while(1)
        {
            tmp=pq.top();
            pq.pop();
            if(pq.empty()) break;
            x=tmp.v;
            tmp=pq.top();
            pq.pop();
            y=tmp.v;
            sum+=(x+y);
            tmp.v=x+y;
            pq.push(tmp);
        }
        printf("%d\n",sum);
    }
    return 0;
}
