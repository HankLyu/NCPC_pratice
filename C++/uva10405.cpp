#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define maxx 1005

using namespace std;

bool use[maxx][maxx];
int dp[maxx][maxx];
char w1[maxx],w2[maxx];

int LCS(int n1,int n2)
{
	if(n1<0 || n2<0)
		return 0;
	if(use[n1][n2]==true)
		return dp[n1][n2];
	if(w1[n1]==w2[n2]){
		dp[n1][n2]=LCS(n1-1,n2-1)+1;
	}
	else{
		int t1=LCS(n1-1,n2);
		int t2=LCS(n1,n2-1);
		if(t1<t2)
			dp[n1][n2]=t2;
		else
			dp[n1][n2]=t1;
	}
	use[n1][n2]=true;
	return dp[n1][n2];
}
int main()
{
	int len;
	while(gets(w1)){
		gets(w2);
		memset(use,0,sizeof(use));
		memset(dp,0,sizeof(use));
		len=LCS(strlen(w1)-1,strlen(w2)-1);
		printf("%d\n",len);
	}
	return 0;
}
