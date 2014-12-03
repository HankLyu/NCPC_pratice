#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

#define pi acos(-1)

using namespace std;

int main(){
	double D,V;
	while(scanf("%lf %lf",&D,&V)){
		if(D==0 && V==0)	break;
		//printf("%lf %lf\n",D,V);
		//printf("pi=%lf\n",pi);
		double ans=pow((pi*D*D*D-6*V)/pi ,1.0/3.0);
		printf("%.3lf\n",ans);
	}
	return 0;
}
