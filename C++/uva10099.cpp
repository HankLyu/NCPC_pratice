#include<iostream>
#include<cstdio>
#include<cstring>

#define maxx 105

using namespace std;

int w[maxx][maxx];
int n,r;

void floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				w[i][j]=max(w[i][j],min(w[i][k],w[k][j]));
}
int main()
{
	int test=1,start,end,trip;
	while(scanf("%d %d",&n,&r)!=EOF){
		if(n==0 && r==0)	break;
		memset(w,0,sizeof(w));
		for(int i=0;i<r;i++){
			scanf("%d %d %d",&start,&end,&trip);
			w[start][end]=w[end][start]=trip;
		}
		scanf("%d %d %d",&start,&end,&trip);
		floyd();
		w[start][end]--;
		int ans=trip/w[start][end];
		if(trip%w[start][end]!=0)	ans++;
		printf("Scenario #%d\n",test++);
		printf("Minimum Number of Trips = %d\n\n",ans);
	}
	return 0;
}
