#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

#define maxx 100000

using namespace std;

struct node{
	double x,y;
}p[maxx],stack[maxx];

double cross(node o,node a,node b){
	return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
bool cmp(node a,node b){
	return (a.x<b.x || (a.x==b.x && a.y<b.y));
}
double dis(node a,node b){
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
int main()
{
	int n,m,top;
	int test=1;
	double ans;
	while(scanf("%d",&n) && n){
		if(test>1)	printf("\n");
		for(int i=0;i<n;i++)
			scanf("%lf %lf",&p[i].x,&p[i].y);
		m=0,ans=0,top=0;
		sort(p,p+n,cmp);
		for(int i=0;i<n;i++){
			while(top>1 && cross(stack[top-2],stack[top-1],p[i])<=0)
				top--;
			stack[top++]=p[i];
		}
		for(int i=n-2,k=top+1;i>=0;i--){
			while(top>=k && cross(stack[top-2],stack[top-1],p[i])<=0)
				top--;
			stack[top++]=p[i];
		}
		for(int i=1;i<top;i++)
			ans+=dis(stack[i],stack[i-1]);
		printf("Region #%d:\n",test++);
		for(int i=top-1;i>=0;i--){
			printf("(%.1lf,%.1lf)",stack[i].x,stack[i].y);
			if(i)	printf("-");
		}
		printf("\nPerimeter length = %.2lf\n",ans);
	}
	return 0;
}
