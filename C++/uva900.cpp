#include<iostream>
#include<cstdio>
#include<cstring>

#define maxx 55

using namespace std;

int main()
{
	long long int dp[maxx]={0};
	int n;
	dp[1]=1;
	dp[2]=2;
	for(int i=3;i<maxx;i++)
		dp[i]=dp[i-1]+dp[i-2];
	while(scanf("%d",&n)!=EOF &&n){
		printf("%lld\n",dp[n]);
	}
	return 0;
}
