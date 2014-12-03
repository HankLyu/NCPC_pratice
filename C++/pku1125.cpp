#include<cstdio>
#include<iostream>
#include<cstring>

#define maxx 105
#define INF 100//000000

using namespace std;

int map[maxx][maxx];
int pre[maxx][maxx];

void floyd_warshall(int n)
{
	for(int i=1;i<=n;i++)	//from 1 to n
		for(int j=1;j<=n;j++){
			//if(i==j)	pre[i][j]=-1;
			//else		
				pre[i][j]=j;
		}
	for(int i=0;i<n;i++)
		map[i][i]=0;
	for(int k=1;k<=n;k++)		//to find the ALL SP
		for(int i=1;i<=n;i++)	//from one to other
			for(int j=1;j<=n;j++)
				if( (map[i][k]+map[k][j]<map[i][j]) ){
					map[i][j]=map[i][k]+map[k][j];
					pre[i][j]=pre[i][k];
				}
	int index=-1;	//index show who cause the fastest spread
	int ans=INF;	//ans show the time spend to spread to all 
	for(int i=1;i<=n;i++){
		int maxtime=-1;
		for(int j=1;j<=n;j++){
			if(maxtime<map[i][j] && i!=j)
				maxtime=map[i][j];
		}
		if(ans>maxtime){
			ans=maxtime;
			index=i;
		}
	}
	if(ans==INF)	printf("disjoint\n");
	else	printf("%d %d\n",index, ans);
}
int main()
{
	int n,lines,end,len;
	while(scanf("%d",&n)!= EOF && n){
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				map[i][j]=INF;
		for(int i=1;i<=n;i++){
			scanf("%d",&lines);
			for(int j=0;j<lines;j++){
				scanf("%d %d",&end,&len);
				map[i][end]=len;
			}
		}
		floyd_warshall(n);
	}
}
