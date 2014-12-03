#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

#define maxstation 105
#define fullgas 205
#define INF 2e9

using namespace std;

struct node{
	int w,p;
}sta[maxstation];
int dp[maxstation][fullgas];
int dis,n;

int main()
{
	int test;
	char s[100];
	scanf("%d",&test);
	gets(s);
	gets(s);
	while(test--){
		n=1;
		scanf("%d",&dis);
		gets(s);
		while(gets(s) && s[0]!='\0'){
			sscanf(s,"%d %d",&sta[n].w,&sta[n].p);
			n++;
		}
		sta[n].w=dis;
		sta[0].w=0;
		for(int i=0;i<=n;i++)
			for(int j=0;j<fullgas;j++)
				dp[i][j]=INF;
		dp[0][100]=0;
		for(int i=1;i<=n;i++){
			for(int j=sta[i].w-sta[i-1].w;j<201;j++)
				dp[i][j-(sta[i].w-sta[i-1].w)]=dp[i-1][j];
			if(i<n)
				for(int j=1;j<201;j++)
					dp[i][j]=min(dp[i][j],dp[i][j-1]+sta[i].p);
		}
		int ans=dp[n][100];
		//for(int i=100;i<201;i++)
		//	printf("%d\n",dp[n][i]);
		for(int j=101;j<201;j++)
			ans=min(ans,dp[n][j]);
		if(ans==INF)	printf("Impossible\n");
		else	printf("%d\n",ans);
		if(test)	printf("\n");
	}
	return 0;
}
