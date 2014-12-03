////2D infinite knapsack	二维完全背包
for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++)
		dp[i][j]=INF;
dp[0][0]=0;
for(int i=0;i<m;i++)
for(int j=p[i].x;j<=n;j++)
for(int k=p[i].y;k<=n;k++)
dp[j][k]=min(dp[j][k],dp[j-p[i].x][k-p[i].y]+1);

int ans=INF,t=n*n;
for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++)
		if(i*i + j*j==t)
			ans=min(dp[i][j],ans);
