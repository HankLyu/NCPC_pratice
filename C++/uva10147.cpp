#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

#define maxx 800 
#define INF 10000000000

using namespace std;

struct city
{
	double x,y;
};

double w[maxx][maxx],d[maxx];
int parent[maxx];
bool visit[maxx];
int n,ans;
int prim();
city c[maxx];

double dis(int a,int b)
{
	return sqrt( (c[a].x-c[b].x)*(c[a].x-c[b].x)+
		(c[a].y-c[b].y)*(c[a].y-c[b].y));
}
int main()
{
	int test,nbuild,c1,c2,num;
	scanf("%d",&test);
	while(test--){
		memset(visit,false,sizeof(visit));
		memset(parent,-1,sizeof(parent));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lf %lf",&c[i].x,&c[i].y);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				w[i][j]=w[j][i]=dis(i,j);
		scanf("%d",&nbuild);
		for(int i=0;i<nbuild;i++){
			scanf("%d %d",&c1,&c2);
			w[c1][c2]=w[c2][c1]=0;
		}

		num=0;
		for(int i=0;i<=n;i++)	d[i]=INF;
		d[1]=0;
		for(int i=0;i<n;i++){
			int a=-1;
			double min=INF;
			for(int j=1;j<=n;j++)
				if(!visit[j] && d[j]<min){
					a=j;
					min=d[j];
				}
			if(a==-1)	break;
			visit[a]=true;
			//printf("min=%lf p[%d]=%d\n",min,a,parent[a]);
			if(min>0){
				printf("%d %d\n",a,parent[a]);
				num++;
			}
			for(int j=1;j<=n;j++)
				if(!visit[j] && w[a][j] <d[j]){
					d[j]=w[a][j];
					parent[j]=a;
				}
		}
		if(num==0)	printf("No new highways need\n");
		if(test)	printf("\n");
	}
	return 0;
}
