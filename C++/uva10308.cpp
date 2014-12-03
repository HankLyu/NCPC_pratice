#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

#define maxx 10005
#define INF 1000000000
using namespace std;

int w[maxx][maxx];
bool visit[maxx];
int next[maxx];
int DFS(int now,int n)
{
	int ans=0,tmp=0;
	visit[now]=true;
	for(int i=1;i<=n;i++){
		if(w[now][i]>0 && !visit[i]){
			//printf("from %d to %d\n",now,i);
			tmp=w[now][i]+DFS(i,n);
			if(ans<tmp){
				ans=tmp;
				next[now]=i;
			}
		}
	}
	return ans;
}
int main()
{
	int a,b,c,maxnum=0;
	char s[100];
	memset(w,0,sizeof(0));
	memset(visit,false,sizeof(visit));
	memset(next,-1,sizeof(next));
	while(gets(s)){
		//printf("s=%s",s);
		if(s[0]!='\0'){
			sscanf(s,"%d %d %d",&a,&b,&c);
			w[a][b]=w[b][a]=c;
			if(maxnum<max(a,b))	maxnum=max(a,b);
		}
		else {
			int ans=0,tmp;
			/*for(int i=1;i<=maxx;i++){
				memset(visit,0,sizeof(visit));
				tmp=DFS(i,maxnum);
				//printf("%d %d\n",i,tmp);
				ans=max(ans,tmp);
			}*/
			DFS(1,maxnum);
			//for(int i=1;i<=maxnum;i++)	printf("%d %d\n",i,next[i]);
			tmp=1;
			memset(visit,false,sizeof(visit));
			while(next[tmp]!=-1)	tmp=next[tmp];
			printf("%d\n",tmp,DFS(tmp,maxnum));
			maxnum=0;
			memset(w,0,sizeof(w));
			memset(visit,false,sizeof(visit));
			memset(next,-1,sizeof(next));
		}
	}
	int ans=0;
	/*for(int i=1;i<=maxx;i++){
		memset(visit,0,sizeof(visit));
		ans=max(ans,DFS(i,maxnum));
	}*/
	DFS(1,maxnum);
	memset(visit,0,sizeof(visit));
	int tmp=1;
	while(next[tmp]!=-1)	tmp=next[tmp];
	printf("%d\n",DFS(tmp,maxnum));
	return 0;
}
