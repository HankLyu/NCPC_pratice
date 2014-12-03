#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>

#define maxx 2000000
using namespace std;

int main()
{
	int n;
	map<string,int>qq;
	int ans;
	char ansstring[maxx],tmp[maxx],input[maxx];
	while(scanf("%d",&n)!=EOF){
		scanf("%s",input);
		int len=strlen(input);
		ans=0;
		for(int i=0;i<=len-n;i++){
			for(int j=0;j<n;j++)
				tmp[j]=input[j+i];
			tmp[n]='\0';
			qq[tmp]++;
			if(qq[tmp]>ans){
				ans=qq[tmp];
				strcpy(ansstring,tmp);
				//printf("ansstring=%s\n",ansstring);
			}
			//printf("tmp=%s\n",tmp);
		}
		printf("%s\n",ansstring);
		qq.clear();
	}
}
