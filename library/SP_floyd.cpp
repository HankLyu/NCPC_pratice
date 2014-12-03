int map[maxx][maxx];
int pre[maxx][maxx];

void floyd_warshall(int n)
{
	for(int i=1;i<=n;i++)	//from 1 to n
		for(int j=1;j<=n;j++){
			if(i==j)	pre[i][j]=-1;
			else		pre[i][j]=i;
		}
	for(int k=1;k<=n;k++)		//to find the ALL sp
		for(int i=1;i<=n;i++)	//from one to another
			for(int j=1;j<=n;j++)
				if(i!=j && (map[i][k]+map[k][j]<map[i][j]) ){
					map[i][j]=map[i][k]+map[k][j];
					pre[i][j]=pre[k][j];
				}
	int index=-1;	//index show who cause the fastest spread
	int ans=INF;	//ans show the time spend to spread to all 
	for(int i=1;i<=n;i++){
		int maxtime=-1;
		for(int j=1;j<=n;j++){
			if(maxtime<map[i][j] && i!=j)
				maxtime=map[i][j];
		}
		if(ans>maxtime){
			ans=maxtime;
			index=i;
		}
	}
	if(ans==INF)	printf("disjoint\n");
	else	printf("%d %d\n",index, ans);
}
void find_path(int a, int b)	// 印出由a點到b點的最短路徑
{								//it wait to be checked
    for (int i=a; i!=b; i=pre[i][b])
        cout << i;
    cout << b;
}
bool negative_cycle()
{
    for (int i=0; i<9; i++)
		if (map[i][i] < 0)
            return true;
    return false;
}