#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 110
using namespace std;


int N, cost[MAXN][MAXN];

bool islegal()
{
	int i, j, k;

	for(k=1; k<=N; k++)
		for(i=1; i<=N; i++)
			for(j=1; j<=N; j++)
				if(i!=j && k!=i && k!=j && cost[i][k]+cost[k][j]<cost[i][j])
					return false;
	return true;
}

void construct()
{
	int i, j, k;
	for(k=1; k<=N; k++)
		for(i=1; i<=N; i++)
			for(j=1; j<=N; j++)
				if(i!=j && k!=i && k!=j && cost[i][k]!=-1 && cost[k][j]!=-1)
					if(cost[i][k]+cost[k][j]==cost[i][j])
						cost[i][j] = -1;
}

int main()
{

	int i, j, T, a, b, c, t=0, n=0;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d", &N);

		/* read the graph */
		memset(cost, -1, sizeof(cost));
		n = 0;

		for(i=2; i<=N; i++)
		{
			a = i;
			for(j=1; j<i; j++)
			{
				b = j;
				scanf("%d", &c);
				cost[a][b] = cost[b][a] = c;
			}
		}

		printf("Case #%d:\n", ++t);

		if(!islegal())
			printf("Need better measurements.\n");
		else
		{
			construct();

			for(i=1; i<=N; i++)
				for(j=i+1; j<=N; j++)
					if(cost[i][j]>=0)
						n++;

			printf("%d\n", n);

			for(i=1; i<=N; i++)
				for(j=i+1; j<=N; j++)
					if(cost[i][j]>=0)
						printf("%d %d %d\n", i, j, cost[i][j]);


			/*for(i=1; i<=N; i++, cout<<endl)
				for(j=1; j<=N; j++)
					cout<<cost[i][j]<<" ";*/
		}
		putchar('\n');
	}

	return 0;
}
