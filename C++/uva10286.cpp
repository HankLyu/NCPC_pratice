#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	double a;
	while(scanf("%lf",&a)!=EOF){
		printf("%.10lf\n",a*sin(M_PI*108/180)/sin(M_PI*63/180));
	}
	return 0;
}
