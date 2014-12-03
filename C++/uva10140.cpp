#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>

#define maxx 46341

using namespace std;

bool p[maxx];
vector<int> prime;
int l,u;
int a,b,c,d,len;
int check[10000001];
void sieve()
{
	memset(p,true,sizeof(p));
	p[0]=0;
	p[1]=0;
	for(int i=2;i<=maxx;i++)
		if(p[i]){
			prime.push_back(i);
			for(int j=i*i;j<maxx;j+=i)
				p[j]=0;
		}
}
bool isprime(int n){
	if(n<maxx)	return p[n];
	for(int i=0;i<len && prime[i]<n;i++){
		if(n%prime[i]==0)	return false;
	}
	return true;
}
int main()
{
	sieve();
	len=prime.size();
	while(scanf("%d %d",&l,&u)!=EOF){
		for(int i=l; ;i++){
			if(!isprime(i))
				check[i-l]=0;
			else check[i-l]=1;
			if(i==u)	break;
		}
		int a=-1,b=-1,dis=0,clo=2e9,mx1,mx2,mn1,mn2;
		for(int i=0;i<=u-l;i++)
			//printf("%d\n",i);
			if(check[i]){
				a=i;
				if(b!= -1){
					if(a-b>dis)	dis=a-b,mx1=b,mx2=a;
					if(a-b<clo)	clo=a-b,mn1=b,mn2=a;
				}
				b=a;
			}
		if(dis)
			printf("%d,%d are closest, %d,%d are most distant.\n",
				mn1+l,mn2+l,mx1+l,mx2+l);
		else	printf("There are no adjacent primes.\n");
	}
	return 0;
}
