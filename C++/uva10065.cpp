#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

#define maxx 105

using namespace std;

struct node{
	double x,y;
}p[maxx],s[maxx];

double cross(node o,node a,node b){
	return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
double area(node a,node b){
	return a.x*b.y-a.y*b.x;
}
bool cmp(node a,node b){
	return a.x<b.x || (a.x==b.x && a.y<b.y);
}
int main()
{
	int n,top,test=1;
	double ap,as;
	while(scanf("%d",&n)!=EOF && n){
		ap=as=0;
		for(int i=0;i<n;i++)
			scanf("%lf %lf",&p[i].x,&p[i].y);
		p[n]=p[0];
		for(int i=0;i<n;i++)	ap+=area(p[i],p[i+1]);
		
		sort(p,p+n,cmp);
		top=0;
		for(int i=0;i<n;i++){
			while(top>1 && cross(s[top-2],s[top-1],p[i])<0)	top--;
			s[top++]=p[i];
		}
		for(int i=n-2,k=top+1;i>=0;i--){
			while(top>=k && cross(s[top-2],s[top-1],p[i])<0)	top--;
			s[top++]=p[i];
		}
		for(int i=0;i<top-1;i++)	as+=area(s[i],s[i+1]);
		ap=fabs(ap)/2;
		as=fabs(as)/2;
		printf("Tile #%d\n",test++);
		printf("Wasted Space = %.2lf %%\n\n",(as-ap)/as*100);
	}
	return 0;
}
