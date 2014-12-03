//無限供應湊得某價位
int v[5]={1,5,10,25,50};
int dp[max]={0};
dp[0]=1;
for(int i=0;i<5;i++)
	for(int j=v[i];j<max;j++)
		dp[j] += dp[j-v[i]];
//每coin只提供一個
memset(dp,0,sizeof(dp));
dp[0]=1;
for(int i=0;i<song;i++)
	for(int j=sum;j>=coin[i];j--)
		if(!dp[j]){
			dp[j]=dp[j-coin[i]];
			pre[j]=j-coin[i];
		}
while(pre[tmp]!=-1){
	ans.push_back(tmp-pre[tmp]);
	tmp=pre[tmp];
}
for(int j=ans.size()-1;j>=0;j--)
	printf("%d ",ans[j]);
