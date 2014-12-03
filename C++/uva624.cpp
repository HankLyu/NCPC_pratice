#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>

#define maxx 10000

using namespace std;

int dp[maxx],pre[maxx];
int coin[maxx],song,sum;
vector<int>ans;

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		scanf("%d",&song);
		sum=0;
		ans.clear();
		memset(coin,0,sizeof(coin));
		memset(dp,0,sizeof(dp));
		memset(pre,-1,sizeof(pre));
		for(int i=0;i<song;i++){
			scanf("%d",&coin[i]);
			sum+=coin[i];
		}
		dp[0]=1;
		for(int i=0;i<song;i++)
			for(int j=sum;j>=coin[i];j--){
				if(!dp[j]){
					dp[j]=dp[j-coin[i]];
					pre[j]=j-coin[i];
				}
			}
		while(!dp[n])	n--;
		/*for(int i=0;i<=n;i++)
			printf("%3d",i);
		printf("\n");
		for(int i=0;i<=n;i++)
			printf("%3d",dp[i]);
		printf("\n");
		for(int i=0;i<=n;i++)
			printf("%3d",pre[i]);
		printf("\n");
		*/int tmp=n;
		while(pre[tmp]!=-1){
			ans.push_back(tmp-pre[tmp]);
			tmp=pre[tmp];
		}
		for(int j=ans.size()-1;j>=0;j--)
			printf("%d ",ans[j]);
		printf("sum:%d\n",n);
	}
	return 0;
}
