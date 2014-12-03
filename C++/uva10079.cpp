#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	long long int n;
	while(scanf("%lld",&n)!=EOF && n>=0){
		printf("%lld\n",(n+1)*n/2+1);
	}
	return 0;
}
