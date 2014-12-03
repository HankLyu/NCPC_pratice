#include<iostream>
#include<cstdio>
#include<cstring>

#define inf 20000000000 
using namespace std;

int len[110],m,n;
int path[11][110],ar[11][110];
long long int dp[11][110];
bool use[11][110];

long long int lcs(int n1,int n2)
{
	if(n2==0){
		use[n1][n2]=true;
		dp[n1][n2]=ar[n1][n2];
		return dp[n1][n2];
	}
	if(use[n1][n2]==true)
		return dp[n1][n2];
	int a,b,c;
	
	if(n1>0)	a=n1-1;
	else	a=m-1;
	
	b=n1;
	
	if(n1<m-1)	c=n1+1;
	else	c=0;
	
	long long int t1=lcs(a,n2-1),t2=lcs(b,n2-1),t3=lcs(c,n2-1);
	if(c==0){//in botton line
		dp[n1][n2]=t3,path[n1][n2]=3;
		if(t1<dp[n1][n2])
			dp[n1][n2]=t1,path[n1][n2]=1;
		if(t2<dp[n1][n2])
			dp[n1][n2]=t2,path[n1][n2]=2;
	}
	else if(a==m-1){//int top line
		dp[n1][n2]=t2,path[n1][n2]=2;
		if(t3<dp[n1][n2])
			dp[n1][n2]=t3,path[n1][n2]=3;
		if(t1<dp[n1][n2])
			dp[n1][n2]=t1,path[n1][n2]=1;
	}
	else{
		dp[n1][n2]=t1,path[n1][n2]=1;
		if(t2<dp[n1][n2])
			dp[n1][n2]=t2,path[n1][n2]=2;
		if(t3<dp[n1][n2])
			dp[n1][n2]=t3,path[n1][n2]=3;
	}
	dp[n1][n2] += ar[n1][n2];
	use[n1][n2]=1;
	return dp[n1][n2];
}
void find_lcs(int ansm,int n)
{
	if(n<0)	return;
	len[n]=ansm;
	if(path[ansm][n]==1){
		if(ansm>0)
			find_lcs(ansm-1,n-1);
		else
			find_lcs(m-1,n-1);
	}
	else if(path[ansm][n]==2)
		find_lcs(ansm,n-1);
	else if(path[ansm][n]==3){
		if(ansm<m-1)
			find_lcs(ansm+1,n-1);
		else
			find_lcs(0,n-1);
	}
}
int main()
{
	while(scanf("%d %d",&m,&n)!=EOF){
		long long int ans=inf;
		int ansm;
		memset(path,0,sizeof(path));
		memset(dp,0,sizeof(dp));
		memset(use,0,sizeof(use));
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&ar[i][j]);
				
		for(int i=0;i<m;i++)
			len[i]=lcs(i,n-1);
		/*
		printf("dp:\n");
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++)
				printf("%2lld ",dp[i][j]);
			printf("\n");
		}
		printf("path\n");
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++)
				printf("%2d ",path[i][j]);
			printf("\n");
		}
			*/
		for(int i=0;i<m;i++)
			if(ans>dp[i][n-1])
				ans=dp[i][n-1],ansm=i;
		find_lcs(ansm,n-1);
		for(int i=0;i<n;i++){
			printf("%d",len[i]+1);
			if(i!=n-1)
				printf(" ");
		}
		printf("\n%lld\n",ans);
	}
	return 0;
}
