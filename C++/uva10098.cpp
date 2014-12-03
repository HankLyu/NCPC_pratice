#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char ar[11],ans[11];
bool solution[11];
int len;
void backtrack(int n)
{
	if(n == len){
		for(int i=0;i<len;i++)
			printf("%c",ans[i]);
		printf("\n");
		return ;
	}
	char last='\0';
	for(int i=0;i<len;i++)
		if(solution[i]==0 && last != ar[i] ){
			solution[i]=1;
			last=ar[i];
			ans[n]=ar[i];
			backtrack(n+1);
			solution[i]=0;
		}
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		memset(solution,false,sizeof(solution));
		scanf("%s",ar);
		len=strlen(ar);
		sort(ar,ar+strlen(ar));
		backtrack(0);
		printf("\n");
	}
	return 0;
}
