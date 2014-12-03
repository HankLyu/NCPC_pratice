#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

#define maxx 5005

using namespace std;

int ch[maxx];
int dp[maxx][maxx];

int main()
{
	int test;
	scanf("%d",&test);
	int k,n;
	while(test--){
		scanf("%d %d",&k,&n);
		for(int i=n-1;i>=0;i--)	scanf("%d",&ch[i]);
		//let z dont influence
		k+=8;
		memset(dp,0x7f,sizeof(dp));
		for(int i=0;i<n;i++)	dp[0][i]=0;
		for(int i=1;i<=k;i++)
			for(int j=i*3-1;j<n;j++){
				dp[i][j]=dp[i][j-1]; //don't use cp[j]
				dp[i][j]=min(dp[i][j],
					dp[i-1][j-2]+(ch[j]-ch[j-1])*(ch[j]-ch[j-1]));
			}
		printf("%d\n",dp[k][n-1]);
	}
	return 0;
}
