#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

#define maxx 1005

using namespace std;

int dp[maxx][maxx];
bool barrier[maxx][maxx];
int w,n;

int doans(int n,int w)
{
	//printf("%d %d\n",n,w);
	if(dp[n][w]>0)	{
		//printf("do");
		return dp[n][w];
	}
	if(w>1 && !barrier[n][w-1])
		dp[n][w]+=doans(n,w-1);
	if(n>1 && !barrier[n-1][w])
		dp[n][w]+=doans(n-1,w);
	//printf("n=%d w=%d dp=%d\n",n,w,dp[n][w]);
	return dp[n][w];
}
int main()
{
	int test,bar[maxx];
	char s[maxx],*p;
	scanf("%d",&test);
	while(test--){
		scanf("%d %d",&n,&w);
		memset(barrier,0,sizeof(barrier));
		gets(s);
		for(int i=1;i<=n;i++){
			gets(s);
			int m=0;
			for(p=strtok(s," ");p!=NULL;p=strtok(NULL," "))
				bar[m++]=atoi(p);
			//printf("b[0]=%d m=%d\n",bar[0],m);
			for(int i=1;i<m;i++)
				barrier[bar[0]][bar[i]]=1;
		}
		barrier[1][1]=0;
		memset(dp,0,sizeof(dp));
		dp[1][1]=1;
		doans(n,w);
		/*for(int i=1;i<=n;i++){
			for(int j=1;j<=w;j++)
				printf("%2d",barrier[i][j]);
			printf("\n");
		}*/
		printf("%d\n",doans(n,w));
		if(test)	printf("\n");
	}
	return 0;
}
