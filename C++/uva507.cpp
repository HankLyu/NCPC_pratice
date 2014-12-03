#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	int t,test=0;
	scanf("%d",&t);
	while(t--){
		int tmp,r,x,ed,st=0xffff,ans=0,sum=0;
		scanf("%d",&r);
		for(int i=2;i<=r;i++){
			scanf("%d",&x);
			sum=sum+x;
			if(sum<0)	sum=0,tmp=i;
			if(sum>=ans){
				if(sum>ans){
					st=tmp;
					ed=i;
				}
				else if(tmp<=st){
					ed=i;
				}
				ans=sum;
			}
		}
		if(ans>0)
			printf("The nicest part of route %d is between stops %d and %d\n",++test,st,ed);
		else
			printf("Route %d has no nice parts\n",++test);
		
	}//while
	return 0;
}
