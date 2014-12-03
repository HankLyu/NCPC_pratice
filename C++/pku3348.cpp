#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

#define maxx 10005

using namespace std;

struct node{
	double x,y;
}p[maxx],s[maxx];

double cross(node o,node a,node b){
	return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
bool cmp(node a,node b){
	return a.x<b.x || (a.x==b.x && a.y<b.y);
}
double area(node a,node b){
	return a.x*b.y-a.y*b.x;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%lf %lf",&p[i].x,&p[i].y);
		if(n<3)	{
			printf("0\n");
			continue;
		}
		int top=0;
		sort(p,p+n,cmp);
		for(int i=0;i<n;i++){
			while(top>1 && cross(s[top-2],s[top-1],p[i])<0)	top--;
			s[top++]=p[i];
		}
		for(int i=n-2,k=top+1;i>=0;i--){
			while(top>=k && cross(s[top-2],s[top-1],p[i])<0)	top--;
			s[top++]=p[i];
		}
		double a=0;
		//for(int i=0;i<top;i++)
		//	printf("%.lf %.lf\n",s[i].x,s[i].y);
		for(int i=0;i<top-1;i++)
			a+=area(s[i],s[i+1]);
			a/=2;
		printf("%d\n",(int)a/50);
	}
	return 0;
}
