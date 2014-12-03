#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

#define maxx 100
#define eps 1e-8

using namespace std;

struct node{
	double x,y;
};
struct center{
	int n;
	node p[maxx];
}tmp;
struct line{
	double a,b,c;
};
double cross(node o,node a,node b){
	return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
line getline(node a,node b){
	line l;
	l.a=a.y-b.y;
	l.b=b.x-a.x;
	l.c=l.a*a.x+l.b*a.y;
	return l;
}
node getpoint(line l1,line l2){
	double d;
	node p;
	d=l1.a*l2.b-l1.b*l2.a+eps;
	p.x=(l1.c*l2.b-l2.c*l1.b)/d;
	p.y=(l1.a*l2.c-l2.a*l1.c)/d;
	return p;
}
bool equal(node p1,node p2){
	return fabs(p1.x-p2.x)<eps && fabs(p1.y-p2.y)<eps;
}
void cut(node p1,node p2){
	int c=0;
	double cross1,cross2;
	center newret;
	node pot,pre;
	line l1,l2;
	for(int i=0;i<tmp.n;i++){
		cross1=cross(p1,p2,tmp.p[i]);
		cross2=cross(p1,p2,tmp.p[i+1]);
		if(cross1>0 || cross2>0){
			if(cross1*cross2<0){
				l1=getline(p1,p2);
				l2=getline(tmp.p[i],tmp.p[i+1]);
				pot=getpoint(l1,l2);
				if(cross1<0){
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
int main()
{
	int n;
	center ret;
	while(scanf("%d",&n)!=EOF && n){
		for(int i=n-1;i>=0;i--)
			scanf("%lf %lf",&ret.p[i].x,&ret.p[i].y);
		ret.n=n;
		ret.p[n]=ret.p[0];
		tmp=ret;
		for(int i=0;i<n;i++)
			cut(ret.p[i],ret.p[i+1]);
		if(tmp.n==0)	printf("0\n");
		else	printf("1\n");
	}
	return 0;
}
