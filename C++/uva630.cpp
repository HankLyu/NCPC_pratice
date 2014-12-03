#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>

#define maxx 1005

using namespace std;

char s[25],tmp[25];
vector<string>a[maxx];
map<string,int>qq;
int n,m;

int main()
{
	int test,len;
	scanf("%d",&test);
	while(test--){
		scanf("%d",&n);
		m=1;
		for(int i=0;i<n;i++){
			scanf("%s",s);
			strcpy(tmp,s);
			sort(tmp,tmp+strlen(tmp));
			if(qq[tmp]==0)	{
				qq[tmp]=m++;
			}
			//printf("s=%s %d\n",s,qq[tmp]);
			//printf("sort=%s\n",tmp);
			a[qq[tmp]].push_back(s);
		}
		/*for(int i=0;i<m;i++){
			for(int j=0;j<a[i].size();j++)
				cout<<a[i][j]<<endl;
			printf("\n");
		}*/
		while(scanf("%s",s)){
			if(strcmp("END",s)==0)	break;
			strcpy(tmp,s);
			sort(tmp,tmp+strlen(tmp));
			printf("Anagrams for: %s\n",s);
			if(qq[tmp]>0){
				len=a[ qq[tmp]].size();
				for(int i=0;i<len;i++){
					printf("%3d) ",i+1);
					cout<<a[qq[tmp]][i]<<endl;
				}
			}
			else printf("No anagrams for: %s\n",s);
		}
		qq.clear();
		for(int i=0;i<m;i++)	a[i].clear();
		if(test)	printf("\n");
	}
	return 0;
}
