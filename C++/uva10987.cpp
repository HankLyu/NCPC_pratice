#include<iostream>
#include<cstdio>
#include<cstring>

#define maxx 105

using namespace std;

int weight[maxx][maxx];
int n;

bool islegal()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j && k!=i && k!=j &&
					weight[i][k]+weight[k][j]<weight[i][j])
					return false;
	return true;
}

int main()
{
	int test,w;
	scanf("%d",&test);
	for(int t=1;t<=test;t++){
		memset(weight,-1,sizeof(weight));
		scanf("%d",&n);
		for(int i=1;i<n;i++){
			for(int j=1;j<=i;j++){
				scanf("%d",&w);
				weight[i+1][j]=weight[j][i+1]=w;
			}
		}
		printf("Case #%d:\n",t);
		if(!islegal())
			printf("Need better measurements.\n");
		else{
			for(int k=1;k<=n;k++)
				for(int i=1;i<=n;i++)
					for(int j=1;j<=n;j++)
						if(i!=j && k!=i && k!=j
							&& weight[i][k]!= -1 && weight[k][j]!=-1)
							if(weight[i][k]+weight[k][j]==weight[i][j])
								weight[i][j]=-1;
			w=0;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					if(weight[i][j]>0)
						w++;
			printf("%d\n",w);

			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					if(weight[i][j]>0)
						printf("%d %d %d\n",i,j,weight[i][j]);
		}
		printf("\n");
	}
	return 0;
}
