#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

#define maxx 1005

using namespace std;

struct node{
	int x,y;
}p[maxx],stack[maxx];;
int n,m,x,y;

double cross(node o,node a,node b){
	return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
bool cmp(node a,node b){
	return (a.x<b.x || (a.x==b.x && a.y<b.y));
}
double dis(node a,node b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
	while(scanf("%d %d",&n,&m)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d %d",&p[i].x,&p[i].y);
		}
		sort(p,p+n,cmp);
		int top=0;
		for(int i=0;i<n;i++){
			while(top>1 && 
				cross(stack[top-2],stack[top-1],p[i])<=0)	top--;
			stack[top++]=p[i];
		}
		for(int i=n-2,k=top+1;i>=0;i--){
			while(top>=k && cross(stack[top-2],stack[top-1],p[i])<=0)
				top--;
			stack[top++]=p[i];
		}
		double ans=0;
		for(int i=1;i<top;i++){
			ans+=dis(stack[i],stack[i-1]);
		}
		ans+=2*acos(-1.0)*m;
		printf("%.0f\n",ans);
	}
	return 0;
}
