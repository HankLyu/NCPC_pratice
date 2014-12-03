#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;

int main()
{
	double x1,y1,x2,y2,x3,y3,x4,y4;
	int test;
	scanf("%d",&test);
	printf("INTERSECTING LINES OUTPUT\n");
	while(test--){
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf",
			&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
		if((y2-y1)*(x3-x4) == (y3-y4)*(x2-x1)){
			if((x2-x1)*(y3-y1)==(y2-y1)*(x3-x1))	printf("LINE\n");
			else printf("NONE\n");
		}
		else{
			double a,b,c,d,e,f;
			a=y2-y1, b=x2-x1;
			c=y4-y3, d=x4-x3;
			e=a*x1-b*y1;
			f=c*x3-d*y3;
			double x=(e*d-b*f)/(a*d-c*b);
			double y=-(a*f-c*e)/(a*d-c*b);
			printf("POINT %.2lf %.2lf\n",x,y);
		}
	}
	printf("END OF OUTPUT\n");
}
