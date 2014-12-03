#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

#define maxx 1000005

using namespace std;

char w[10005],t[maxx];
int piw[maxx];
int lenw,lent;
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		scanf("%s",w+1);
		scanf("%s",t+1);
		w[0]=t[0]='#';
		memset(piw,0,sizeof(piw));
		lenw=strlen(w);
		lent=strlen(t);
		int k=0;
		for(int i=2;i<lenw;i++){
			while(k>0 && w[k+1]!=w[i])	k=piw[k];
			if(w[k+1]==w[i])	k++;
			piw[i]=k;
		}
		int ans=0,l=0;
		for(int i=1;i<lent;i++){
			while(w[l+1]!=t[i] && l)	l=piw[l];
			if(w[l+1]==t[i])	l++;
			if(l==lenw-1)	{
				ans++;
				l=piw[l];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
