#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main(){
	double a,b,c;
	while(scanf("%lf %lf %lf",&a,&b,&c)!=EOF){
		double s=(a+b+c)/2.0;
		double at=sqrt(s*(s-a)*(s-b)*(s-c));
		double rin=2.0*at/(a+b+c);
		double rout=a*b*c/4.0/at;
		printf("%.4lf %.4lf %.4lf\n",acos(-1)*rout*rout-at,
			at-acos(-1)*rin*rin,acos(-1)*rin*rin);
	}
	return 0;
}
