#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<cmath>
#include<vector>

#define maxx 16000005

using namespace std;

int n,nc;
int dp[maxx];
char s[maxx];
int word[200];

int pow(int n,int b){
	int ans=1;
	for(int i=0;i<b;i++)
		ans*=n;
	return ans;
}
int main()
{
	int p,q;
	int num;
	while(scanf("%d %d",&n,&nc)!=EOF){
		memset(dp,0,sizeof(dp));
		memset(word,-1,sizeof(word));
		scanf("%s",s);
		p=nc;
		num=0;
		int slen=strlen(s);
		int tmp=0,ans=0,k;
		for(int i=0;i<slen;i++){
			if(word[s[i]]<0)	
				word[s[i]]=num++;
		}
		for(int i=0;i<n;i++){
			tmp=(tmp*p+word[s[i]]);
		}
		dp[tmp]++;
		//printf("%d\n",tmp);
		ans++;
		for(int i=n;i<slen;i++){
			k = pow(p,n-1)*word[s[i-n]];
			//printf("w=%d\n",word[s[i-n]]);
			tmp-=k;
			tmp*=p;
			tmp += word[s[i]];
			//printf("%d\n",tmp);
			if(!dp[tmp]){
				dp[tmp]++;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
