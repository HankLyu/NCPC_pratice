#include<iostream>
#include<cstdio>
#include<cstring>

#define maxx 20

using namespace std;

char map[maxx][maxx];
int n;

int check(int i,int j){
	int ans=0;
	if(i>0){
		if(j>0 && map[i-1][j-1]=='*')	ans++;
		if(j<n-1 && map[i-1][j+1]=='*')	ans++;
		if(map[i-1][j]=='*')			ans++;
	}
	if(i<n-1){
		if(j>0 && map[i+1][j-1]=='*')	ans++;
		if(j<n-1 && map[i+1][j+1]=='*')	ans++;
		if(map[i+1][j]=='*')			ans++;
	}
	if(j>0 && map[i][j-1]=='*')		ans++;
	if(j<n-1 && map[i][j+1]=='*')	ans++;
	//printf("%d\n",ans);
	return ans;
}
int main()
{
	int test;
	char tuch[maxx][maxx];
	int ans[maxx][maxx];
	int boom;
	scanf("%d",&test);
	while(test--){
		memset(ans,-1,sizeof(ans));
		scanf("%d",&n);
		boom=0;
		for(int i=0;i<n;i++)
			scanf("%s",map[i]);
		for(int i=0;i<n;i++)
			scanf("%s",tuch[i]);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(tuch[i][j]=='x'){
					ans[i][j]=check(i,j);
					if(map[i][j]=='*')	boom=1;
				}
		if(boom){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(map[i][j]=='*')	printf("*");
					else if(ans[i][j]>=0)	printf("%d",ans[i][j]);
					else	printf(".");
				}
				printf("\n");
			}
		}
		else{
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(ans[i][j]>=0)	printf("%d",ans[i][j]);
					if(ans[i][j]==-1)	printf(".");
				}
				printf("\n");
			}
		}
		if(test)	printf("\n");
	}
	return 0;
}
