#include<iostream>
#include<cstdio>
#include<cstring>

#define maxx 15

using namespace std;

int main()
{
	int first=0,n;
	int dp[maxx*2];
	memset(dp,0,sizeof(dp));
	dp[0]=dp[1]=1;
	dp[2]=2;
	for(int i=3;i<maxx;i++){
		for(int j=0;j<i;j++)
			dp[i] += (dp[j]*dp[i-j-1]);
	}
	while(scanf("%d",&n)!=EOF){
		if(first)	printf("\n");
		else		first++;
		printf("%d\n",dp[n]);
	}
	return 0;
}
