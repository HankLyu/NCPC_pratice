#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

#define eps 1e-15
#define maxx 3005

using namespace std;

struct point{
	double x,y;
};
struct center{
	int n;
	point p[maxx];
}tmp;
struct line{
	double a,b,c;
};
double cross(point o,point a,point b){
	return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
line getline(point p1,point p2){
	line l;
	l.a=p1.y-p2.y;
	l.b=p2.x-p1.x;
	l.c=l.a*p1.x+l.b*p1.y;
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
int equal(point p1,point p2){
	return fabs(p1.x-p2.x)<eps && fabs(p1.y-p2.y)<eps;
}
void cut(point p1,point p2){
	int c=0;
	double cross1,cross2;
	center newret;
	point pot,pre;
	line l1,l2;
	for(int i=0;i<tmp.n;i++){
		cross1=cross(p1,p2,tmp.p[i]);
		cross2=cross(p1,p2,tmp.p[i+1]);
		if(cross1>0.0 || cross2>0.0){
			if(cross1*cross2<0){
				l1=getline(p1,p2);
				l2=getline(tmp.p[i],tmp.p[i+1]);
				pot=getpoint(l1,l2);
				if(cross1<0.0){
					newret.p[c++]=tmp.p[i];
					newret.p[c++]=pot;
				}
				else{
					newret.p[c++]=pot;
					newret.p[c++]=tmp.p[i+1];
				}
			}
		}
		else{
			newret.p[c++]=tmp.p[i];
			newret.p[c++]=tmp.p[i+1];
		}
	}
	int j=1;
	tmp.p[0]=pre=newret.p[0];
	for(int i=1;i<c;i++)
		if(!equal(newret.p[i-1],newret.p[i]))
			tmp.p[j++]=newret.p[i];
	if(equal(tmp.p[j-1],tmp.p[0]))	j--;
	tmp.p[j]=tmp.p[0];
	tmp.n=j;
}
double area(){
	double sum=0;
	for(int i=0;i<tmp.n;i++)
		sum+=tmp.p[i].x*tmp.p[i+1].y-tmp.p[i].y*tmp.p[i+1].x;
	return fabs(sum/2);
}
int main()
{
	int test,n;
	center ret;
	scanf("%d",&test);
	while(test--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%lf %lf",&ret.p[i].x, &ret.p[i].y);
		ret.n=n;
		ret.p[n]=ret.p[0];
		tmp=ret;
		for(int i=0;i<n;i++)
			cut(ret.p[i],ret.p[i+1]);
		printf("%.2lf\n",area());
	}
	return 0;
}
