
int weight[maxx][maxx],n;		//weight
int depth[maxx],low[maxx];	//dfn low
int visit[maxx],cut;

int DFS(int node,int d,int parent){	//dth be find
	int back=1000,child=0,tmp,flag=0;
	depth[node]=d;
	for(int i=1;i<=n;i++){
		if(weight[node][i]==1){
			if(visit[i]==0){
				visit[i]=1;
				tmp=DFS(i,d+1,node);
				if(tmp>=d)	flag=1;
				/*	it is caculate edge
				if(tmp>d){
					cutBridge[node][i]=1;
					cutBridge[i][node]=1;
				}
				*/
				back=min(back,tmp);
				child++;
			}
			else if(i!=parent)
				back=min(back,depth[i]);
		}
	}
	low[node]=back;
	//it is node
	if(node==1 ){	
		if(child>1)	cut++;
	}
	else	cut+=flag;
	//
	return low[node];
}
visit[1]=1;
cut=0;
DFS(1,1,0);
printf("%d\n",cut);
//edge	for is mean may many graph
for(int i=0;i<n;i++)
	if(used[i]==0){
		used[i]=1;
		DFS(i,1,-1);
	}
int ans=0;
for(int i=0;i<n;i++)
	for(int j=i+1;j<n;j++)
		if(cutBridge[i][j]!=0)	ans++;
//edge
