#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

#define maxx 105

using namespace std;

int weight[maxx][maxx],n;		//weight
int depth[maxx],low[maxx];	//dfn low
int use[maxx],cut;

int DFS(int node,int d,int parent){	//dth be find
	int i,back=1000,son=0,tmp,flag=0;
	depth[node]=d;
	for(int i=1;i<=n;i++){
		if(weight[node][i]==1){
			if(use[i]==0){
				use[i]=1;
				tmp=DFS(i,d+1,node);
				if(tmp>=d)	flag=1;
				back=min(back,tmp);
				son++;
			}
			else if(i!=parent)
				back=min(back,depth[i]);
		}
	}
	low[node]=back;
	if(node==1 ){	
		if(son>1)	cut++;
	}
	else	cut+=flag;
	return low[node];
}

int main()
{
	int x,y;
	char c;
	while(scanf("%d",&n) ==1 &&n){
		memset(weight,0,sizeof(weight));
		memset(depth,0,sizeof(depth));
		memset(low,0,sizeof(low));
		memset(use,0,sizeof(use));
		while(scanf("%d",&x)==1 && x){
			while(scanf("%d%c",&y,&c)==2){
				weight[x][y]=weight[y][x]=1;
				if(c=='\n')	break;
			}
		}
		use[1]=1;
		cut=0;
		DFS(1,1,0);
		printf("%d\n",cut);
	}
	return 0;
}
