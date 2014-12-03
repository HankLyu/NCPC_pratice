#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>

#define maxx 1005

using namespace std;

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	char s[20];
	unsigned long long int ans,value;
	map<string,unsigned long long int>qq;
	for(int i=0;i<n;i++){
		scanf("%s %llu",s,&value);
		qq[s]=value;
	}
	for(int i=0;i<m;i++){
		ans=0;
		while(scanf("%s",s)){
			if(s[0]=='.'){
				printf("%llu\n",ans);
				break;
			}
			if(qq[s])	ans+=qq[s];
		}
	}
}
