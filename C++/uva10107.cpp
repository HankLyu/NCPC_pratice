#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define maxx 10005
using namespace std;

int num[maxx];
int n;

int main()
{
	n=0;
	while(scanf("%d",&num[n++])!=EOF){
		sort(num,num+n);
		if(n%2==1)	printf("%d\n",num[n/2]);
		else{
			printf("%d\n",(num[n/2]+num[n/2-1])/2);
		}
	}
	return 0;
}
