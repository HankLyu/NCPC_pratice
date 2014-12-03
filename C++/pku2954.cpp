#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

struct node{
	double x,y;
}p[5];

long long int gcd(long long int a,long long int b){
	if(a==0)	return b;
	return gcd(b%a,a);
}
long long int cross(node a,node b){
	return a.x*b.y-a.y*b.x;
}
int main()
{
	while(scanf("%lf %lf %lf %lf %lf %lf",&p[0].x, &p[0].y, &p[1].x,
			&p[1].y, &p[2].x, &p[2].y)!=EOF){
		if(p[0].x==0 && p[0].y==0 && p[1].x==0 && p[1].y==0 &&
			p[2].x==0 &&p[2].y==0)	break;
		p[3]=p[0];
		long long int a,b,r,count=0;
		for(int i=0;i<3;i++){
			a=p[i+1].x-p[i].x;
			b=p[i+1].y-p[i].y;
			if(a<0)	a=-a;
			if(b<0)	b=-b;
			r=gcd(a,b);
			count+=r;
		}
		long long int area=0;
		for(int i=0;i<3;i++)
			area+=cross(p[i],p[i+1]);
		if(area<0)	area=-area;
		area=area/2;
		printf("%lld\n",area+1-count/2);
	}
}
