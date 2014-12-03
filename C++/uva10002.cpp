#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define maxx 105

using namespace std;

struct node{
	double x,y;
}p[maxx],st[maxx];
double cross(node o,node a,node b){
	return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
double area(node a,node b){
	return a.x*b.y-a.y*b.x;
}
bool cmp(node a,node b){
	return (a.x<b.x || (a.x==b.x && a.y<b.y));
}
int main()
{
	double ansx,ansy,w;
	int n,top;
	while(scanf("%d",&n) &&n>2){
		ansx=0,ansy=0,w=0;
		top=0;
		for(int i=0;i<n;i++)
			scanf("%lf %lf",&p[i].x,&p[i].y);
		sort(p,p+n,cmp);
		for(int i=0;i<n;i++){
			while(top>1 && cross(st[top-2],st[top-1],p[i])<0)	top--;
			st[top++]=p[i];
		}
		for(int i=n-2,k=top+1;i>=0;i--){
			while(top>=k && cross(st[top-2],st[top-1],p[i])<0)	top--;
			st[top++]=p[i];
		}
		for(int i=top-1,j=0;j<top;i=j++){
			double a=area(st[i],st[j]);
			ansx+=(st[i].x+st[j].x)*a;
			ansy+=(st[i].y+st[j].y)*a;
			w+=a;
		}
		printf("%.3lf %.3lf\n",ansx/3/w,ansy/3/w);
	}
	return 0;
}
