// UVA 532  Dungeon Master
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 35
using namespace std;
char map[MAXN][MAXN][MAXN];
bool v[MAXN][MAXN][MAXN];
int L,R,C,SX,SY,SZ,EX,EY,EZ;
struct QUEUE
{
	int x,y,z,c;
}tmp,next;
int BFS(int x,int y,int z)
{
	v[x][y][z]=true;
	queue<QUEUE>q;
	tmp.x=x,tmp.y=y,tmp.z=z,tmp.c=0;
	q.push(tmp);
	while(!q.empty())
	{
		tmp=q.front();
		//cout<<tmp.x<<" "<<tmp.y<<" "<<tmp.z<<" "<<tmp.c<<'\n';
		q.pop();
		if(tmp.x==EX&tmp.y==EY&tmp.z==EZ) return tmp.c;
		if(tmp.x>1&!v[tmp.x-1][tmp.y][tmp.z]) {
			next.x=tmp.x-1,next.y=tmp.y,next.z=tmp.z,next.c=tmp.c+1,q.push(next),v[tmp.x-1][tmp.y][tmp.z]=true;	}
		if(tmp.y>1&!v[tmp.x][tmp.y-1][tmp.z]) {
			next.x=tmp.x,next.y=tmp.y-1,next.z=tmp.z,next.c=tmp.c+1,q.push(next),v[tmp.x][tmp.y-1][tmp.z]=true;	}
		if(tmp.z>1&!v[tmp.x][tmp.y][tmp.z-1]) {
			next.x=tmp.x,next.y=tmp.y,next.z=tmp.z-1,next.c=tmp.c+1,q.push(next),v[tmp.x][tmp.y][tmp.z-1]=true;	}
		if(tmp.x<L&!v[tmp.x+1][tmp.y][tmp.z]) {	
			next.x=tmp.x+1,next.y=tmp.y,next.z=tmp.z,next.c=tmp.c+1,q.push(next),v[tmp.x+1][tmp.y][tmp.z]=true;	}
		if(tmp.y<R&!v[tmp.x][tmp.y+1][tmp.z]) {
			next.x=tmp.x,next.y=tmp.y+1,next.z=tmp.z,next.c=tmp.c+1,q.push(next),v[tmp.x][tmp.y+1][tmp.z]=true;	}
		if(tmp.z<C&!v[tmp.x][tmp.y][tmp.z+1]) {
			next.x=tmp.x,next.y=tmp.y,next.z=tmp.z+1,next.c=tmp.c+1,q.push(next),v[tmp.x][tmp.y][tmp.z+1]=true;	}
	}
	return 0;
}
int main()
{
	int i,j,k,ans;
	while(scanf("%d%d%d",&L,&R,&C),L||R||C)
	{
		memset(v,0,sizeof(v));
		for(i=1;i<=L;++i)
		{
			for(j=1;j<=R;++j)
			{
				scanf("%s",map[i][j]+1);
				for(k=1;k<=C;++k)
				{
					if(map[i][j][k]=='S')
						{SX=i,SY=j,SZ=k;}
					if(map[i][j][k]=='E')
						{EX=i,EY=j,EZ=k;}
					if(map[i][j][k]=='#')
						v[i][j][k]=true;
				}
			}
		}
		ans=BFS(SX,SY,SZ);
		if(ans)	printf("Escaped in %d minute(s).\n",ans);
		else printf("Trapped!\n");
	}
	return 0;
}
