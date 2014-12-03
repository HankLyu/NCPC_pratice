#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

#define INF 10000
using namespace std;

struct node{
	double x,y;
};

double dis(node a,node b){
	return sqrt(pow(a.x-b.x,2)+
				pow(a.y-b.y,2));
}
bool cmp(node a,node b){
	return a.x<b.x;
}
int main()
{
	int n;
	double ans;
	node p[INF];
	while(scanf("%d",&n) && n){
		for(int i=0;i<n;i++)
			scanf("%lf %lf",&p[i].x,&p[i].y);
		ans=INF;
		sort(p,p+n,cmp);
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n && (p[j].x-p[i].x<=ans);j++)
				ans=min(ans,dis(p[i],p[j]));
		if(ans==INF)	printf("INFINITY\n");
		else			printf("%.4lf\n",ans);
	}
	return 0;
}
