#include<iostream>
#include<cstdio>
#include<cstring>

#define maxx 55

using namespace std;

char map[maxx][maxx];
char s[maxx];
int m,n,k;

void check()
{
	int x=0,y=0,len=strlen(s);
	int ans=0;
	for(int i=0;i<n;i++){
		if(ans)	break;
		for(int j=0;j<m;j++){
			if(ans)	break;
			//printf("%d\n",ans);
			if(map[i][j]==s[0]){
				if(i>=len-1 && !ans){
					ans=1;
					for(int k=1;k<len;k++)
						if(map[i-k][j]!=s[k]){
							ans=0;
							break;
						}
					x=i,y=j;
					//printf("x=%d y=%d do1\n",x,y);
				}
				if(n-i>=len && !ans){
					ans=1;
					for(int k=1;k<len;k++)
						if(map[i+k][j]!=s[k]){
							ans=0;
							break;
						}
					x=i,y=j;
					//printf("x=%d y=%d do2\n",x,y);
				}
				if(j>=len-1 && !ans){
					ans=1;
					for(int k=1;k<len;k++)
						if(map[i][j-k]!=s[k]){
							ans=0;
							break;
						}
					x=i,y=j;
					//printf("x=%d y=%d do3\n",x,y);
				}
				if(m-j>=len && !ans){
					ans=1;
					for(int k=1;k<len;k++)
						if(map[i][j+k]!=s[k]){
							ans=0;
							break;
						}
					x=i,y=j;
					//printf("x=%d y=%d do4\n",x,y);
				}
				if(i>=len-1 && j>=len-1 && !ans){
					ans=1;
					for(int k=1;k<len;k++)
						if(map[i-k][j-k]!=s[k]){
							ans=0;
							break;
						}
					x=i,y=j;
					//printf("x=%d y=%d do5\n",x,y);
				}
				if(i>=len-1 && m-j>=len && !ans){
					ans=1;
					for(int k=1;k<len;k++)
						if(map[i-k][j+k]!=s[k]){
							ans=0;
							break;
						}
					x=i,y=j;
					//printf("x=%d y=%d do6\n",x,y);
				}
				if(n-i>=len && j>=len-1 && !ans){
					ans=1;
					int k;
					for(k=1;k<len;k++)
						if(map[i+k][j-k]!=s[k]){
							ans=0;
							break;
						}
					x=i,y=j;
					//printf("x=%d y=%d do7\n",x,y);
				}
				if(n-i>=len && m-j>=len && !ans){
					ans=1;
					for(int k=1;k<len;k++)
						if(map[i+k][j+k]!=s[k]){
							ans=0;
							break;
						}
					x=i,y=j;
					//printf("x=%d y=%d do8\n",x,y);
				}
			}
			//printf("n=%d m=%d i=%d j=%d ans=%d\n",n,m,i,j,ans);
		}
	}
	printf("%d %d\n",x+1,y+1);
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%s",map[i]);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(map[i][j]<='Z' && map[i][j]>='A')
					map[i][j]+='a'-'A';
		scanf("%d",&k);
		for(int i=0;i<k;i++){
			scanf("%s",s);
			int len=strlen(s);
			for(int j=0;j<len;j++)
				if(s[j]<='Z' && s[j]>='A')	s[j]+='a'-'A';
			check();
		}
		if(test)	printf("\n");
	}
	return 0;
}
