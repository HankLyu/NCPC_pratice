#include<iostream>
#include<cstdio>
#include<cstring>

#define maxx 105

using namespace std;

bool use[maxx][maxx];
int dp[maxx][maxx];
int path[maxx][maxx];
int w1[maxx],w2[maxx];

int LCS(int a,int b)
{
	if(a<0 || b<0)
		return 0;
	if(use[a][b]==true)
		return dp[a][b];
	if(w1[a] == w2[b]){
		dp[a][b]=LCS(a-1,b-1)+1;
	}
	else{
		int t1=LCS(a-1,b);
		int t2=LCS(a,b-1);
		if(t1<t2)
			dp[a][b]=t2;
		else
			dp[a][b]=t1;
	}
	use[a][b]=true;
	return dp[a][b];
}
int main()
{
	int a,b,test=1,ans;
	while(scanf("%d %d",&a,&b)!= EOF){
		if(a==0 && b==0)	break;
		memset(w1,0,sizeof(w1));
		memset(w2,0,sizeof(w2));
		memset(use,0,sizeof(use));
		memset(dp,0,sizeof(dp));
		for(int i=0;i<a;i++)
			scanf("%d",&w1[i]);
		for(int i=0;i<b;i++)
			scanf("%d",&w2[i]);
		ans=LCS(a-1,b-1);
		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",test++,ans);
	}
	return 0;
}

