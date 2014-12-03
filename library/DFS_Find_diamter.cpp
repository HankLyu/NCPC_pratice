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
int ans=0,tmp;
DFS(1,maxnum);
tmp=1;
memset(visit,false,sizeof(visit));
while(next[tmp]!=-1)	tmp=next[tmp];//到端點
printf("%d\n",tmp,DFS(tmp,maxnum));
