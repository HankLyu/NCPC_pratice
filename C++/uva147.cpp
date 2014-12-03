#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	long long int dp[40000]={0};
	int n,a,b,c[11]={10000,5000,2000,1000,500,200,100,50,20,10,5};
	dp[0]=1;
	for(int i=0;i<11;i++)
		for(int j=c[i];j<40000;j++)
			dp[j] += dp[j-c[i]];
	while(scanf("%d.%d",&a,&b) != EOF){
		if(a==0 && b==0)	break;
		n=a*100+b;
		printf("%3d.%02d%17lld\n",a,b,dp[n]);
	}
	return 0;
}
