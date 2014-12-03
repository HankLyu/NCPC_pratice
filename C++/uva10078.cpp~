#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

#define maxx 55

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
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF && n){
		for(int i=0;i<n;i++)
			scanf("%lf %lf",&p[i].x,&p[i].y);
		sort(p,p+n,cmp);
		int top=0;
		for(int i=0;i<n;i++){
			while(top>1 && cross(s[top-2],s[top-1],p[i])<=0)	top--;
			s[top++]=p[i];
		}
		for(int i=n-2,k=top+1;i>=0;i--){
			while(top>=k && cross(s[top-2],s[top-1],p[i])<=0)	top--;
			s[top++]=p[i];
		}
		if(top-1 != n)	printf("Yes\n");
		else	printf("No\n");
	}
	return 0;
}
