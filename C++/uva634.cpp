#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

#define maxx 1005

using namespace std;

struct point
{
	double x,y;
}p[maxx],input;
int n;

bool point_in_polygon()
{
	bool c=false;
	for(int i=0,j=n-1;i<n;j=i++)
		if( (p[i].y>input.y) != (p[j].y>input.y) &&
			input.x<((p[j].x-p[i].x)*(input.y-p[i].y)/
			(p[j].y-p[i].y)+p[i].x))
			c =!c;
	return c;
}
int main()
{
	while(scanf("%d",&n)!=EOF && n){
		for(int i=0;i<n;i++)
			scanf("%lf %lf",&p[i].x,&p[i].y);
		scanf("%lf %lf",&input.x,&input.y);
		if(point_in_polygon())
			printf("T\n");
		else printf("F\n");
	}
	return 0;
}
