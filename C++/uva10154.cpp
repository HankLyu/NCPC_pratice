#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define maxx 6000

using namespace std;

struct node
{
	int w,s;
}t[maxx];
int dp[maxx],pre[maxx];
int tw[maxx],n;

bool cmp(node a,node b){
	return a.s<b.s;
}
void LIS()
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
int main()
{
	int a,b;
	while(scanf("%d %d",&a,&b)!=EOF){
		t[n].w=a;
		t[n].s=b;
		//tw[n]=a;
		n++;
	}
	sort(t,t+n,cmp);
	//for(int i=0;i<n;i++)
	//	printf("w=%d s=%d\n",t[i].w,t[i].s);
	LIS();
	return 0;
}
