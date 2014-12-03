#include<iostream>
#include<cstdio>
#include<cstring>

#define maxx 10005

using namespace std;

int num[maxx],n,m,last;
bool check,remain[100],remaintmp[100];

int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		check=0;
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%d",&num[i]);
		memset(remain,0,sizeof(remain));
		int x=num[0]%m;
		if(x<0)	x+=m;
		remain[x]=1;
		for(int i=1;i<n;i++){
			memset(remaintmp,0,sizeof(remaintmp));
			for(int j=0;j<100;j++){
				if(remain[j]==1){
					int m1=(j+num[i])%m;
					if(m1<0)	m1+=m;
					int m2=(j-num[i])%m;
					if(m2<0)	m2+=m;
					remaintmp[m1]=1;
					remaintmp[m2]=1;
				}
			}
			memcpy(remain,remaintmp,sizeof(remain));
		}
		if(remain[0]==1)	printf("Divisible\n");
		else				printf("Not divisible\n");
	}
	return 0;
}
