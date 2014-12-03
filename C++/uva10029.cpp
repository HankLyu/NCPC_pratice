#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>

#define maxx 25005

using namespace std;

char word[20];
int dp[maxx];
map<string,int>r[50];

/*bool check(int i,int j)
{
	int leni=strlen(word[i]);
	int lenj=strlen(word[j]);
	if(abs(leni-lenj)>1)	return false;
	int change=0;
	leni=max(leni,lenj);
	//printf("do");
	for(int k=0;k<leni;k++)
		if(word[i][k]!=word[j][k]){
			change++;
			if(change>1)	return false;
		}
	if(change)	return true;
	else		return false;
}*/
int main()
{
	int n=0,ans=0;
	while(scanf("%s",word)!=EOF){
		int len=strlen(word);
		int mx=0;
		string x=word,y;
		map<string,int>::iterator it;
		for(int i=0;i<=len;i++)
			for(int j='a';j<='z';j++){
				y=x.substr(0,i)+char(j)+x.substr(i);
				it=r[y.length()].find(y);
				if(it !=r[y.length()].end())
					mx=max(mx,dp[it->second]);
				if(y.compare(x)>0)	break;
			}
		for(int i=0;i<len;i++){
			y=x.substr(0,i)+x.substr(i+1);
			it=r[y.length()].find(y);
			if(it != r[y.length()].end())
				mx=max(mx,dp[it->second]);
		}
		y=x;
		for(int i=0;i<len;i++)
			for(int j='a';j<='z';j++){
				char o=y[i];
				y[i]=j;
				it=r[y.length()].find(y);
				if(it != r[y.length()].end())
					mx=max(mx,dp[it->second]);
					y[i]=o;
					if(y.compare(x)>0)	break;
			}
		dp[n]=mx+1;
		ans=max(ans,dp[n]);
		r[x.length()][x]=n;
		n++;
	}
	printf("%d\n",ans);
	//memset(dp,0,sizeof(dp));
	/*for(int i=0;i<n;i++)
		for(int j=0;j<i;j++)
			if(check(i,j) && dp[j]+1>dp[i])
				dp[i]=dp[j]+1;
	int ans=0;
	for(int i=0;i<n;i++)
		ans=max(ans,dp[i]);
	printf("%d\n",ans+1);*/
	return 0;
}
