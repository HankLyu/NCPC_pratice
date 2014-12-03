#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define maxx 110
#define word 35
using namespace std;

int len1,len2,len;
char first[maxx][word],second[maxx][word];
char result[maxx][word];
int dp[maxx][maxx],path[maxx][maxx];
bool use[maxx][maxx];

int LCS(int n1,int n2)
{
	if(n1<0 || n2<0)
		return 0;
	if(use[n1][n2] ==true)
		return dp[n1][n2];
	if(strcmp(first[n1],second[n2]) == false){
		dp[n1][n2] = LCS(n1-1,n2-1) +1;
		path[n1][n2]=1;
	}
	else{
		int t1=LCS(n1-1,n2);
		int t2=LCS(n1,n2-1);
		if(t1<t2)
			dp[n1][n2]=t2, path[n1][n2]=2;
		else
			dp[n1][n2]=t1, path[n1][n2]=3;
	}
	use[n1][n2]=true;
	return dp[n1][n2];
}
void find_LCS(int n1,int n2)
{
	if(n1<0 || n2<0)
		return ;
	if(path[n1][n2]==3)
		find_LCS(n1-1,n2);
	else if(path[n1][n2]==2)
		find_LCS(n1,n2-1);
	else if(path[n1][n2] ==1){
		strcpy(result[--len],first[n1]);
		find_LCS(n1-1,n2-1);
	}
}

int main()
{
	char c[word];
	int play=0,m;
	len1=len2=0;
	memset(use,0,sizeof(use));
	memset(dp,0,sizeof(dp));
	memset(path,0,sizeof(path));
	while(scanf("%s",c) != EOF){
		//printf("play=%d len1=%d len2=%d\n",play,len1,len2);
		if(play==0 && c[0]!='#'){
			strcpy(first[len1],c);
			len1++;
		}
		else if(play==0 && c[0]=='#'){
			play++;
		}
		else if(play==1 && c[0]!='#'){
			strcpy(second[len2],c);
			len2++;
		}
		else if(play==1 && c[0]=='#'){
			m=len=LCS(len1-1,len2-1);
			find_LCS(len1-1,len2-1);
			for(int i=0;i<m;i++){
				printf("%s",result[i]);
				if(i != m-1)
					printf(" ");
			}
			printf("\n");
			/*printf("first:\n");
			for(int i=0;i<len1;i++){
				printf("%s",first[i]);
				if(i != len1-1)
					printf(" ");
			}
			printf("\n");
			printf("second:\n");
			for(int i=0;i<len2;i++){
				printf("%s",second[i]);
				if(i != len2-1)
					printf(" ");
			}
			printf("\n");
*/
			memset(use,0,sizeof(use));
			memset(dp,0,sizeof(use));
			memset(path,0,sizeof(path));
			play=len1=len2=0;
		}
	}
	return 0;
}
