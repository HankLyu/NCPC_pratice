#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

#define maxx 105

using namespace std;

struct node
{
	double x,y,r;
}point[maxx];
int p[maxx],rank[maxx];
int com[maxx];

double dis(int x,int y)
{
	return sqrt(pow(point[x].x-point[y].x,2)+
				pow(point[x].y-point[y].y,2));
}

int FindSet(int x)
{
	if(x!=p[x])	p[x]=FindSet(p[x]);
	return p[x];
}
void Link(int x,int y)
{
	if(rank[x]>rank[y])	p[y]=x;
	else{
		p[x]=y;
		if(rank[x]==rank[y])	rank[y]++;
	}
}
void Union(int x,int y)
{
	Link(FindSet(x),FindSet(y));
}
int main()
{
	int n;
	double tmp;
	while(scanf("%d",&n) != EOF && n>=0){
		for(int i=0;i<n;i++)
			scanf("%lf %lf %lf",&point[i].x,
				&point[i].y,&point[i].r);
		for(int i=0;i<n;i++)	p[i]=i;
		memset(rank,0,sizeof(rank));
		memset(com,0,sizeof(com));
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++){
				tmp=dis(i,j);
				if(point[i].r+point[j].r>tmp &&
					abs(point[i].r-point[j].r)<tmp)
					Union(i,j);
			}
		for(int i=0;i<n;i++)
			com[FindSet(i)]++;
		int ans=0;
		for(int i=0;i<n;i++)
			ans=max(ans,com[i]);
		if(ans!=1)
			printf("The largest component contains %d rings.\n",ans);
		else	printf("The largest component contains %d ring.\n",ans);
	}
	return 0;
}
