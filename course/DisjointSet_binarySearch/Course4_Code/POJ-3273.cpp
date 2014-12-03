#include <iostream>
#define MAXN 100010
using namespace std;

int N, M, money[MAXN];

bool canbe(int in)
{
	int i, s=0, c=0;
	for(i=0; i<N; i++)
		if(s+money[i]<=in)
			s += money[i];
		else
			s = money[i], c++;
	if(s>0) c++;
	if(c<=M) return true;
	return false;
}

int main()
{

	int i, LEFT, RIGHT, mid;

	while(scanf("%d %d", &N, &M)==2)
	{
		/* initialization */
		LEFT = 0, RIGHT = 0;

		for(i=0; i<N; i++)
		{
			scanf("%d", &money[i]);
			RIGHT += money[i];
			LEFT = max(LEFT, money[i]);
		}

		/* start to search the answer */
		do
		{
			mid = (LEFT+RIGHT)/2;

			if(canbe(mid))
				RIGHT = mid;
			else
				LEFT = mid+1;
		}while(LEFT<RIGHT);
		printf("%d\n", RIGHT);
	}

	return 0;
}
