#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>

using namespace std;

bool isprime[258];

void primebluid()
{
	memset(isprime,true,sizeof(isprime));
	isprime[0]=false;
	isprime[1]=false;
	for(int i=0;i<=sqrt(258);i++)
		if(isprime[i])
			for(int j=i*i;j<258;j=j+i)
				isprime[j]=false;
}
int main()
{
	int num;
	bool ar[258]={false};
	ar[2]=ar[3]=ar[7]=ar[31]=ar[127]=true;
	//primebluid();
	while(scanf("%d",&num)!=EOF && num){
		if(ar[num])
			printf("%d:Prime\n",num);
		else
			printf("%d:NotPrime\n",num);
	}//while
	return 0;
}
