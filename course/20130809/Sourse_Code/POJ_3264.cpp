#include <iostream>
#define MAX 50005
using namespace std;
int n,q,d[MAX];
typedef struct NODE
{
    int hcost,lcost;
}node;
node tree[MAX*3];
void creat_MAX(int id,int l,int r)
{
    if(l==r) 
    {
        tree[id].hcost=d[l];
        return;
    }
    int m=(l+r)/2;
    creat_MAX(id*2,l,m);
    creat_MAX(id*2+1,m+1,r);
    tree[id].hcost=max(tree[id*2].hcost,tree[id*2+1].hcost);
}
void creat_MIN(int id,int l,int r)
{
    if(l==r) 
    {
        tree[id].lcost=d[l];
        return;
    }
    int m=(l+r)/2;
    creat_MIN(id*2,l,m);
    creat_MIN(id*2+1,m+1,r);
    tree[id].lcost=min(tree[id*2].lcost,tree[id*2+1].lcost);
}
int find_MAX(int id,int nl,int nr,int l,int r)
{
    if(l>nr||r<nl) return 0;
    if(l<=nl&&r>=nr) return tree[id].hcost;
	int lf, rf, mid;
	mid = (nl+nr)/2;
	lf = find_MAX(2*id, nl, mid, l, r);
	rf = find_MAX(2*id+1, mid+1, nr, l, r);
	return max(lf, rf);
}
int find_MIN(int id,int nl,int nr,int l,int r)
{
    if(l>nr||r<nl) return 999999;
    if(l<=nl&&r>=nr) return tree[id].lcost;
	int lf, rf, mid;
	mid = (nl+nr)/2;
	lf = find_MIN(2*id, nl, mid, l, r);
	rf = find_MIN(2*id+1, mid+1, nr, l, r);
	return min(lf, rf);
}
int main()
{
    int i,a,b;
    while(scanf("%d%d",&n,&q)==2)
    {
        for(i=1;i<=n;++i)
            scanf("%d",&d[i]);
        creat_MAX(1,1,n);
        creat_MIN(1,1,n);
        for(i=0;i<q;++i)
        {
            scanf("%d%d",&a,&b);
            printf("%d\n",find_MAX(1,1,n,a,b)-find_MIN(1,1,n,a,b));
        }
    }
    return 0;
}
