#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

#define maxx 15
#define eps 1e-9

using namespace std;

struct figure{
	int type;
	double x1,y1,x2,y2,x3,y3;
	double h,k,r;
}f[maxx];

bool checkin(double x,double y,figure f){
	if(f.type==1){
		if(min(f.x1,f.x2)<x && x<max(f.x1,f.x2) &&
			min(f.y1,f.y2)<y && y<max(f.y1,f.y2))
			return true;
	}
	if(f.type==2){
		double dis=sqrt(pow(x-f.h,2)+pow(y-f.k,2));
		if(dis<f.r)	return true;
	}
	if(f.type==3){
		//printf("do\n");
		double a0=0,a1=0,a2=0,a3=0;
		a0=fabs((f.x2-f.x1)*(f.y3-f.y1)-(f.y2-f.y1)*(f.x3-f.x1))/2;
		a1=fabs((f.x2-f.x1)*(   y-f.y1)-(f.y2-f.y1)*(   x-f.x1))/2;
		a2=fabs((   x-f.x1)*(f.y3-f.y1)-(   y-f.y1)*(f.x3-f.x1))/2;
		a3=fabs((f.x2-   x)*(f.y3-   y)-(f.y2-   y)*(f.x3-   x))/2;
		if(a1<eps || a2<eps || a3<eps)	return false;
		if(fabs(a1+a2+a3-a0)<eps)	return true;
	}
	return false;
}
int main(){
	char s[maxx];
	int fnum=0,pnum=1;
	double x,y;
	while(scanf("%s",s) && s[0]!='*'){
		if(s[0]=='r'){
			f[fnum].type=1;
			scanf("%lf %lf %lf %lf",
				&f[fnum].x1,&f[fnum].y1,&f[fnum].x2,&f[fnum].y2);
			fnum++;
		}
		if(s[0]=='c'){
			f[fnum].type=2;
			scanf("%lf %lf %lf",
				&f[fnum].h,&f[fnum].k,&f[fnum].r);
			fnum++;
		}
		if(s[0]=='t'){
			f[fnum].type=3;
			scanf("%lf %lf %lf %lf %lf %lf",
				&f[fnum].x1,&f[fnum].y1,	&f[fnum].x2,&f[fnum].y2,
				&f[fnum].x3,&f[fnum].y3);
			fnum++;
		}
	}
	while(scanf("%lf %lf",&x,&y)!=EOF){
		if(fabs(x-9999.9)<eps &&fabs(y-9999.9)<eps)	break;
		bool check=true;
		for(int i=0;i<fnum;i++)
			if(checkin(x,y,f[i])){
				printf("Point %d is contained in figure %d\n",pnum,i+1);
				check=false;
			}
			if(check)
				printf("Point %d is not contained in any figure\n",pnum);
			pnum++;
	}
	return 0;
}
