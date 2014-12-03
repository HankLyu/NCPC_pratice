#include<iostream>
#include<cstdio>
#include<cstring>

#define maxx 1005

using namespace std;

int fun(char x)
{
	if(x<='9' && x>='0')	return x-'0';
	if(x<='Z' && x>='A')	return x-'A'+10;
	if(x<='z' && x>='a')	return x-'a'+36;
	return 0;
}
int main()
{
	char s[maxx];
	while(scanf("%s",s)!=EOF){
		int ans=2,x=0;
		int len=strlen(s);
		for(int i=0;i<len;i++)	ans=max(ans,fun(s[i])+1);
		for(int i=0;i<len;i++)	x+=fun(s[i]);
		if(s[0]=='-')	x=-x;
		for(;ans<63;ans++)	if(x%(ans-1)==0)	break;
		if(ans==63)	printf("such number is impossible!\n");
		else printf("%d\n",ans);
	}
	return 0;
}
