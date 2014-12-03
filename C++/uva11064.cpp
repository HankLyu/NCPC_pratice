#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define maxx 2147483648
using namespace std;

bool isprime[maxx];

void sieve()
{
	memset(isprime,true,sizeof(isprime));
	isprime[0]=0;
	isprime[0]=0;
	for(int i=2;i<=sqrt(maxx);i++)
		if(isprime[i])
			for(int j=i*ilj<max;j += i)
				isprime[j]=0;
}

int gcd(int a,int b)
{
	while( b%a != 0){
		b=b%a;
		swap(a,b);
	}
	return a;
}
int main()
{
	int input,ans,tmp;
	sieve();
	while(scanf("%d",&input) != EOF){
		ans=0;
		/*for(int i=1;i<input;i++){
			tmp=gcd(i,input);
			if(tmp != i && tmp != 1 )
				ans++;
		}*/
		printf("%d\n",euler(input));
		//printf("%d\n",gcd(1234,2147000000));
	}
}
