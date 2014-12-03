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

bool operator ==(point a,point b){
	return fabs(a.x-b.x)<eps && fabs(a.y-b.y)<eps;
}
line getline(point a,point b,point c){
	line l;
	l.a=a.y-b.y;
	l.b=b.x-a.x;
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
	point p[4];
	line l1,l2;
	while(scanf("%lf %lf",&p[0].x,&p[0].y)!=EOF){
		int pnum=1,inter;
		for(int i=1;i<4;i++){
			scanf("%lf %lf",&p[pnum].x,&p[pnum].y);
			for(int j=0;j<pnum;j++)
				if(p[pnum]==p[j]){
					//printf("%.3lf %.3lf %.3lf %.3lf\n",
					//	p[pnum].x,p[pnum].y,p[j].x,p[j].y);
					inter=j;
					pnum--;
				}
			pnum++;
		}
		//for(int i=0;i<pnum;i++)
		//	printf("%.3lf %.3lf\n",p[i].x,p[i].y);
		int a=(inter+1)%3,b=(inter-1)%3;
		if(b<0)	b+=3;
		//printf("%d %d %d\n",inter,a,b);
		l1=getline(p[inter],p[a],p[b]);
		l2=getline(p[inter],p[b],p[a]);
		p[3]=getpoint(l1,l2);
		if(fabs(p[3].x)<eps)	p[3].x=0;
		if(fabs(p[3].y)<eps)	p[3].y=0;
		printf("%.3lf %.3lf\n",p[3].x,p[3].y);
	}
	return 0;
}
