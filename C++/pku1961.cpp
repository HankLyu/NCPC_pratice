#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>

#define maxx 1000005

using namespace std;

char s[maxx],input[maxx];
int len,pi[maxx];

int main(){
	int test=0;
	while(scanf("%d",&len)!=EOF && len){
		scanf("%s",input);
		strcpy(s,"s");
		strcat(s,input);
		len++;
		memset(pi,0,sizeof(pi));
		int k=0;
		for(int i=2;i<len;i++){
			while(k>0 && s[k+1]!=s[i])
				k=pi[k];
			if(s[k+1]==s[i])	k++;
			pi[i]=k;
		}
		//len--;
		printf("Test case #%d\n",++test);
		for(int i=1;i<len;i++)
			if(i%(i-pi[i])==0 && i/(i-pi[i])>1)
				printf("%d %d\n",i,i/(i-pi[i]));
		printf("\n");
	}
	return 0;
}
