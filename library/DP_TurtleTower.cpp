void TurtleTower()
{
	memset(pre,-1,sizeof(pre));
	for(int i=0;i<=n;i++)	dp[i]=2e9;
	dp[0]=0;
	for(int i=0;i<n;i++)
		for(int j=n;j>=1;j--)
			if(dp[j-1]+t[i].w<=t[i].s){
				dp[j]=min(dp[j],dp[j-1]+t[i].w);
			}
	int ans=0;
	for(ans=n;ans>=0;ans--){
		//printf("%d\n",dp[ans]);
		if(dp[ans]!=2e9)	break;
	}
		printf("%d\n",ans);
}
