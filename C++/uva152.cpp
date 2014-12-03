#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

#define maxx 5005
#define INF 1000

using namespace std;

struct node
{
	int x,y,z;
}point[maxx];

int dis(int a,int b)
{
	return sqrt(pow(point[a].x-point[b].x,2)+
				pow(point[a].y-point[b].y,2)+
				pow(point[a].z-point[b].z,2));
}
int main()
{
	int n=0,a,b,c;
	int ans[10]={0};
	while(scanf("%d %d %d",&a,&b,&c)!=EOF){
		if(a==0 && b==0 && c==0)	break;
		point[n].x=a;
		point[n].y=b;
		point[n].z=c;
		n++;
	}
	for(int i=0;i<n;i++){
		int d=INF;
		for(int j=0;j<n;j++)
			if(i != j)	d=min(d,dis(i,j));
		if(d<10)	ans[d]++;
	}
	for(int i=0;i<10;i++)
		printf("%4d",ans[i]);
	printf("\n");
	return 0;
}
