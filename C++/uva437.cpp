#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define maxx 200

using namespace std;

struct node
{
	int x,y,z;
}block[91];

bool cmp(node a,node b)
{
	return a.x>b.x;
}
int main()
{
	int n,test=0;
	while(scanf("%d",&n)!=EOF && n){
		for(int i=0;i<n;i++){
			scanf("%d %d %d",&block[i].x,&block[i].y,&block[i].z);
			if(block[i].y>block[i].x)	swap(block[i].x,block[i].y);
			
			block[n+i]=block[i];
			swap(block[n+i].x,block[n+i].z);
			if(block[n+i].y > block[n+i].x)
				swap(block[n+i].x, block[n+i].y);

			block[2*n+i]=block[i];
			swap(block[2*n+i].y,block[2*n+i].z);
			if(block[2*n+i].y > block[2*n+i].x)
				swap(block[2*n+i].y,block[2*n+i].x);
		}
		sort(block,block+3*n,cmp);
		//for(int i=0;i<3*n;i++)
			//printf("%d %d %d\n",block[i].x,block[i].y,block[i].z);
		int dp[90];
		for(int i=0;i<3*n;i++)	dp[i]=block[i].z;
		for(int i=0;i<3*n;i++)
			for(int j=i+1;j<3*n;j++){
				if( (block[i].x>block[j].x && block[i].y>block[j].y) ||
					(block[i].x>block[j].y && block[i].y>block[j].x)) 
					if(dp[j]<dp[i]+block[j].z){
						dp[j]=dp[i]+block[j].z;
					}
			}
		int ans=0;
		for(int i=0;i<3*n;i++)
			ans=max(ans,dp[i]);
		printf("Case %d: maximum height = %d\n",++test,ans);
	}
	return 0;
}
