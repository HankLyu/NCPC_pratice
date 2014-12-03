#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

#define pi 2.0*acos(0)

using namespace std;

int main(){
	int n;
	double area;
	int test=1;
	while(scanf("%d %lf",&n,&area)!=EOF){
		if(n<3)	break;
		double rout=sqrt(2.0*area/sin(2.0*pi/n)/n);
		double rin=rout*cos(pi/n);
		double aout=rout*rout*pi;
		double ain=rin*rin*pi;
		//printf("rout= %lf rin= %lf\n",rout,rin);
		printf("Case %d: %.5lf %.5lf\n",test++,aout-area,area-ain);
	}
	return 0;
}
