#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){
	int test,a[3];
	scanf("%d",&test);
	while(test--){
		for(int i=0;i<3;i++)	scanf("%d",&a[i]);
		sort(a,a+3);
		if(a[0]+a[1]<=a[2])	printf("Wrong!!\n");
		else	printf("OK\n");
	}
	return 0;
}
