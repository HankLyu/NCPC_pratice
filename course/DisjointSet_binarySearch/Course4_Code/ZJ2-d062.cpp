#include <iostream>
#include <cstdio>
using namespace std;

#define MAXN 31000

int p[MAXN], rank[MAXN], size[MAXN], ans[MAXN];

void makeset()
{
	int i;
	for(i=0; i<MAXN; i++)
	{
		p[i] = i;			//parent
		rank[i] = 0;		//height
		size[i] = 1;		//self
	}
}

int findset(int a)
{
	return a==p[a] ? a : p[a] = findset(p[a]);
}

void link(int x, int y)
{
	if(rank[x]<rank[y])
	{
		p[x] = y;
		size[y] += size[x];
	}
	else
	{
		p[y] = x;
		size[x] += size[y];
		if(rank[x]==rank[y])
		{
			rank[x]++;
		}
	}
}

void unionset(int x, int y)
{
	if(findset(x)==findset(y)) return;
	link(findset(x), findset(y));
}

int main()
{

	int i, j, datacase, N, M, a, b, len;

	scanf("%d", &datacase);

	while(datacase--)
	{
		scanf("%d %d", &N, &M);

		makeset();

		for(i=0; i<M; i++)
		{
			scanf("%d %d", &a, &b);
			unionset(a, b);
		}



		j = 0;

		for(i=1; i<=N; i++)
			j = max(j, size[findset(i)]);

		cout<<j<<endl;

	}

	return 0;
}
