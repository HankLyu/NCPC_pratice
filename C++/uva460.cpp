#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){
	int test,a[4],b[4];
	scanf("%d",&test);
	while(test--){
		scanf("%d %d %d %d",&a[0],&b[0],&a[1],&b[1]);
		scanf("%d %d %d %d",&a[2],&b[2],&a[3],&b[3]);
		if(a[2]>=a[1] || a[0]>=a[3] || b[2]>=b[1] || b[0]>=b[3])
			printf("No Overlap\n");
		else{
		sort(a,a+4);
		sort(b,b+4);
		printf("%d %d %d %d\n",a[1],b[1],a[2],b[2]);
		}
		if(test)	printf("\n");
	}
	return 0;
}
