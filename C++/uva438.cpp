#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

#define pi 3.141592653589793
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
	c.x=(a.x+b.x)/2; c.y=(a.y+b.y)/2;
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
	double diameter;
	point p1,p2,p3,ansp;
	line l1,l2;
	while(scanf("%lf %lf %lf %lf %lf %lf",
		&p1.x,&p1.y, &p2.x,&p2.y, &p3.x,&p3.y)!=EOF){
		l1=getline(p1,p2);
		l2=getline(p1,p3);
		//printf("%.2lf %.2lf %.2lf\n%.2lf %.2lf %.2lf\n",
		//	l1.a,l1.b,l1.c, l2.a,l2.b,l2.c);
		ansp=getpoint(l1,l2);
		//if(abs(ansp.x)<eps)	ansp.x=0;
		//if(abs(ansp.y)<eps)	ansp.y=0;
		//printf("point %lf %lf\n",ansp.x,ansp.y);
		diameter=dis(ansp,p1);
		printf("%.2lf\n",2*diameter*pi,diameter);
	}
	return 0;
}
