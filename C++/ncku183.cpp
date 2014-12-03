#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>

#define max 1299710

using namespace std;

bool isprime[max];

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
		if(isprime[num])
			printf("0\n");
		else{
			for(int i=num-1;i>0;i--)
				if(isprime[i]){
					a=i;
					break;
				}
			for(int i=num+1;i<max;i++)
				if(isprime[i]){
					b=i;
					break;
				}
			printf("%d\n",b-a);
		}//else
	}//while
	return 0;
}
