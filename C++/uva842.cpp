#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<vector>
#include<map>

#define maxx 30

using namespace std;

int check=0,num;
int edge[maxx][maxx];
int deg[maxx];
char have[maxx],big,small,solve[maxx];
int use[maxx];
map<char,int>qq;

void back(int n){
	if(n==num){
		check=1;
		for(int i=0;i<num;i++){
			printf("%c",solve[i]);
			if(i!=num-1)	printf(" ");
		}
		printf("\n");
	}
	for(int i=0;i<num;i++){
		//printf("i=%d deg=%d use=%d\n",i,deg[i],use[i]);
		if(deg[i]==0 && use[i]==0){
			solve[n]=have[i];
			use[i]=1;
			for(int j=0;j<maxx;j++)
				if(edge[i][j]==1)
					deg[j]--;
			back(n+1);
			for(int j=0;j<maxx;j++)
				if(edge[i][j]==1)
					deg[j]++;
			use[i]=0;
		}
	}
}

int main(){
	int test;
	char s[10000];
	scanf("%d",&test);
	gets(s);
	while(test--){
		qq.clear();
		memset(edge,0,sizeof(edge));
		memset(deg,0,sizeof(deg));
		num=0;
		check=0;
		gets(s);
		gets(s);
		int len=strlen(s);
		for(int i=0;i<len;i++)
			if(s[i]!=' ')	have[num++]=s[i];
		sort(have,have+num);
		for(int i=0;i<num;i++)	qq[have[i]]=i;
		gets(s);
		len=strlen(s);
		for(int i=0;i<len;i++)
			if(s[i]<='Z' && s[i]>='A'){
				small=s[i];
				i=i+2;
				big=s[i];
				edge[qq[small]][qq[big]]=1;
				deg[qq[big]]++;
			}
		memset(use,0,sizeof(use));
		back(0);
		if(check==0)	printf("NO\n");
		if(test)	printf("\n");
	}
	return 0;
}
