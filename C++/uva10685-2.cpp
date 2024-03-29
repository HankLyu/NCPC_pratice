/*
	Find the lagest group
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include<map>

#define maxx 5005

using namespace std;
void Make_Set(int n);
int Find_Set(int i);
void Union(int x, int y);
int father[maxx], rank[maxx];
map<string,int>qq;

int main()
{	
	int c, m,x,y;
	char p1[100], p2[100];
	while(~scanf("%d%d", &c, &m)){
		qq.clear();
		if(c == 0 && m == 0)
			break;
		Make_Set(c);
		for(int i = 0; i < c; i++){
			scanf("%s", p1);
			qq[p1]=i;
			//printf("%d\n",qq[p1]);
		}
		for(int i = 0; i < m; i++){
			scanf("%s %s", p1, p2);
			x=qq[p1],y=qq[p2];
			//printf("%d %d\n",x,y);
			x = Find_Set(x), y = Find_Set(y);
			//printf("do\n");
			if(x != y)
				Union(x, y);
		}
		int ans = 0;
		for(int i = 0; i < c; i++)
			ans=max(ans,rank[i]);
		printf("%d\n", ans);
	}
	return 0;
}
void Make_Set(int n){
	for(int i = 0; i < n; i++)
		father[i] = i, rank[i] = 1;
}
int Find_Set(int i){
	if(i != father[i])
		father[i] = Find_Set(father[i]);
	return father[i];
}
void Union(int x, int y){
	if(rank[x] < rank[y])
		father[y] = x, rank[x] += rank[y];
	else
		father[x] = y, rank[y] += rank[x];
}
