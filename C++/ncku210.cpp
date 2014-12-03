#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#define MAX 1000010

using namespace std;

bool isprime[ MAX ];
long long int table[ MAX ] = {0}, limit = 0;

void init()
{
	memset( isprime, true, sizeof(isprime) );
	isprime[0] = isprime[1] = false;
	for ( int i = 2; i <= sqrt(MAX); i++ )
	{
		if ( isprime[i] )
			for ( int j = i*i; j < MAX; j += i )
				isprime[j] = false;
	}

	for ( int i = 2; i < MAX; i++ )
		if ( isprime[i] )
			table[ limit++ ] = i;
}

int main()
{
	int x;
	long long int low, high;
	scanf("%d", &x);

	init();

	while ( x-- )
	{
		scanf("%lld %lld", &low, &high);
		int sum = 0;
		for(int i=0;table[i]!=0;i++)
	}
	return 0;
}
