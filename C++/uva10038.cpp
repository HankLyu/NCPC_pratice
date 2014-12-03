#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

#define maxx 3005

using namespace std;

int main()
{
	int n,use[maxx],tmp;
	int num[maxx];
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%d",&num[i]);
		memset(use,0,sizeof(use));
		bool check=1;
		for(int i=1;i<n;i++){
			tmp=abs(num[i]-num[i-1]);
			if(tmp<n){
				use[tmp]++;
				if(use[tmp]>1){
					check=0;
					break;
				}
			}
			else{
				check=0;
				break;
			}
		}
		if(check)	printf("Jolly\n");
		else		printf("Not jolly\n");
	}
	return 0;
}
