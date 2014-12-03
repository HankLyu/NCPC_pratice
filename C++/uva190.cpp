#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

#define eps 1e-9

using namespace std;

struct point{
	double x,y;
};
struct line{
	double a,b,c;
};

double dis(point a,point b){
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
line getline(point a,point b){
	line l;
	point c;
	c.x=(a.x+b.x)/2;
	c.y=(a.y+b.y)/2;
	l.a=a.x-b.x;
	l.b=a.y-b.y;
	l.c=l.a*c.x+l.b*c.y;
	return l;
}
point getpoint(line l1,line l2){
	double d;
	point p;
	d=l1.a*l2.b-l1.b*l2.a+eps;
	p.x=(l1.c*l2.b-l2.c*l1.b)/d;
	p.y=(l1.a*l2.c-l2.a*l1.c)/d;
	return p;
}
int main(){
	point p1,p2,p3,center;
	line l1,l2;
	double r,c,d,e;
	while(scanf("%lf %lf %lf %lf %lf %lf",
		&p1.x,&p1.y,	&p2.x,&p2.y,	&p3.x,&p3.y) != EOF){
		l1=getline(p1,p2);
		l2=getline(p1,p3);
		center=getpoint(l1,l2);
		r=dis(center,p1);
		c=-2*center.x;
		d=-2*center.y;
		e=pow(center.x,2)+pow(center.y,2)-r*r;
		printf("(x ");
		if(center.x > -eps)	printf("- %.3lf",abs(center.x));
		else				printf("+ %.3lf",abs(center.x));
		printf(")^2 + (y ");
		if(center.y > -eps)	printf("- %.3lf",abs(center.y));
		else				printf("+ %.3lf",abs(center.y));
		printf(")^2 = %.3lf^2\n",r);
		printf("x^2 + y^2 ");
		if(c>-eps)	printf("+ %.3lfx ",abs(c));
		else		printf("- %.3lfx ",abs(c));
		if(d>-eps)	printf("+ %.3lfy ",abs(d));
		else		printf("- %.3lfy ",abs(d));
		if(e>-eps)	printf("+ %.3lf",abs(e));
		else		printf("- %.3lf",abs(e));
		printf(" = 0\n\n");
	}
	return 0;
}
