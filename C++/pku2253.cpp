#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>

#define maxx 205
#define INF 1000000000

using namespace std;

struct stone
{
	int x,y;
};
double w[maxx][maxx],d[maxx];
stone s[maxx];
int n,parent[maxx];
bool visit[maxx];

double dis(int a,int b)
{
	//printf("%d %d\n",a,b);
	return sqrt( (s[a].x-s[b].x)*(s[a].x-s[b].x)
		+(s[a].y-s[b].y)*(s[a].y-s[b].y));
}
void prim()
{
	memset(visit,false,sizeof(visit));
	for(int i=0;i<n;i++)	d[i]=INF;
	d[0]=0;
	for(int i=0;i<n;i++){
		int mind=INF,mink;
		for(int j=0;j<n;j++)
			if(!visit[j] && mind>d[j]){
				mind=d[j];
				mink=j;
			}
		visit[mink]=1;
		for(int j=0;j<n;j++){
			if(d[j]>max(d[mink],dis(mink,j)))
				d[j]=max(d[mink],dis(mink,j));
		}
	}
}
int main()
{
	int test=1;
	while(scanf("%d",&n) != EOF && n){
		for(int i=0;i<n;i++)
			scanf("%d %d",&s[i].x,&s[i].y);
		memset(parent,-1,sizeof(parent));
		for(int i=0;i<n;i++)
			d[i]=INF;
		prim();
		printf("Scenario #%d\n",test++);
		printf("Frog Distance = %.3lf\n\n",d[1]);
	}
	return 0;
}
