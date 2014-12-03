#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<cstdlib>
//#include<utility>

#define maxx 105
#define INF 1000000000

using namespace std;

int n,k,t[6],w[maxx][maxx],arr[maxx],dis[maxx];
bool inqueue[maxx];

void SPFA(int start)
{
	memset(inqueue,false,sizeof(inqueue));
	for(int i=0;i<maxx;i++)	dis[i]=INF;
	dis[start]=0;
	queue<int>q;
	inqueue[start]=true;
	q.push(start);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		inqueue[u]=false;
		for(int i=0;i<maxx;i++){
			if(u==0){
				if(dis[i]>dis[u]+w[u][i]){
					dis[i]=dis[u]+w[u][i];
					if(inqueue[i]==false){
						inqueue[i]=true;
						q.push(i);
					}
				}
			}
			else if(dis[i]>dis[u]+w[u][i]+60){
				dis[i]=dis[u]+w[u][i]+60;
				if(inqueue[i]==false){
					inqueue[i]=true;
					q.push(i);
				}
			}
		}//for(int i=0;i<n;i++)
	}//while(!q.empty())
}
int main()
{
	char input[1000],*p;
	while(scanf("%d %d",&n,&k)!= EOF){
		for(int i=0;i<maxx;i++){
			w[i][i]=INF;
			for(int j=i+1;j<maxx;j++)
				w[i][j]=w[j][i]=INF;
		}
		for(int i=0;i<n;i++)
			scanf("%d",&t[i]);
		getchar();
		for(int i=0;i<n;i++){
			gets(input);
			int pos=0;
			for(p=strtok(input," ");p!=NULL;p=strtok(NULL," "))
				arr[pos++]=atoi(p);
			for(int j=0;j<pos;j++)
				for(int k=j;k<pos;k++){
					int tmp=abs(arr[j]-arr[k])*t[i];
					if(tmp<w[arr[j]][arr[k]])
						w[arr[j]][arr[k]]=w[arr[k]][arr[j]]=tmp;
				}
		}
		SPFA(0);
		if(dis[k] != INF)	printf("%d\n",dis[k]);
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}
