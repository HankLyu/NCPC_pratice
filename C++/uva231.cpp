#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int ar[1000],dp[1000];

void f(int x)
{
	if(dp[x]>1)
		return ;
	for(int i=x-1;i>=0;i--)
		if(ar[x]<ar[i] && dp[x]<dp[i]+1)
			dp[x]=dp[i]+1;
	return ;
}

int main()
{
	int test=1,num=0,n,first=0;
	while(scanf("%d",&n)!= EOF){
		if(n!=-1){
			ar[num]=n;
			num++;
		}
		else{
			if(num==0)
				break;
			if(first)	printf("\n");
			else first++;
			for(int i=0;i<num;i++)
				dp[i]=1;
			for(int i=0;i<num;i++) f(i);
			int max=dp[0];
			for(int i=1;i<num;i++)
				if(max<dp[i])	max=dp[i];
			printf("Test #%d:\n",test);
			printf("  maximum possible interceptions: %d\n",max);
			test++;
			num=0;
		}
	}
	return 0;
}
