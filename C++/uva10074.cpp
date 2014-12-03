#include<iostream>
#include<cstdio>
#include<cstring>

#define maxx 105

using namespace std;

int main()
{
	int n,m;
	int map[maxx][maxx],ans,tmp,length,width;
	while(scanf("%d %d",&n,&m)!=EOF){
		if(n==0 && m==0)	break;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",&map[i][j]);
		ans=0;
		for(int i=0;i<n;i++){
			int sum[maxx]={0};
			for(int j=i;j<n;j++)
				for(int k=0;k<m;k++){
					sum[k]+=!map[j][k];
					if(k==0 || tmp!=length*width)
						tmp=0,length=0;
					length++,width=j-i+1;
					tmp += sum[k];
					if(tmp==length*width)
						ans=max(ans,tmp);
				}
		}
		printf("%d\n",ans);
	}
	return 0;
}
