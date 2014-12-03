#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

bool isans(int i,int n)
{
	int tmp=i/n;
	int a[10]={0};
	if(i<10000)		a[0]++;
	if(tmp<10000)	a[0]++;
	if(tmp<1000)	return false;
	if(a[0]>1)	return false;
	while(i>0){
		a[i%10]++;
		if(a[i%10]>1)	return false;
		i=i/10;
	}
	while(tmp>0){
		a[tmp%10]++;
		if(a[tmp%10]>1)	return false;
		tmp /=10;
	}
	return true;
}
int main()
{
	int n,first=0;
	while(scanf("%d",&n)!=EOF && n){
		bool check=0;
		if(first)	printf("\n");
		else	first++;
		for(int i=1234;i<99999;i++)
			if(i%n==0)
				if(isans(i,n)){
					printf("%05d / %05d = %d\n",i,i/n,n);
					check=1;
				}
		if(check==0)	printf("There are no solutions for %d.\n",n);
	}
}
