#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

#define INF 1000000000.000
#define maxx 800

using namespace std;

struct building
{
	int x,y;
};

double dis(building i,building j)
{
	return sqrt((i.x-j.x)*(i.x-j.x)
		+(i.y-j.y)*(i.y-j.y));
}

int main()
{
	int n,m,visit[maxx];
	double w[maxx][maxx],d[maxx],ans;
	int hasa,hasb;
	building b[maxx];
	while(scanf("%d",&n) != EOF){
		for(int i=1;i<=n;i++)
			scanf("%d %d",&b[i].x,&b[i].y);
		for(int i=1;i<=n;i++)	w[i][i]=INF;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				w[i][j]=w[j][i]=dis(b[i],b[j]);
		scanf("%d",&m);
		for(int i=1;i<=m;i++){
			scanf("%d %d",&hasa,&hasb);
			w[hasa][hasb]=w[hasb][hasa]=0;
		}
		ans=0;
		for(int i=1;i<=n;i++){
			d[i]=w[1][i];
			visit[i]=0;
		}
		visit[1]=1;	d[1]=0;
		for(int i=1;i<=n;i++){
			double min=INF;
			int u=1;
			for(int j=1;j<=n;j++)
				if(!visit[j] && d[j]<min){
					min=d[j];
					u=j;
				}
			visit[u]=1;
			ans +=d[u];
			for(int j=1;j<=n;j++)
				if(!visit[j] && w[u][j] < d[j])
					d[j]=w[u][j];
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}
