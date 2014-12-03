#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>

#define max 1000001
using namespace std;

bool isprime[1000001];

void sieve()
{
	memset(isprime,true,sizeof(isprime));
	isprime[0]=false;
	isprime[1]=false;
	for(int i=2;i<=sqrt(max);i++)
		if(isprime[i])
			for(int j=i*i;j<max;j=j+i)
				isprime[j]=false;
}
int main()
{
	int num,a,b;
	sieve();
	while(scanf("%d",&num)!=EOF && num){
		int check=0;
		for(int i=0;i<=num/2;i++)
			if(isprime[i]){
				b=num-i;
				if(isprime[b]){
					a=i;
					check=1;
					break;
				}
			}
		if(check)
			printf("%d = %d + %d\n",num,a,b);
		else	printf("Goldbach's conjecture is wrong.\n");
	}//while
	return 0;
}
