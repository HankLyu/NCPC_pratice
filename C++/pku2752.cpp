#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

#define maxx 400005

using namespace std;

char s[maxx];
int pi[maxx],len,a[maxx];

int pow(int n,int b){
	int ans=1;
	for(int i=0;i<b;i++)
		ans*=n;
	return ans;
}
int main(){
	while(scanf("%s",s+1)!=EOF){
		s[0]='#';
		len=strlen(s);
		pi[1]=0;
		int k=0;
		for(int i=2;i<=len;i++){
			while(k>0 && s[k+1]!=s[i])	k=pi[k];
			if(s[k+1]==s[i])	k++;
			pi[i]=k;
		}
		int tmp=len-1,num=0;
		a[num++]=len-1;
		while(pi[tmp]){
			a[num++]=pi[tmp];
			tmp=pi[tmp];
		}
		for(int i=num-1;i>0;i--)	printf("%d ",a[i]);
		printf("%d\n",a[0]);
	}
	return 0;
}
