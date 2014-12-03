#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;

int main()
{
	int test;
	long long int n;
	scanf("%d",&test);
	while(test--){
		scanf("%lld",&n);
		int time=0;
		//int t=100;
		while(1){
			int r[30],len=0;
			long long int re=n;
			while(re>0){
				r[len]=re%10;
				re=re/10;
				len++;
			}
			re=0;
			for(int i=0;i<len;i++)
				re=re*10+r[i];
			//printf("%lld %lld\n",n,re);
			if(n==re){
				printf("%d %lld\n",time,n);
				break;
			}
			time++;
			n=n+re;
		}
	}
	return 0;
}
