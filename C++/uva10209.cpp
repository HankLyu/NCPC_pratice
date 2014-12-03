#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

const double pi=3.141592653589793;

int main()
{
	double a;
	while(scanf("%lf",&a)!=EOF){
		printf("%.3lf %.3lf %.3lf\n",
			(1+pi/3-sqrt(3.0))*a*a,
			(pi/12+sqrt(3.0)/2-1)*a*a*4,
			(-pi/6+1-sqrt(3.0)/4)*a*a*4);
	}
	return 0;
}
