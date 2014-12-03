#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){
	int r,a;
	while(scanf("%d %d",&r,&a)!=EOF){
		printf("%.3lf\n",r*r*sin(2*M_PI/a)*a/2);
	}
	return 0;
}
