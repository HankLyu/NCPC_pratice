#include<iostream>
#include<cstdio>
#include<cstring>

#define maxx 10005

using namespace std;

char s[maxx][11];
int n;

bool docheck(int a,int b)
{
	int len=min(strlen(s[a]),strlen(s[b]));
	for(int i=0;i<len;i++)
		if(s[a][i]!=s[b][i])	return 0;
	return 1;
}
int main()
{
	n=0;
	int test=1;
	while(scanf("%s",s[n]) !=EOF){
		if(s[n][0] != '9'){
			n++;
		}
		else{
			bool check=0;
			for(int i=0;i<n;i++)
				for(int j=i+1;j<n;j++)
					if(docheck(i,j)==1){
						//printf("i=%d j=%d\n",i,j);
						check=1;
					}
			if(check)
				printf("Set %d is not immediately decodable\n",test);
			else
				printf("Set %d is immediately decodable\n",test);
			test++;
			n=0;
		}
	}
}
