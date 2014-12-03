#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	long long int n,ans;
	while(scanf("%lld",&n)!=EOF){
		n=n/2;
		ans=15+30*(n-1)+(n-2)*(n-1)*6;
		printf("%lld\n",ans);
	}
	return 0;
}
