//PKU 3617
#include <iostream>
using namespace std;
#define MAXN 2010
int N;
bool small(int pleft, int pright, char in[])
{
	int i, j=0;

	for(i=pleft; i<=pright; i++, j++)
	{
		if(in[i]>in[pright-j]) return false;
		if(in[i]<in[pright-j]) return true;
	}
	return false;
}

int main()
{
	int i, pleft, pright, pfinal;
	char in[MAXN], out[MAXN];

	while(scanf("%d", &N)==1)
	{
		/* initialization */
		for(i=0; i<N; i++)
		{
			cin>>in[i];
		}

		/* start to process */
		pleft = 0, pright = N-1, pfinal = 0;

		while(pfinal<N)
		{
			if( small(pleft, pright, in) )
				out[pfinal++] = in[pleft++];
			else
				out[pfinal++] = in[pright--];
		}
		out[pfinal] = 0;

		for(i=0; i<pfinal; i++)
		{
			if(i&&(i%80==0)) putchar('\n');
			printf("%c", out[i]);
		}
		putchar('\n');
	}
	return 0;
}
