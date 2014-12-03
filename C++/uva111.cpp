#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int num,dp[25][25],ar[25];
int ans[25];
bool use[25][25];

int lcs(int n1,int n2){
	if(n1<0||n2<0)
		return 0;
	if(use[n1][n2]==true)
		return dp[n1][n2];
	if(ar[n1]==ans[n2])
		dp[n1][n2] = lcs(n1-1,n2-1)+1;
	else{
		int t1=lcs(n1-1,n2);
		int t2=lcs(n1,n2-1);
		if(t1 < t2)
			dp[n1][n2]=t2;
		else	dp[n1][n2]=t1;
	}
	use[n1][n2]=1;
	return dp[n1][n2];
}

int main()
{
	scanf("%d",&num);
	int sc[25];
	for(int i=0;i<num;i++)
		scanf("%d",&sc[i]);
	for(int i=0;i<num;i++)
		ans[sc[i]-1]=i+1;
	while(scanf("%d",&sc[0])!=EOF){
		for(int i=1;i<num;i++)
			scanf("%d",&sc[i]);
		for(int i=0;i<num;i++)
			ar[sc[i]-1]=i+1;
		memset(dp,0,sizeof(dp));
		memset(use,0,sizeof(use));
		int max=0;
		printf("%d\n",lcs(num-1,num-1));
	}
	return 0;
}
