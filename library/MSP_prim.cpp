int w[MAXN][MAXN];// 一張有權重的圖
int d[MAXN];       // 紀錄目前的MST到圖上各點的距離。
int parent[MAXN];  // 紀錄各個點在MST上的父親是誰
bool visit[MAXN];  // 紀錄各個點是不是已在MST之中
int n,ans;
int prim()
{
    int i,j;
    for (i=0; i<n; i++) visit[i] = false;
    for (i=0; i<n; i++) d[i] = INT_MAX;
    d[0] = 0;   // 可以選定任何點做為樹根，這裡以第零點做為樹根。
    parent[0] = 0;
    ans=0;
    for (i=0; i<n; i++)
    {
        int a = -1, b = -1, min = INT_MAX;
        for (j=0; j<n; j++)
            if (!visit[j] && d[j] < min)   //找出相鄰的點的最小值
            {
                a = j;  // 記錄這一條邊
                min = d[j];
            }

        if (a == -1) break; // 與起點相連通的MST都已找完
        visit[a] = true;
        if(min>0){			//build a new way
				printf("%d %d\n",a,parent[a]);
				num++;
		}
        ans=max(ans,w[parent[a]][a]);
        for (b=0; b<n; b++)
            // 以下與Dijkstra's Algorithm略有不同
            if  (!visit[b] && w[a][b] < d[b])    //相鄰的點皆有最小值了
            {
                d[b] = w[a][b]; // 離樹最近，不是離根最近。
                parent[b] = a;
            }
    }
    return ans;
}
