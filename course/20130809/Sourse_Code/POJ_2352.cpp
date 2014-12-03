#include <iostream>
#define MAXN 40001
using namespace std;

/* sum of tree in node i */
int tree_sum[MAXX], N;

void ini()
{
	memset(tree_sum, 0, sizeof(tree_sum));
}

int low(int in)
{
	return in&(-in);
}

void change(int x, int d)
{
	for(; x<MAXN; x+=low(x))
		tree_sum[x] += d;
}

int getsum(int x)
{
	int s = 0;
	for(; x>=1; x-=low(x))
		s += tree_sum[x];
	return s;
}

int main()
{

	int x, y, level[MAXN], i;

	while(scanf("%d", &N)==1)
	{
		/* initialization */
		ini();
		memset(level, 0, sizeof(level));

		/* start to read the input */
		for(i=1; i<=N; i++)
		{
			scanf("%d %d", &x, &y);
			x++, y++;
			level[getsum(x)]++;
			change(x, 1);
		}

		/* show the answer */
		for(i=0; i<N; i++)
			printf("%d\n", level[i]);
	}

	return 0;
}












