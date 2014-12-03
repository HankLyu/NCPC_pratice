#include <iostream>
#include <algorithm>
#define MAXN 50010
using namespace std;

int dis[MAXN], D, N, M;

bool canbe(int in)
{
	int i, cnt=0, prev=0;
	for(i=0; i<N; i++)
		if(dis[i]-prev<in) cnt++;
		else prev = dis[i];
	if(D-prev<in) cnt++;
	if(cnt<=M) return true;
	return false;
}

int main()
{
	//freopen("test", "r", stdin);

	int i, beg, end, mid;

	while(scanf("%d %d %d", &D, &N, &M)==3)
	{
		for(i=0; i<N; i++) scanf("%d", &dis[i]);
		sort(dis, dis+N);

		/* start to check */
		beg = 0, end = D;

		do
		{
			mid = (beg+end+1)/2;

			if(canbe(mid)) beg = mid;
			else end = mid - 1;

		}while(beg<end);

		printf("%d\n", end);

	}

	return 0;
}
