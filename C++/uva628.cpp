#include<iostream>
#include<cstdio>
#include<cstring>

#define maxword 105
#define maxrule 1005
#define maxlen 260

using namespace std;

char word[maxword][maxlen];
char rule[maxrule][maxlen];
int n,m,solve[maxlen];

void back(int w,int r,int n)
{
	int len=strlen(rule[r]);
	if(n==len){
		for(int i=0;i<len;i++){
			if(solve[i]>=0)	printf("%d",solve[i]);
			else printf("%s",word[w]);
		}
		printf("\n");
		return ;
	}
	if(rule[r][n]=='0'){
		for(int i=0;i<10;i++){
			solve[n]=i;
			back(w,r,n+1);
		}
	}
	if(rule[r][n]=='#')
		back(w,r,n+1);
}
int main()
{
	while(scanf("%d",&n)!=EOF){
		printf("--\n");
		for(int i=0;i<n;i++)
			scanf("%s",word[i]);
		scanf("%d",&m);
		for(int i=0;i<m;i++)
			scanf("%s",rule[i]); 
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				memset(solve,-1,sizeof(solve));
				back(i,j,0);
			}
	}
	return 0;
}
