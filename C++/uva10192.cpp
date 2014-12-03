#include<iostream>
#include<cstdio>
#include<cstring>

#define maxx 105

using namespace std;

char w1[maxx],w2[maxx];
int dp[maxx][maxx];
bool use[maxx][maxx];

int LCS(int a,int b)
{
	if(a<0 || b<0)
		return 0;
	if(use[a][b]==true)
		return dp[a][b];
	if(w1[a] == w2[b])
		dp[a][b] = LCS(a-1,b-1) +1;
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
	int test=1;
	while(gets(w1)){
		if(w1[0] == '#')	break;
		gets(w2);
		memset(dp,0,sizeof(dp));
		memset(use,0,sizeof(use));
		//printf("%s\n%s\n",w1,w2);
		printf("Case #%d: you can visit at most %d cities.\n",
			test++,LCS(strlen(w1)-1,strlen(w2)-1) );
	}//while gets
	return 0;
}
