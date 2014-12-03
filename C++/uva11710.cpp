#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>

#define maxx 405
#define INF 2e9

using namespace std;

int w[maxx][maxx],parent[maxx];
int d[maxx],n,m,ans;
bool visit[maxx];
map<string,int> qq;

void prim()
{
	memset(visit,0,sizeof(visit));
	for(int i=0;i<n;i++)	d[i]=INF;
	d[0]=0;
	parent[0]=0;
	ans=0;
	for(int i=0;i<n;i++){
		int a=-1,b=-1,min=INF;
		for(int j=0;j<n;j++)
			if(!visit[j] && d[j]<min){
				a=j;
				min=d[j];
			}
		if(a==-1)	break;
		//printf("p[%d]=%d\n",a,parent[a]);
		visit[a]=true;
		ans += w[parent[a]][a];
		for(b=0;b<n;b++)
			if(w[a][b]>0 && !visit[b]){
				d[b]=w[a][b];
				parent[b]=a;
			}
	}
}

int main()
{
	char a[20],b[20];
	int cost;
	while(scanf("%d %d",&n,&m)!=EOF){
		if (n==0 && m==0)	break;
		for(int i=0;i<n;i++){
			scanf("%s",a);
			qq[a]=i;
		}
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)	w[i][j]=w[j][i]=INF;
		for(int i=0;i<m;i++){
			scanf("%s %s %d",a,b,&cost);
			w[ qq[a]][ qq[b]]=w[ qq[b]][ qq[a]]=cost;
		}
		scanf("%s",a);
		prim();
		bool check=true;
	/*	for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				printf("%5d",w[i][j]);
			printf("\n");
		}
		for(int i=0;i<n;i++)
			printf("%2d",visit[i]);
		printf("\n");
	*/	for(int i=0;i<n;i++)
			if(visit[i]==0)	check=false;
		//check=true;
		if(check)	printf("%d\n",ans);
		else	printf("Impossible\n");
	}
	return 0;
}
