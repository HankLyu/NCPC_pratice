#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int ans[500],n;

const int V = 100, E = 600;
// Edge List
struct Edge 
{
	int a, b, c;
} edges[E];
bool operator<(const Edge& e1, const Edge& e2) 
{
	return e1.c < e2.c;
}     
    // Disjoint-sets Forest
int p[V];

int init() 
{
	for (int i=0; i<V; ++i) 
		p[i] = i;
}

int find(int x) 
{
	return x == p[x] ? x : (p[x] = find(p[x]));
}

void un(int x, int y) 
{
	p[find(x)] = find(y);
}
//////////////////////////////////////////
void Kruskal()
{
    init();
        // 圖上所有邊，依照權重大小，由小到大排序。
    sort(edges, edges+E);   // O(NlogN)
        // 嘗試找出最小生成樹上的V-1條邊
    int i, j;
	n=0;
    for (i = 0, j = 0; i < V-1 && j < E; ++i){
            // 同名參照，方便閱讀。
        Edge &e = edges[j];
            // 產生環，則捨棄。直到產生橋。
        while (find(e.a) == find(e.b)) j++;
            // 產生橋，則以此邊連接兩棵MSS。
        un(e.a, e.b);
            // 印出最小生成樹（森林）上的邊。
        ans[n]=edges[j].c;
		n++;
		cout<< "起點：" << edges[j].a
            << "終點：" << edges[j].b
            << "權重：" << edges[j].c;
        
		j++;    // 別忘記累計索引值。也可以寫入迴圈。
    }
     
    /*if (i == V) cout << "得到最小生成樹";
    else        cout << "得到最小生成森林";
	*/
}
//////////////////////////////////////////
int main()
{
	int play;
	scanf("%d",&play);
	while(play--)
	{
		memset(ans,0,sizeof(ans));
		int num;
		scanf("%d",&num);
		int dis[num][num];
		n=0;
		for(int i=0;i<num;i++)
			for(int j=0;j<num;j++){
				scanf("%d",&dis[i][j]);
				if(i<j){
					edges[n].a=i;
					edges[n].b=j;
					edges[n].c=dis[i][j];
					n++;
				}
			}
		Kruskal();
	}
	return 0;
}
