#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

#define maxx 105

using namespace std;

int k,n;
double dp[maxx][10];

int main()
{
	while(scanf("%d %d",&k,&n)!=EOF){
		memset(dp,0,sizeof(dp));
		for(int i=0;i<=k;i++)	dp[1][i]=1;
		for(int i=2;i<=n;i++)
			for(int j=0;j<=k;j++){
				if(j+1<=k)
					dp[i][j]+=dp[i-1][j+1];
				if(j<=k)
					dp[i][j]+=dp[i-1][j];
				if(j>0)
					dp[i][j]+=dp[i-1][j-1];
			}
		double cnt=0;
		for(int i=0;i<=k;i++)
			cnt+=dp[n][i];
		double ans=cnt/pow(k+1,n);
		printf("%.5lf\n",ans*100);
	}
	return 0;
}
