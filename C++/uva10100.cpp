#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

#define maxx 1005
#define maxn 55

using namespace std;

char s[maxx],w1[maxx][maxx],w2[maxx][maxx];
int dp[maxx][maxx];
int use[maxx][maxx];
int w1num,w2num,slen;
void change1()
{
	w1num=0;
	int tmp=0;
	for(int i=0;i<=slen;i++){
		if((s[i]<='z' && s[i]>='a') || (s[i]<='Z' && s[i]>='A') || 
			(s[i]<='9' && s[i]>='0')){
			w1[w1num][tmp]=s[i];
			tmp++;
		}
		else{
			tmp=0;
			if( (w1[w1num][0]>='a' && w1[w1num][0]<='z') ||
				(w1[w1num][0]>='A' && w1[w1num][0]<='Z') ||
				(w1[w1num][0]>='0' && w1[w1num][0]<='9'))	w1num++;
			//w1num++;
		}
	}
}
void change2()
{
	w2num=0;
	int tmp=0;
	for(int i=0;i<=slen;i++){
		if((s[i]<='z' && s[i]>='a') || (s[i]<='Z' && s[i]>='A') ||
			(s[i]<='9' && s[i]>='0'))
			w2[w2num][tmp++]=s[i];
		else{
			tmp=0;
			if( (w2[w2num][0]>='a' && w2[w2num][0]<='z') ||
				(w2[w2num][0]>='A' && w2[w2num][0]<='Z') ||
				(w2[w2num][0]>='0' && w2[w2num][0]<='9'))	w2num++;
			//w2num++;
		}
	}
}
int LCS(int n1,int n2)
{
	if(n1<0 || n2<0)	return 0;
	if(use[n1][n2])	return dp[n1][n2];
	if(strcmp(w1[n1],w2[n2])==0){
		dp[n1][n2]=LCS(n1-1,n2-1)+1;
	}
	else{
		int t1=LCS(n1-1,n2);
		int t2=LCS(n1,n2-1);
		if(t1<t2)	dp[n1][n2]=t2;
		else		dp[n1][n2]=t1;
	}
	use[n1][n2]=true;
	return dp[n1][n2];
}
int main()
{
	int test=1;
	while(gets(s)){
		bool check=0;
		if(s[0]=='\0'){
			printf("%2d. Blank!\n",test++);
			gets(s);
			continue;
		}
		memset(w1,0,sizeof(w1));
		memset(w2,0,sizeof(w2));
		memset(dp,0,sizeof(dp));
		memset(use,0,sizeof(use));
		slen=strlen(s);
		for(int i=0;i<slen;i++)
			if(s[i]!=' '){
				check=1;
				break;
			}
		if(!check){
			printf("%2d. Blank!\n",test++);
			gets(s);
			continue;
		}
		change1();
		gets(s);
		if(s[0]=='\0'){
			printf("%2d. Blank!\n",test++);
			continue;
		}
		slen=strlen(s);
		for(int i=0;i<slen;i++)
			if(s[i]!=' '){
				check=1;
				break;
			}
		if(!check){
			printf("%2d. Blank!\n",test++);
			continue;
		}
		change2();
		/*for(int i=0;i<w1num;i++)
			printf("%s\n",w1[i]);
		printf("/////////////////endw1\n");
		for(int i=0;i<w2num;i++)
			printf("%s\n",w2[i]);
		printf("/////////////////endw2\n");
		*///printf("w1num=%d w2num=%d\n",w1num,w2num);
		printf("%2d. Length of longest match: %d\n",
			test++,LCS(w1num-1,w2num-1));
	}
	return 0;
}
