#include <iostream>
#include <algorithm>
#include <cmath>
#define MAXN 1003
using namespace std;
struct Point {int x,y;} P[MAXN],CH[MAXN];
int cross(const Point& o,const Point& a,const Point& b)
{
	return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
bool compare(const Point& a,const Point& b)
{
	return (a.x<b.x||(a.x==b.x&&a.y<b.y));
}
int main()
{
	int n,i,t,x,y,k,L;
	scanf("%d%d",&n,&L);
	for(i=0;i<n;++i)
		scanf("%d%d",&P[i].x,&P[i].y);
	sort(P,P+n,compare);
	int m=0;
	for(i=0;i<n;++i)
	{
		while(m>=2&&cross(CH[m-2],CH[m-1],P[i])<=0) m--;
		CH[m++]=P[i];
	}
	for(i=n-2,k=m+1;i>=0;--i)
	{
		while(m>=k&&cross(CH[m-2],CH[m-1],P[i])<=0) m--;
		CH[m++]=P[i];
	}
	//cout<<m;
	//m--;
	double ans=0.0;
	for(i=1;i<m;++i)
	{
		ans+=sqrt(double((CH[i].x-CH[i-1].x)*(CH[i].x-CH[i-1].x)
		+(CH[i].y-CH[i-1].y)*(CH[i].y-CH[i-1].y)));
		//cout<<ans<<" ";
	}
	ans+=(double)L*acos(-1.0)*2.0;
	printf("%.lf",ans);
	//system("pause");
	return 0;
}
