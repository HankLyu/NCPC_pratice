#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int test,n;
	scanf("%d",&test);
	while(test--){
		vector<int>ans;
		scanf("%d",&n);
		int a[10]={0};
		if(n==1)	printf("1\n");
		else{
			for(int i=2;i<10;i++)
				while(n%i==0){
					a[i]++;
					n/=i;
				}
			if(n!=1)	printf("-1\n");
			else{
				int tmp=1;
				for(int i=2;i<10;){
					//printf("tmp=%d i=%d\n",tmp,i);
					if(tmp*i<10){
						if(a[i]>0){
							tmp *= i;
							a[i]--;
						}
						else	i++;
					}
					else{
						//printf("tmp=%d\n",tmp);
						ans.push_back(tmp);
						tmp=1;
						//i++;
					}
				}
				sort(ans.begin(),ans.end());
				tmp=ans.size();
				for(int i=0;i<tmp;i++)
					printf("%d",ans[i]);
				printf("\n");
			}
		}
	}
	return 0;
}
