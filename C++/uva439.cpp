#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

int x1,x2;
int y1,y2,visit[8][8];

struct seat
{
	int x,y,move;
};

int BFS()
{
	queue<seat> q;
	seat tmp,next;
	memset(visit,0,sizeof(visit));
	visit[x1][y1]=1;
	tmp.x=x1, tmp.y=y1, tmp.move=0;
	q.push(tmp);
	while(!q.empty()){
		tmp=q.front();
		q.pop();
		//printf("%d%d\n",tmp.x,tmp.y);
		if(tmp.x==x2 && tmp.y==y2){
			while(!q.empty())
				q.pop();
			return tmp.move;
		}
		if(tmp.x >=2 && tmp.y >= 1 && !visit[tmp.x-2][tmp.y-1]){
			next.x=tmp.x-2,next.y=tmp.y-1,next.move=tmp.move+1;
			q.push(next);
			visit[next.x][next.y]=1;
		}
		if(tmp.x >=2 && tmp.y <= 6 && !visit[tmp.x-2][tmp.y+1]){
			next.x=tmp.x-2,next.y=tmp.y+1,next.move=tmp.move+1;
			q.push(next);
			visit[next.x][next.y]=1;
		}
		if(tmp.x <=5 && tmp.y >= 1 && !visit[tmp.x+2][tmp.y-1]){
			next.x=tmp.x+2,next.y=tmp.y-1,next.move=tmp.move+1;
			q.push(next);
			visit[next.x][next.y]=1;
		}
		if(tmp.x <=5 && tmp.y <= 6 && !visit[tmp.x+2][tmp.y+1]){
			next.x=tmp.x+2,next.y=tmp.y+1,next.move=tmp.move+1;
			q.push(next);
			visit[next.x][next.y]=1;
		}
		if(tmp.x >=1 && tmp.y >= 2 && !visit[tmp.x-1][tmp.y-2]){
			next.x=tmp.x-1,next.y=tmp.y-2,next.move=tmp.move+1;
			q.push(next);
			visit[next.x][next.y]=1;
		}
		if(tmp.x >=1 && tmp.y <= 5 && !visit[tmp.x-1][tmp.y+2]){
			next.x=tmp.x-1,next.y=tmp.y+2,next.move=tmp.move+1;
			q.push(next);
			visit[next.x][next.y]=1;
		}
		if(tmp.x <=6 && tmp.y >= 2 && !visit[tmp.x+1][tmp.y-2]){
			next.x=tmp.x+1,next.y=tmp.y-2,next.move=tmp.move+1;
			q.push(next);
			visit[next.x][next.y]=1;
		}
		if(tmp.x <=6 && tmp.y <= 5 && !visit[tmp.x+1][tmp.y+2]){
			next.x=tmp.x+1,next.y=tmp.y+2,next.move=tmp.move+1;
			q.push(next);
			visit[next.x][next.y]=1;
		}
	}
	return 0;
}
int main()
{
	char s1[5],s2[5];
	while(scanf("%s %s",s1,s2) != EOF){
		x1=s1[0]-'a', y1=s1[1]-'1';
		x2=s2[0]-'a', y2=s2[1]-'1';
		//printf("%d%d %d%d\n",x1,y1,x2,y2);	
		printf("To get from %s to %s takes %d knight moves.\n",s1,s2,BFS());
	}//while scanf
}
