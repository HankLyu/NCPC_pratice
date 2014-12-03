#include<iostream>
#include<cstdio>
#include<cstring>

#define INF 200000000
#define max 16

using namespace std;

int edge[max][max];
int dp[1<<max];
bool count[max]; //奇數點

int f(bit)
{
	if(dp[bit] != 0)
		return dp[i];
	
}

int main()
{
	int n,m;
	while(scanf("%d",&n) != EOF && n){
		scanf("%d",&m);
		int ans,a,b,c;
		memset(dp,0,sizeof(dp));
		memset(count,0,sizeof(count));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				edge[i][j]=INF;
		for(int i=0;i<m;i++){
			scanf("%d %d %d",&a,&b,&c);
			if(edge[a-1][b-1]>c)
				edge[a-1][b-1]=c;
		}
		for(int i=0;i<n;i++){		//找出哪些是基點
			int docount=0;
			for(int j=0;j<n;j++)
				if(edge[i][j]<INF){
					docount++;
					ans=ans+edge[i][j];
				}
			if(docount%2==1)
				count[i]=1;
		}
		int anscount=0;
		for(int i=1;i<=n;i++)
			if(count[i]==1){
				anscount+=1<<i;
			}
		ans+=f(anscount);
		printf("%d\n",ans);
	}
	return 0;
}
