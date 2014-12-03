int adj[9][9];
bool visit[9];
vector<int> finish[9];  // 依照離開順序排好所有點
int contract[9];		// 每個點收縮到的點
void DFS1(int i){
	if (visit[i]) return;
	visit[i] = true;
	for (int j=0; j<9; ++j)
		if (adj[i][j])
			DFS1(j);
	finish.push_back(i);
} 
void DFS2(int i, int p){
	if (visit[i]) return;
	visit[i] = true;
	for (int j=0; j<9; ++j)
		if (adj[j][i])  // 顛倒所有邊的方向
			DFS2(j, n);
	contract[i] = p;	// 收縮至第p點
}	 
void kosaraju(){
	finish.clear();
	memset(visit, false, sizeof(visit));
	for (int i=0; i<9; ++i) DFS1(i);
	memset(visit, false, sizeof(visit));
	for (int i=9-1; i>=0; --i) DFS2(finish[i], finish[i]);
}
