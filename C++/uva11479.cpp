#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){
	int test;
	long long int a[3];
	scanf("%d",&test);
	for(int t=1;t<=test;t++){
		printf("Case %d: ",t);
		for(int i=0;i<3;i++)	scanf("%lld",&a[i]);
		sort(a,a+3);
		if(a[0]+a[1]<=a[2])	
			printf("Invalid\n");
		else if(a[0]==a[1] && a[1]==a[2])
			printf("Equilateral\n");
		else if(a[0]==a[1] || a[1]==a[2])
			printf("Isosceles\n");
		else 
			printf("Scalene\n");
	}
	return 0;
}
