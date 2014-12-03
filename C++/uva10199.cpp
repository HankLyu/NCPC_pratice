#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>

#define maxx 105

using namespace std;

int w[maxx][maxx],n,edge,ans;
map<string,int>qq;
int depth[maxx],low[maxx];
char name[maxx][35],city[maxx][35];
bool is[maxx],visit[maxx];
int root;

int DFS(int node, int d, int parent)
{
	int back=1000,child=0,tmp,flag=0;
	depth[node]=d;
	for(int i=0;i<n;i++){
		if(w[node][i]==1){
			if(visit[i]==0){
				visit[i]=1;
				tmp=DFS(i,d+1,node);
				if(tmp>=d){
					flag=1;
					//is[node]=1;
				}
				back=min(back,tmp);
				child++;
			}
			else if(i!=parent)
				back=min(back,depth[i]);
		}
	}
	low[node]=back;
	if(node==root){
		if(child>1)	ans++,is[root]=1;
	}
	else if(flag==1){
		ans+=flag;
		is[node]=1;
	}
	return low[node];
}
int main()
{
	int test=1;
	char a[35],b[35];
	while(scanf("%d",&n)!=EOF && n){
		memset(depth,-1,sizeof(depth));
		memset(is,0,sizeof(is));
		memset(visit,0,sizeof(visit));
		memset(low,-1,sizeof(low));
		memset(name,0,sizeof(name));
		memset(w,0,sizeof(w));
		memset(city,0,sizeof(city));
		ans=0;
		for(int i=0;i<n;i++){
			scanf("%s",a);
			qq[a]=i;
			strcpy(name[i],a);
		}
		scanf("%d",&edge);
		for(int i=0;i<edge;i++){
			scanf("%s %s",a,b);
			//printf("%d %d\n",qq[a],qq[b]);
			w[qq[a] ][qq[b] ] = w[qq[b] ][qq[a] ] = 1;
		}
		/*for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				printf("%2d",w[i][j]);
			printf("\n");
		}*/
		for(root=0;root<n;root++)
			if(visit[root]==0){
				visit[root]=1;
				DFS(root,1,-1);
			}
		//sort(anscity,anscity+ans);
		if(test!=1)	printf("\n");
		printf("City map #%d: %d camera(s) found\n",test++,ans);
		ans=0;
		for(int i=0;i<n;i++)
			if(is[i]==1)	strcpy(city[ans++],name[i]);
			//printf("%s\n",name[i]);
		for(int i=0;i<ans;i++)
			for(int j=0;j<i;j++)
				if(strcmp(city[i],city[j])<0){
					swap(city[i],city[j]);
				}
		for(int i=0;i<ans;i++)
			printf("%s\n",city[i]);
		qq.clear();
	}
	return 0;
}
