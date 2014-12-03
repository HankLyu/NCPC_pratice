char pawns[max][max];
struct xxx tmp,next;
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
			next.x=tmp.x-1,next.y=tmp.y,next.z=tmp.z,next.c=tmp.c+1;
			q.push(next);
			v[tmp.x-1][tmp.y][tmp.z]=true;
		}
		if(tmp.y>1&!v[tmp.x][tmp.y-1][tmp.z]) {
			next.x=tmp.x,next.y=tmp.y-1,next.z=tmp.z,next.c=tmp.c+1;
			q.push(next);
			v[tmp.x][tmp.y-1][tmp.z]=true;
		}
		if(tmp.z>1&!v[tmp.x][tmp.y][tmp.z-1]) {
			next.x=tmp.x,next.y=tmp.y,next.z=tmp.z-1,next.c=tmp.c+1;
			q.push(next);
			v[tmp.x][tmp.y][tmp.z-1]=true;
		}
		if(tmp.x<L&!v[tmp.x+1][tmp.y][tmp.z]) {	
			next.x=tmp.x+1,next.y=tmp.y,next.z=tmp.z,next.c=tmp.c+1;
			q.push(next);
			v[tmp.x+1][tmp.y][tmp.z]=true;
		}
		if(tmp.y<R&!v[tmp.x][tmp.y+1][tmp.z]) {
			next.x=tmp.x,next.y=tmp.y+1,next.z=tmp.z,next.c=tmp.c+1;
			q.push(next);
			v[tmp.x][tmp.y+1][tmp.z]=true;
		}
		if(tmp.z<C&!v[tmp.x][tmp.y][tmp.z+1]) {
			next.x=tmp.x,next.y=tmp.y,next.z=tmp.z+1,next.c=tmp.c+1;
			q.push(next);
			v[tmp.x][tmp.y][tmp.z+1]=true;
		}
	}
	return 0;
}
