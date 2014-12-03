#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>

#define maxx 150000

using namespace std;

bool isprime[maxx];
vector<long long int>prime;
int len;

void sieve()
{
	prime.clear();
	memset(isprime,true,sizeof(isprime));
	isprime[0]=false;
	isprime[1]=false;
	len=0;
	for(int i=2;i<=sqrt(maxx);i++){
		if(isprime[i]){
			prime.push_back(i);
			len++;
			for(int j=i*i;j<maxx;j += i){
				isprime[j]=false;
			}
		}
	}
}
int gcd(int a,int b)
{
	if(b==0)	return a;
	return gcd(b,a%b);
}
int main()
{
	sieve();
	long long int n,tmp;
	int ans,check;
	while(scanf("%lld",&n) != EOF && n!=0){
		int tmp=n;
		vector<int>v;
		for(int i=0;i<len;i++){
			int t=0;
			while(n%prime[i]==0){
				n=n/prime[i];
				t++;
			}
			if(t>0)	v.push_back(t);
		}
		if(n!=1 && n!=-1)	v.push_back(1);
		if(tmp==1 || tmp==-1)	v.push_back(1);
		int ans=v[0];
		for(int i=1;i<v.size();i++){
			ans=gcd(ans,v[i]);
		}
		if(tmp<0){
			for(int i=0;i<v.size();i++)
				while(v[i]%2==0)	v[i]=v[i]/2;
			ans=v[0];
			for(int i=1;i<v.size();i++)
				ans=gcd(ans,v[i]);
		}
		if(tmp ==1 || tmp ==-1)	ans=1;
		printf("%d\n",ans);
	}//while scanf
	return 0;
}
