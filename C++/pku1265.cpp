#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

#define maxx 105

using namespace std;

struct node{
	double x,y;
}p[maxx];
int n;

double cross(node a,node b){
	return a.x*b.y-a.y*b.x;
}
int gcd(int a,int b){
	if(a==0)	return b;
	return gcd(b%a,a);
}
int main()
{
	int test;
	double a,b;
	scanf("%d",&test);
	for(int t=1;t<=test;t++){
		scanf("%d",&n);
		p[0].x=0,p[0].y=0;
		for(int i=0;i<n;i++){
			scanf("%lf %lf",&a,&b);
			p[i+1].x=p[i].x+a;
			p[i+1].y=p[i].y+b;
		}
		long long int a,b,r,count=0,in;
		for(int i=0;i<n;i++){
			a=abs(p[i+1].x-p[i].x);
			b=abs(p[i+1].y-p[i].y);
			count+=gcd(a,b);
		}
		double area=0;
		for(int i=0;i<n;i++)
			area+=cross(p[i],p[i+1]);
		area=fabs(area)/2;
		in=(int)area+1-count/2;
		printf("Scenario #%d:\n",t);
		printf("%lld %lld %.1lf\n\n",in,count,area);
	}
	return 0;
}
