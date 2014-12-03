/*#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

#define maxx 1000
#define eps 1e-8

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
bool equal(point p1,point p2){
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
		if(cross1>eps || cross2 >eps){
			if(cross1*cross2<eps){
				l1=getline(p1,p2);
				l2=getline(tmp.p[i],tmp.p[i+1]);
				pot=getpoint(l1,l2);
				if(cross1<eps){
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
	int n,test=1;
	center ret;
	while(scanf("%d",&n)!=EOF && n){
		for(int i=0;i<n;i++)
			scanf("%lf %lf",&ret.p[i].x,&ret.p[i].y);
		ret.n=n;
		ret.p[n]=ret.p[0];
		tmp=ret;
		for(int i=0;i<n;i++)
			cut(ret.p[i],ret.p[i+1]);
		printf("Floor #%d\n",test++);
		if(tmp.n>0)	printf("Surveillance is possible.\n\n");
		else		printf("Surveillance is impossible.\n\n");
	}
	return 0;
}*/
#include<cmath> 
#include<stdio.h> 
#include<algorithm> 
 
using namespace std; 
 
struct Point { 
	double x, y; 
} point[105]; //原始节点 
 
Point p[105];//保存新切割出的多边形 
Point q[105];//临时保存新切割的多边形 
 
int n, m; 
double a, b, c;//直线 ax + by + c == 0 
 
void lineFromSegment(Point p1, Point p2) { 
	//线段所在直线,返回直线方程的三个系数 
	a = p2.y - p1.y; 
	b = p1.x - p2.x; 
	c = p2.x * p1.y - p1.x * p2.y; 
} 
Point intersect(Point x, Point y) { 
	double u = fabs(a * x.x + b * x.y + c); 
	double v = fabs(a * y.x + b * y.y + c); 
	Point ans; 
	ans.x = (x.x * v + y.x * u) / (u + v); 
	ans.y = (x.y * v + y.y * u) / (u + v); 
	return ans; 
}//获取直线ax+by+c==0  和点x和y所连直线的交点 
 
int cut(){ 
	int np = 0, i; 
	for( i = 0 ; i < m ; i++) { 
		if( p[i].x *a + p[i].y *b + c >= 0)  //题目输入是顺时针方向故大于号  
			q[np++] = p[i]; //某点在该直线割后的多边形内，则保存该点 
		else { 
			if( p[(i + m - 1) % m].x * a + p[(i + m - 1) % m].y * b + c > 0 )// 
				q[np++] = intersect(p[i], p[(i + m - 1) % m]); 
			if( p[(i + 1) % m].x * a + p[(i + 1) % m].y * b + c > 0 ) 
				q[np++] = intersect(p[i], p[(i + 1) % m]); 
		}//如果该点在外，看是该点的相邻两边是否存在与割线的交点，有交点保存割边上的交点 
	} 
	for( i = 0 ; i < np ; i++) 
		p[i] = q[i];//更新切割后的多边形顶点 
	m = np; 
	return 0; 
}  
int find_nucleus() { 
	int i, j; 
	for( i = 0; i < n; i++) 
		p[i] = point[i]; 
	m = n; 
	for( i = 0 ; i < n ; i++) { 
		lineFromSegment(point[i], point[(i + 1) % n]); 
		cut(); 
	} 
	return 0; 
} 
int main() 
{
	int i, k; 
	k = 1; 
	while(scanf("%d", &n)&& n) { 
		for( i = 0 ; i < n ; i++) 
			scanf("%lf%lf", &point[i].x, &point[i].y); 
		find_nucleus();  
		printf("Floor #%d\n", k++); 
		printf("%s\n\n", m == 0 ? "Surveillance is impossible." : "Surveillance is possible."); 
	} 
	return 0; 
} 
