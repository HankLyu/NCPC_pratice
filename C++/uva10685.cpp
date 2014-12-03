#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>

#define maxx 5005

using namespace std;

int c,r;
int w[maxx][maxx];
int visit[maxx],next[maxx];
map<string,int>qq;
vector<int> head;

int DFS(int now)
{
	int ans=0,tmp=0;
	visit[now]=true;
	for(int i=0;i<c;i++)
		if(w[now][i]>0 && !visit[i]){
			tmp=w[now][i]+DFS(i);
			if(ans<tmp){
				ans=tmp;
				next[now]=i;
			}
		}
	return ans;
}
void search(int now)
{
	int ans=0,tmp=0;
	visit[now]=true;
	for(int i=0;i<c;i++)
		if(w[i][now]>0 && !visit[i]){
			tmp=w[i][now]+DFS(i);
			if(ans<tmp){
				ans=tmp;
				next[now]=i;
			}
		}
}
int main()
{
	char a[35],b[35];
	while(scanf("%d %d",&c,&r)!=EOF){
		qq.clear();
		if(c==0 && r==0)	break;
		memset(w,0,sizeof(w));
		memset(visit,0,sizeof(visit));
		memset(next,-1,sizeof(next));
		for(int i=0;i<c;i++){
			scanf("%s",a);
			//printf("%s\n",s);
			qq[a]=i;
		}
		for(int i=0;i<r;i++){
			scanf("%s %s",a,b);
			w[ qq[b]][ qq[a]]=1;
		}
		/*for(int i=0;i<c;i++){
			for(int j=0;j<c;j++)
				printf("%2d",w[i][j]);
			printf("\n");
		}*/
		//DFS(0);
		int tmp,ans=0,len;
		for(int i=0;i<c;i++){
			if(!visit[i]){
				search(i);
				tmp=i;
				while(next[tmp]!=-1)	tmp=next[tmp];
				//printf("tmp=%d\n",tmp);
				head.push_back(tmp);
			}
		}
		len=head.size();
		for(int i=0;i<len;i++){
				memset(visit,false,sizeof(visit));
				//memset(next,-1,sizeof(next));
				ans=max(ans,DFS(head[i]));
		}
		printf("%d\n",ans+1);
	}
	return 0;
}
