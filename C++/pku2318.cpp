#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

#define maxx 5005

using namespace std;

struct node
{
	double a,b,c;
}line[maxx];

int main()
{
	int n,first=0;
	while(scanf("%d",&n) !=EOF && n){
		if(first)	printf("\n");
		else	first++;
		int ans[maxx]={0};
		int m;
		double x1,y1,x2,y2,xa,xb;
		scanf("%d %lf %lf %lf %lf",&m,&x1,&y1,&x2,&y2);
		for(int i=0;i<n;i++){
			scanf("%lf %lf",&xa,&xb);
			line[i].a=(y1-y2);
			line[i].b=xb-xa;
			line[i].c=line[i].a*xb+line[i].b*y2;
		}
		double x,y;
		bool check=0;
		for(int i=0;i<m;i++){
			scanf("%lf %lf",&x,&y);
			check=0;
			for(int j=0;j<n;j++)
				if(line[j].a*x +line[j].b*y < line[j].c){
					check=1;
					ans[j]++;
					break;
				}
			if(check==0)	ans[n]++;
		}
		for(int i=0;i<=n;i++){
			printf("%d: %d\n",i,ans[i]);
		}
	}
	return 0;
}
