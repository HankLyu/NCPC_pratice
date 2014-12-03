#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

#define maxx 105

using namespace std;

struct node
{
	double x,y;	
	bool operator<(const node& a)const{
		return x>a.x;
	}
}p[maxx];
double dis(int i,int j)
{
	return sqrt(pow(p[i].x-p[j].x,2)+pow(p[i].y-p[j].y,2));
}
int n;

int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%lf %lf",&p[i].x,&p[i].y);
		sort(p,p+n);
		double y=0,ans=0,tmp;
		//for(int i=0;i<n;i++)
		//	printf("%lf %lf\n",p[i].x,p[i].y);
		for(int i=0;i<n;i++){
			if(p[i].y>y){
				ans+=dis(i,i-1)*(p[i].y-y)/(p[i].y-p[i-1].y);
				//ans+=tmp;
				//printf("tmp=%lf %lf %lf\n",tmp,dis(i,i-1),
				//		(p[i].y-y)/p[i].y);
				y=p[i].y;
			}
		}
		//for(int i=0;i<n;i++)
		//	printf("%lf %lf\n",p[i].x,p[i].y);
		printf("%.2lf\n",ans);
	}
}
