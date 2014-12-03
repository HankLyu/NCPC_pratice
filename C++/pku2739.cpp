#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>

using namespace std;
bool isprime[10001];

void sieve()
{
	memset(isprime,true,sizeof(isprime));
	isprime[0]=false;
	isprime[1]=false;
	for(int i=2;i<=sqrt(10001);i++)
		if(isprime[i])
			for(int j=i*i;j<10001;j+=i)
				isprime[j]=false;
}
int main()
{
	int a,i,j;
	sieve();
	while(scanf("%d",&a)!=EOF&&a!=0)
	{
		int sum=0;
		int ans=0;
		for(i=2;i<=a;i++)
			if(isprime[i])
				for(j=i;j<=a;j++)
					if(isprime[j])
					{
						sum+=j;
						if(sum==a)
						{
							ans++;
							sum=0;
							break;
						}
						else if(sum>a)
						{
							sum=0;
							break;
						}
					}
		//if(isprime[a])	sum++;
		cout<<ans<<endl;
	}
	return 0;
}
