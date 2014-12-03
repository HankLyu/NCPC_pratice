#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	int n,t,cow[25010][2],chore[1000000];
	int end=1;
	while(scanf("%d %d",&n,&t)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%d %d",&cow[i][0],&cow[i][1]);
		while(1){
			int check=1;
			
			for(int i=1;i<=t;i++)
				if(chore[i]==0){
					check=0;
					break;
				}
			if(check)	break;
		}
	}
	return 0;
}
