#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

#define maxx 1000005

using namespace std;

char s[maxx],input[maxx];
int pi[maxx];
int main()
{
	while(scanf("%s",input)!=EOF && input[0]!='.'){
		strcpy(s,"s");
		strcat(s,input);
		memset(pi,0,sizeof(pi));
		int len=strlen(s);
		int ans=-1,k=0;
		pi[1]=0;
		for(int i=2;i<len;i++){
			while(k>0 && s[k+1]!=s[i])
				k=pi[k];
			if(s[k+1]==s[i])	k++;
			pi[i]=k;
		}
		//for(int i=1;i<len;i++)
		//	printf("%3d",pi[i]);
		//printf("\n");
		len--;
		if(len%(len-pi[len])==0)
			printf("%d\n",(len)/(len-pi[len]));
		else	printf("1\n");
	}
	return 0;
}
