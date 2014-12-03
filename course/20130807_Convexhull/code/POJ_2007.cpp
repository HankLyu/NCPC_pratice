#include <iostream>
#include <algorithm>
#define MAXN 51
using namespace std;
int xi,yi;
struct node
{
    int x,y;
    bool operator<(const node& t) const{
        return (xi-x)*(yi-t.y)-(xi-t.x)*(yi-y) > 0;
        // x*t.y - y*t.x
    }
};
node v[MAXN];
int main()
{
    scanf("%d%d",&xi,&yi);
    int n=0,i;
    while(scanf("%d%d",&v[n].x,&v[n].y)==2)
        ++n;
    sort(v,v+n);
    printf("(%d,%d)\n",xi,yi);
    for(i=0;i<n;i++)
        printf("(%d,%d)\n",v[i].x,v[i].y);
    return 0;
}
