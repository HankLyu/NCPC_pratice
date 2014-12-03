#include<iostream>
#include<cstdio>
#include<cstring>

#define maxx 1005
#define maxman 105

using namespace std;

struct node
{
	int price,weight;
}p[maxx];
int n,m;
int c[maxx];

int knapsack(int w){
	memset(c,0,sizeof(c));
	for(int i=0;i<n;i++)
		for(int j=w;j-p[i].weight>=0;j--)
			c[j]=max(c[j],c[j-p[i].weight]+p[i].price);
	return c[w];
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d %d",&p[i].price, &p[i].weight);
		scanf("%d",&m);
		int ans=0,w;
		for(int i=0;i<m;i++){
			scanf("%d",&w);
			ans+=knapsack(w);
		}
		printf("%d\n",ans);
	}
	return 0;
}
