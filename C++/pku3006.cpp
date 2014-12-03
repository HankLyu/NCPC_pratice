#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

#define maxx 1000000

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
}
int main()
{
	int a,d,n,ans;
	sieve();
	while(scanf("%d %d %d",&a,&d,&n) != EOF){
		if(a==0 && d==0 && n==0)
			break;
		for(int i=a;;i= i+d){
			if(isprime[i]==true)
				n--;
			if(n==0){
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
