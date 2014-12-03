#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>

#define maxx 35

using namespace std;

double w[maxx][maxx],dis[maxx][maxx];
map<string,int>QQ;

int main()
{
	int n,test=1,num;
	double change;
	char a[1000],b[1000];
	while(scanf("%d",&n)!=EOF && n){
		memset(w,0,sizeof(w));
		memset(dis,0,sizeof(dis));
		for(int i=0;i<n;i++){
			scanf("%s",a);
			QQ[a]=i;
		}
		scanf("%d",&num);
		for(int i=0;i<num;i++){
			scanf("%s %lf %s",a,&change,b);
			w[QQ[a]][QQ[b]]=change;
		}
		for(int k=0;k<n;k++)
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					if(w[i][k]*w[k][j]>w[i][j])
						w[i][j]=w[i][k]*w[k][j];
		bool check=false;
		for(int i=0;i<n;i++)
			if(w[i][i]>1){
				check=1;
				break;
			}
		/*for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				printf("%.3lf ",w[i][j]);
			printf("\n");
		}*/
		if(check)	printf("Case %d: Yes\n",test++);
		else		printf("Case %d: No\n" ,test++);
		QQ.clear();
	}
}
