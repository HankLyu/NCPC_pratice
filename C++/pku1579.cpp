#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int n,ar[105][105],dp[105][105][105][105];
bool cnt[105][105][105][105];

int sum(int a,int b,int c,int d)
{
	if(a==b && c==d){
		dp[a][b][c][d]=ar[a][c];
		cnt[a][b][c][d]=1;
		return dp[a][b][c][d];
	}
	if(cnt[a][b][c][d])	return dp[a][b][c][d];
	int small[4]={0};
	//r-1
	if(a<b){
		small[0]=sum(a+1,b,c,d);
		for(int i=c;i<=d;i++)
			small[0]=small[0]+ar[i][a];
		small[1]=sum(a,b-1,c,d);
		for(int i=c;i<=d;i++)
			small[1]=small[1]+ar[i][b];
	}
	if(c<d){
		small[2]=sum(a,b,c+1,d);
		for(int i=a;i<=b;i++)
			small[2]=small[2]+ar[c][i];
		small[3]=sum(a,b,c,d-1);
		for(int i=a;i<=b;i++)
			small[3]=small[3]+ar[d][i];
	}
	int max=0;
	for(int i=0;i<4;i++)
		if(max<small[i])	max=small[i];
	dp[a][b][c][d]=max;
	cnt[a][b][c][d]=1;
	return dp[a][b][c][d];
}
int main()
{
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n*n;i++)
			scanf("%d",&ar[i/n][i%n]);
		memset(dp,0,sizeof(dp));
		memset(cnt,0,sizeof(cnt));
		sum(0,n,0,n);
		printf("%d\n",dp[0][n-1][0][n-1]);
	}
	return 0;
}
