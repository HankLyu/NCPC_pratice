#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>

#define pi acos(-1)

using namespace std;

int main(){
	double dis,dre;
	char s[10];
	while(scanf("%lf %lf %s",&dis,&dre,s)!=EOF){
		//printf("dre=%.3lf\n",dre);
		dre=abs(dre);
		if(dre>180)	dre=360-dre;
		if(strcmp(s,"deg")==false)	dre=dre*pi/180.0;
		else	dre=dre/180.0/60.0*pi;
		dis+=6440.0;
		//printf("dre=%.3lf\n",dre);
		printf("%.6lf %.6lf\n",dre*dis,2*dis*sin(dre/2.0));
	}
	return 0;
}
