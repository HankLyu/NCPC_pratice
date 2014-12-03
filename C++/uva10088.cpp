#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

#define maxx 1005

using namespace std;

struct node
{
	long long int x,y;
}p[maxx];

long long int gcd(long long int a,long long int b)
{
	if(b==0ll)	return a;
	if(a==0ll)	return b;
	return gcd(b,a%b);
}
long long int cross(node a,node b)
{
	return a.x*b.y-b.x*a.y;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF && n){
		for(int i=0;i<n;i++)
			scanf("%lld %lld",&p[i].x,&p[i].y);
		p[n]=p[0];
		long long int a,b,r,count=0ll;
		for(int i=0;i<n;i++){
			a=abs(p[i+1].x-p[i].x);
			b=abs(p[i+1].y-p[i].y);
			r=gcd(a,b);
			count+=r;
		}
		long long int area=0ll;
		for(int i=0;i<n;i++)
			area+=cross(p[i],p[i+1]);
		area=abs(area)/2ll;
		printf("%lld\n",area+1ll-count/2ll);
	}
	return 0;
}
