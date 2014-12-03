/* Library: Find the cut vertex (articulation point) of a G
 *
 * Call: As shown in the main function.
 *
 * Note: The input graph is bi-directional.
 *
 *  */
#include <iostream>
using namespace std;

class CutVertex
{
public:
	#define MAX_VERTEX 110
	bool graph[MAX_VERTEX][MAX_VERTEX];
	int dfn[MAX_VERTEX], low[MAX_VERTEX], answer[MAX_VERTEX];
	int deapth, ansc, Vnum, Enum;

	void dfnlow(int u, int v)
	{
		/*--u is the visiting point, v is the u's parent and w
			is u's child.--*/
		int w;
		bool yes=0;
		int child=0;
		dfn[u]=low[u]=deapth++;
		for(w=0;w<MAX_VERTEX;w++)
			if(graph[u][w])
			{
				if(dfn[w]<0)    //w isn't visited.
				{
					dfnlow(w,u);
					child++;
					if(dfn[u]<=low[w])yes=1;
					low[u]=(low[u]<low[w])?low[u]:low[w];
				}
				else if(w!=v) //Back edge
					low[u]=(low[u]<dfn[w])?low[u]:dfn[w];
			}
		if((child>1||v>=0)&&yes)answer[ansc++]=u;
	}

	void initialization()
	{
		int i;
		memset(graph,0,MAX_VERTEX*MAX_VERTEX*sizeof(bool));
		ansc = deapth = 0;
		for(i=0;i<MAX_VERTEX;i++) dfn[i]=low[i]=-1;
	}

	void FindCutVertex()
	{
		for(int i=0;i<MAX_VERTEX;i++)
			if(dfn[i]==-1) dfnlow(i,-1);
	}
};

int main()
{
	freopen("test", "r", stdin);

	CutVertex my;
	int u, v;

	while(scanf("%d %d", &my.Vnum, &my.Enum)==2)
	{
		my.initialization();

		for(int i=0; i<my.Enum; i++)
		{
			scanf("%d %d",&u, &v);
			my.graph[u][v] = my.graph[v][u] = true;
		}

		/* Find the cut-vertex */
		my.FindCutVertex();

		/* Show the vertex */
		if(my.ansc==0)
			printf("No cut vertex\n");
		else
		{
			for(int i=0; i<my.ansc; i++)
				printf("%d ", my.answer[i]);
			putchar('\n');
		}
	}
	return 0;
}


