void MakeSet(int x)
{
	p[x] = x;
	rank[x] = 0;
}
int FindSet(int x)
{
	if(x!=p[x])
		p[x] = FindSet(p[x]);
	return p[x];
}
void Link(int x,int y)
{
	if(x==y)	cycle++;
	if(rank[x]>rank[y])
		p[y] = x;
	else{
		p[x] = y;
		if(rank[x]==rank[y])
			rank[y]++;
	}
}
void Union(int x,int y)
{
	Link(FindSet(x),FindSet(y));
}



