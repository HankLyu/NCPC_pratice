#include<iostream>
#include<cstdio>
#include<cstring>

#define maxx 50005

using namespace std;

bool dp[maxx];
int coin[105];
int n,sum;

int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		scanf("%d",&n);
		sum=0;
		for(int i=0;i<n;i++){
			scanf("%d",&coin[i]);
			sum+=coin[i];
		}
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int i=0;i<n;i++)
			for(int j=sum;j>=coin[i];j--)
				if(!dp[j])	dp[j]=dp[j-coin[i]];
		//for(int i=0;i<=sum;i++)
		//	printf("i=%d dp=%d\n",i,dp[i]);
		for(int i=sum/2;i>=0;i--)
			if(dp[i]){
				printf("%d\n",sum-i-i);
				break;
			}
	}
	return 0;
}
