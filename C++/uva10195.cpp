#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

int main(){
	double l1,l2,l3;
	double s,p,r;
	while(scanf("%lf %lf %lf",&l1,&l2,&l3)!=EOF){
		p=(l1+l2+l3)/2;
		s=sqrt(p*(p-l1)*(p-l2)*(p-l3));
		if(l1 && l2 && l3)
			r=2*s/(l1+l2+l3);
		else r=0;
		printf("The radius of the round table is: %.3lf\n",r);
	}
	return 0;
}
