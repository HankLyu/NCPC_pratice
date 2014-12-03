/*#include<iostream>
#include<cstdio>
#include<cstring>

#define maxx 55
#define INF 2e9
#define maxlen 1005

using namespace std;

int dp[maxlen][maxlen];
int cut[maxx],len,n;

int cutting(int a,int b)
{
	if(dp[a][b]!= -1)	return dp[a][b];
	int tmp;
	for(int i=a+1;i<b;i++){
		tmp=cutting(a,i)+cutting(i,b)+cut[b]-cut[a];
		if(dp[a][b]<0 || tmp<dp[a][b])	dp[a][b]=tmp;
	}
	return dp[a][b];
}
int main()
{
	while(scanf("%d",&len)!=EOF && len){
		scanf("%d",&n);
		memset(dp,-1,sizeof(dp));
		cut[0]=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&cut[i]);
		cut[n+1]=len;
		for(int i=0;i<=n;i++)
			dp[i][i+1]=0;
		printf("The minimum cutting is %d.\n",cutting(0,n+1));
	}
	return 0;
}*/
#include <iostream>  
#include <string.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <algorithm>  
using namespace std;  
#define LL long long  
#define M 55  
#define inf 0x3fffffff  
  
int dp[M][M], c[M];  
  
int dfs (int x, int y)  
{  
    if (dp[x][y] > -1)  
        return dp[x][y];  
    int tp = -1, i;  
    for (i = x+1; i < y; i++)  
    {  
        int tmp = dfs(x, i) + dfs(i, y) + c[y] - c[x];  
        if (tp < 0 || tmp < tp) tp = tmp;  
    }  
    return (dp[x][y] = tp);  
}  
  
int main()  
{  
    int n, m, i;  
    while (cin >> n, n)  
    {  
        cin >> m;  
        c[0] = 0;  
        for (i = 1; i <= m; i++) {  
            cin >> c[i];  
        }  
        c[m+1] = n;  
        memset (dp, -1, sizeof(dp));  
        for (i = 0; i <= m; i++)  
            dp[i][i+1] = 0;  
        cout << "The minimum cutting is " << dfs(0, m+1) << "." << endl;  
    }  
    return 0;  
}  
