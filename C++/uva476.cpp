#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

#define maxx 15
#define eps 1e-6

using namespace std;

struct rec{
	double  x1,x2,y1,y2;
}r[maxx];

bool checkin(double x,double y,rec r){
	if(min(r.x1,r.x2)<x && x<max(r.x1,r.x2) &&
		min(r.y1,r.y2)<y && y<max(r.y1,r.y2))
		return true;
	return false;
}
int main(){
	char s[maxx];
	double x,y;
	while(scanf("%s",s)!=EOF){
		int rnum=0,pnum=1;
		if(s[0]=='r'){
			scanf("%lf %lf %lf %lf",&r[rnum].x1,&r[rnum].y1,
				&r[rnum].x2,&r[rnum].y2);
			rnum++;
		}
		while(scanf("%s",s) && s[0]=='r'){
			scanf("%lf %lf %lf %lf",&r[rnum].x1,&r[rnum].y1,
				&r[rnum].x2,&r[rnum].y2);
			rnum++;
		}
		while(scanf("%lf %lf",&x,&y)){
			if(fabs(x-9999.9)<eps && fabs(y-9999.9)<eps)	break;
			bool check=true;
			for(int i=0;i<rnum;i++)
				if(checkin(x,y,r[i])){
					printf("Point %d is contained in figure %d\n",pnum,i+1);
					check=false;
				}
			if(check)
				printf("Point %d is not contained in any figure\n",pnum);
			pnum++;
		}
	}
	return 0;
}
