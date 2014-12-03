#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

#define pi 2.0*acos(0)
#define eps 1e-9

using namespace std;

int main(){
	double d,l;
	int test;
	scanf("%d",&test);
	while(test--){
		scanf("%lf %lf",&d,&l);
		double a=l/2.0;
		double b=sqrt(l*l/4.0-d*d/4.0);
		//printf("%.3lf %.3lf  ",a,b);
		printf("%.3lf\n",pi*a*b);
	}
	return 0;
}
