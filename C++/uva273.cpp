#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>

#define maxx 15

using namespace std;

struct node
{
	int x1,y1,x2,y2;
}line[maxx];
int n,rank[maxx],parent[maxx];

int cross(int x1,int y1,int x2,int y2)
{
	return x1*y2-x2*y1;
}
bool onsegment(int x1,int y1,int x2,int y2,int x3,int y3)
{
	if(min(x2,x3)<=x1 && x1<=max(x2,x3) &&
		min(y2,y3)<=y1 && y1<=max(y2,y3))
		return true;
	return false;
}
bool check(int j,int i)
{
	int d1,d2,d3,d4;
	d1=cross(line[j].x1-line[i].x1, line[j].y1-line[i].y1,
			 line[i].x2-line[i].x1, line[i].y2-line[i].y1);
	d2=cross(line[j].x2-line[i].x1, line[j].y2-line[i].y1,
			 line[i].x2-line[i].x1, line[i].y2-line[i].y1);
	d3=cross(line[i].x1-line[j].x1, line[i].y1-line[j].y1,
			 line[j].x2-line[j].x1, line[j].y2-line[j].y1);
	d4=cross(line[i].x2-line[j].x1, line[i].y2-line[j].y1,
			 line[j].x2-line[j].x1, line[j].y2-line[j].y1);
	if(d1*d2<0 && d3*d4<0)	return true;
	if(d1==0 && onsegment(line[j].x1, line[j].y1,
			line[i].x1, line[i].y1, line[i].x2, line[i].y2))	return true;
	if(d2==0 && onsegment(line[j].x2, line[j].y2,
			line[i].x1, line[i].y1, line[i].x2, line[i].y2))	return true;
	if(d3==0 && onsegment(line[i].x1, line[i].y1,
			line[j].x1, line[j].y1, line[j].x2, line[j].y2))	return true;
	if(d4==0 && onsegment(line[i].x2, line[i].y2,
			line[j].x1, line[j].y1, line[j].x2, line[j].y2))	return true;
	return false;
}
int FindSet(int x)
{
	if(x!=parent[x])
		parent[x]=FindSet(parent[x]);
	return parent[x];
}
void Link(int x,int y)
{
	if(rank[x]>rank[y])
		parent[y]=x;
	else{
		parent[x]=y;
		if(rank[x]==rank[y])
			rank[y]++;
	}
}
void Union(int x,int y)
{
	Link(FindSet(x),FindSet(y));
}
int main()
{
	int test,a,b;
	scanf("%d",&test);
	while(test--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d %d %d %d",&line[i].x1, &line[i].y1,
								&line[i].x2, &line[i].y2);
		for(int i=1;i<=n;i++)	parent[i]=i;
		memset(rank,0,sizeof(rank));
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if( i!=j && check(i,j))
					Union(i,j);
		while(scanf("%d %d",&a,&b)!=EOF){
			if(a==0 && b==0)	break;
			if(FindSet(a) == FindSet(b))	printf("CONNECTED\n");
			else							printf("NOT CONNECTED\n");
		}
		if(test)	printf("\n");
	}
}
