#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>


using namespace std;

bool isprime[10000];
int prime[1500],top=0;

void sieve()
{
	memset(isprime,true,sizeof(isprime));
	isprime[0]=false;
	isprime[1]=false;
	for(int i=2;i<10000;i++)
		if(isprime[i]){
			for(int j=i*i;j<10000;j += i)
				isprime[i]=false;
			prime[top++]=i;
		}
}
int main()
{
	int test;
	int a,b,c,ans,re,tmp,num,p;
	sieve();
	scanf("%d",&test);
	for(int t=1;t<=test;t++){
		printf("Case %d:\n",t);
		scanf("%d %d",&a,&b);
		tmp=a;
		ans=1<<29;
		for(int i=0;i<top && prime[i]<=tmp;i++){
			c=p=0;
			num=1;
			if(tmp % prime[i]==0){
				while(tmp%prime[i]==0){
					num=prime[i];
					tmp /= prime[i];
					p++;
				}
				while(num<=b){
					c += b/num;
					num *= prime[i];
				}
				ans=min(ans,c/p);
			}
		}
		if(ans>0)	
			printf("%d\n",ans);
		else
			printf("Impossible to divide\n");
	}
}
