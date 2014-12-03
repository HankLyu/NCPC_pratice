#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){
	double a[3];
	while(scanf("%lf %lf %lf",&a[0],&a[1],&a[2])!=EOF){
		sort(a,a+3);
		if(a[0]+a[1]<=a[2]){
			printf("%.3lf\n",-1.0);
			continue;
		}
		for(int i=0;i<3;i++)
			a[i]=a[i]*2/3;
		double s=(a[0]+a[1]+a[2])/2;
		printf("%.3lf\n",3*sqrt(s*(s-a[0])*(s-a[1])*(s-a[2])));
	}
	return 0;
}
