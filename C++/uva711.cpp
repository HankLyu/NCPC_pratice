#include<iostream>
#include<cstdio>
#include<cstring>

#define maxx 60005

using namespace std;

int cnt[6];
int dp[maxx];

bool rec(int amount,int index)
{
	if(index==6 || amount<0)	return 0;
	if(dp[amount]!=-1)	return dp[amount];

	int ret=0;
	for(int i=0;i<=cnt[index];i++){
		ret=ret | rec(amount-(index+1*i),index+1);
		if(ret)	break;
	}
	dp[amount]=ret;
	return dp[amount];
}
int main()
{
	int test=0;
	while(1){
		int sum=0,check=0;
		for(int i=0;i<6;i++){
			scanf("%d",&cnt[i]);
			if(cnt[i])	check=1;
			sum +=cnt[i]*(i+1);
		}
		if(check==0)	break;
		memset(dp,-1,sizeof(dp));
		dp[0]=1;
		printf("Collection #%d\n",test++);
		if(sum%2){
			printf("Can't be divided.\n\n");
			continue;
		}
		
		if(rec(sum/2,0) )		printf("Can be divided.\n\n");
		else				printf("can't be divided.\n\n");
	}
	return 0;
}
