#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

#define maxx 100000000

using namespace std;

bool isprime[maxx];

void sieve()
{
	memset(isprime,true,sizeof(isprime));
	isprime[0]=false;
	isprime[1]=false;
	for(int i=2;i<=sqrt(maxx);i++)
		if(isprime[i])
			for(int j=i*i;j<maxx;j += i)
				isprime[j]=false;
	isprime[1]=true;
}
int main()
{
	sieve();
	int n,i,check;
	while(scanf("%d",&n) != EOF){
		if(n&1){
			if(n <=3 ){
				printf("%d is not the sum of two primes!\n",n);
				continue;
			}
			if(isprime[n-2])
				printf("%d is the sum of 2 and %d.\n",n,n-2);
			else
				printf("%d is not the sum of two primes!\n",n);
		}
		else{
			i=n>>1;
			if(! (i&1) )	i--;
			for(;i>2;i-=2){
				if(isprime[i] && isprime[n-i] && n-i != i){
					printf("%d is the sum of %d and %d.\n",n,i,n-i);
					break;
				}
			}
			if(i<2)
				printf("%d is not the sum of two primes!\n",n);
		}
	}//while scanf
	return 0;
}

