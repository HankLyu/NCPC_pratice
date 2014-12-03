#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>

#define maxx 105
#define INF 1000

using namespace std;

struct EDGE
{
	int t,w,c,d;
};
struct node
{
	int d,id,c;
	bool operator <(const node &t)const{
		if(d==t.d) return c>t.c;
		return d>t.d;
	}
}TMP;
priority_queue<node> v;
vector<EDGE> edge[maxx];
EDGE tmp;
int M,W,dis[maxx];
int S,D,L,T,K,N,R;
int dd[maxx];

int dij(int start)
{
	int nowv,nowd,nowc,nextv,cost[maxx];
	for(int i=0;i<maxx;i++)
		dis[i]=INF;
	TMP.id=start,TMP.d=0,TMP.c=0;
	v.push(TMP);
	dis[start]=0;
	while(!v.empty()){
		TMP=v.top();
		nowv=TMP.id,nowd=TMP.d,nowc=TMP.c;
		dis[nowv]=nowd;
		if(nowv==N) return dis[N];
		v.pop();
		for(int i=0;i<(int)edge[nowv].size();i++){
			nextv=edge[nowv][i].t;
			if(nowc+edge[nowv][i].c<=K){
				TMP.id=nextv;
				TMP.d=nowd+edge[nowv][i].w;
				TMP.c=nowc+edge[nowv][i].c;
				v.push(TMP);
			}
		}
	}
	if(dis[N]==INF) return -1;
	else return dis[N];
}
int main()
{
	scanf("%d %d %d",&K,&N,&R);
	for(int i=0;i<maxx;i++)
		edge[i].clear();
	for(int i=0;i<R;i++){
		scanf("%d %d %d %d",&S,&D,&L,&T);
		tmp.t=D;
		tmp.w=L;
		tmp.c=T;
		edge[S].push_back(tmp);
	}
	printf("%d\n",dij(1));
	return 0;
}
