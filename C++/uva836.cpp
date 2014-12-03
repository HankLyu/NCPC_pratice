#include<iostream>
#include<cstdio>
#include<cstring>

#define maxx 30

using namespace std;

int main()
{
	int test,ans,row,column;
	char clear[3],map[maxx][maxx];
	int tmp[maxx];
	scanf("%d",&test);
	gets(map[0]);
	while(test--){
		gets(map[0]);
		gets(map[0]);
		row=column=strlen(map[0]);
		for(int i=1;i<row;i++)
			gets(map[i]);
		int ans=0,length,width,tmp;
		for(int i=0;i<row;i++){
			int sum[50]={};
			for(int j=i;j<row;j++){
				for(int k=0;k<column;k++){
					sum[k] +=map[j][k]-'0';
					if(k==0 || tmp != length*width)
						tmp=0,length=0;
						tmp += sum[k];
						length++,width=j-i+1;
						if(tmp==length*width)
							ans=max(ans,tmp);
				}
			}
		}
		printf("%d\n",ans);
		if(test)	printf("\n");
	}
	return 0;
}
