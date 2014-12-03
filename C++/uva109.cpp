#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

#define maxx 100

using namespace std;

struct point{
	double x,y;
};
struct kingdom{
	int n,top;
	point p[maxx],stack[maxx];
}king[maxx];
struct line{
	double a,b,c;
};
double cross(point o,point a,point b){
	return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
bool cmp(point a,point b){
	return (a.x<b.x || (a.x==b.x &&a.y<b.y));
}
double area(point a[],int b){
	double ans=0.0;
	for(int i=0;i<b;i++)
		ans+= a[i].x*a[i+1].y-a[i].y*a[i+1].x;
	return fabs(ans)/2;
}
int main()
{
	int n,kingnum=0,missnum=0;
	memset(king,0,sizeof(king));
	while(scanf("%d",&n)!=EOF && n!=-1){
		for(int i=0;i<n;i++)
			scanf("%lf %lf",&king[kingnum].p[i].x, &king[kingnum].p[i].y);
		king[kingnum].n=n;
		kingnum++;
	}
	point miss[maxx];
	while(scanf("%lf %lf",&miss[missnum].x, &miss[missnum].y)!=EOF){
		missnum++;
	}
	for(int i=0;i<kingnum;i++){
		sort(king[i].p,king[i].p+king[i].n,cmp);
		king[i].p[ king[i].n]=king[i].p[0];
		for(int j=0;j<king[i].n;j++){
			while(king[i].top>1 && cross(king[i].stack[king[i].top-2],
					king[i].stack[king[i].top-1],king[i].p[j])<0)
				king[i].top--;
			king[i].stack[king[i].top++]=king[i].p[j];
		}
		for(int j=king[i].n-2,k=king[i].top+1;j>=0;j--){
			while(king[i].top>=k && cross(king[i].stack[king[i].top-2],
					king[i].stack[king[i].top-1],king[i].p[j])<0)
				king[i].top--;
			king[i].stack[king[i].top++]=king[i].p[j];
		}
	}
	line l;
	int use[maxx]={0};
	bool check;
	double ans=0.0;
	kingdom tmp;
	for(int a=0;a<missnum;a++){
		for(int b=0;b<kingnum;b++){
			check=0;
			tmp=king[b];
			for(int i=0,j=tmp.top-1;i<tmp.top;j=i++)
				if((tmp.stack[i].y>miss[a].y)!=(tmp.stack[j].y>miss[a].y)&&
					miss[a].x<((tmp.stack[j].x-tmp.stack[i].x)*(miss[a].y-
					tmp.stack[i].y)/(tmp.stack[j].y-tmp.stack[i].y)+
					tmp.stack[i].x))
					check =! check;
			if(check && !use[b]){
				use[b]=1;
				ans+=area(tmp.stack,tmp.top);
			}
		}
	}
	printf("%.2lf\n",ans);
	return 0;
}
