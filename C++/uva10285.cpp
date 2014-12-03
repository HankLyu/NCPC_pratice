#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>

#define maxx 105

using namespace std;

int map[maxx][maxx];
int visit[maxx][maxx];
int n,m;

struct node
{
	int x,y;
	int c;
}tmp,next;

int DFS(int x,int y){
	visit[x][y]=true;
	stack<node>q;
	int ans=0;
	tmp.x=x,tmp.y=y,tmp.c=1;
	q.push(tmp);
	while(!q.empty()){
		tmp=q.top();
		//printf("%d %d\n",tmp.x,tmp.y);
		q.pop();
		int check=1;
		if(tmp.x>0 && map[tmp.x-1][tmp.y]<map[tmp.x][tmp.y]){
			next.x=tmp.x-1,next.y=tmp.y,next.c=tmp.c+1;
			q.push(next);
			check=0;
			visit[next.x][next.y]=1;
		}
		if(tmp.y>0 && map[tmp.x][tmp.y-1]<map[tmp.x][tmp.y]){
			next.x=tmp.x,next.y=tmp.y-1,next.c=tmp.c+1;
			q.push(next);
			check=0;
			visit[next.x][next.y]=1;
		}
		if(tmp.x<n-1 && map[tmp.x+1][tmp.y]<map[tmp.x][tmp.y]){
			next.x=tmp.x+1,next.y=tmp.y,next.c=tmp.c+1;
			q.push(next);
			check=0;
			visit[next.x][next.y]=1;
		}
		if(tmp.y<m-1 && map[tmp.x][tmp.y+1]<map[tmp.x][tmp.y]){
			next.x=tmp.x,next.y=tmp.y+1,next.c=tmp.c+1;
			q.push(next);
			check=0;
			visit[next.x][next.y]=1;
		}
		if(check){
			ans=max(ans,tmp.c);
		}
	}
	//printf("%d %d %d\n",x,y,ans);
	return ans;
}
int main()
{
	int test;
	char name[maxx];
	int a=0,b=0;
	scanf("%d",&test);
	while(test--){
		scanf("%s %d %d",name,&n,&m);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",&map[i][j]);
		int ans=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				//memset(visit,0,sizeof(visit));
				int tmp=DFS(i,j);
				if(ans<tmp){
					ans=tmp;
					a=i,b=j;
				}
			}
		printf("%s: %d\n",name,ans,a,b);
	}
	return 0;
}
