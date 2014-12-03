#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

struct node
{
	int x1,y1,x2,y2;
}line[5];

int cross(int x1,int y1,int x2,int y2)
{
	return x1*y2-x2*y1;
}
bool onsegment(int x1,int y1,int x2,int y2,int x3,int y3)
{
	if(min(x2,x3)<=x1 && x1<=max(x2,x3) &&
		min(y2,y3)<=y1 && y1<=max(y2,y3))
		return true;
	return false;
}
bool check(int j,int i)
{
	int d1,d2,d3,d4;
	d1=cross(line[j].x1-line[i].x1, line[j].y1-line[i].y1,
			 line[i].x2-line[i].x1, line[i].y2-line[i].y1);

	d2=cross(line[j].x2-line[i].x1, line[j].y2-line[i].y1,
			 line[i].x2-line[i].x1, line[i].y2-line[i].y1);

	d3=cross(line[i].x1-line[j].x1, line[i].y1-line[j].y1,
			 line[j].x2-line[j].x1, line[j].y2-line[j].y1);

	d4=cross(line[i].x2-line[j].x1, line[i].y2-line[j].y1,
			 line[j].x2-line[j].x1, line[j].y2-line[j].y1);
	//printf("d1*d2=%d d3*d4=%d\n",d1*d2,d3*d4);
	if(d1*d2<0 && d3*d4<0)	return true;
	if(d1==0 && onsegment(line[j].x1,line[j].y1,
						  line[i].x1,line[i].y1,
						  line[i].x2,line[i].y2))
		return true;
	if(d2==0 && onsegment(line[j].x2,line[j].y2,
						  line[i].x1,line[i].y1,
						  line[i].x2,line[i].y2))
		return true;
	if(d3==0 && onsegment(line[i].x1,line[i].y1,
						  line[j].x1,line[j].y1,
						  line[j].x2,line[j].y2))
		return true;
	if(d4==0 && onsegment(line[i].x2,line[i].y2,
						  line[j].x1,line[j].y1,
						  line[j].x2,line[j].y2))
		return true;
	return false;
}
int main()
{
	int test;
	int a,b,c,d;
	scanf("%d",&test);
	while(test--){
		scanf("%d %d %d %d %d %d %d %d",
			&line[0].x1, &line[0].y1, &line[0].x2, &line[0].y2,
			&a,&b,&c,&d);
			//if(a>c)	swap(a,c);
			//if(b<d)	swap(b,d);
		line[1].x1=a, line[1].y1=b, line[1].x2=c, line[1].y2=b;
		line[2].x1=a, line[2].y1=b, line[2].x2=a, line[2].y2=d;
		line[3].x1=a, line[3].y1=d, line[3].x2=c, line[3].y2=d;
		line[4].x1=c, line[4].y1=b, line[4].x2=c, line[4].y2=d;
		bool ans=0;
		for(int i=1;i<5;i++)
			if(check(0,i)==true){
				//printf("%d do\n",i);
				ans=1;
				break;
			}
		if(min(a,c)<=line[0].x1 && line[0].x1<=max(a,c) &&
			min(b,d)<=line[0].y1 && line[0].y1<=max(b,d))
				ans=1;
		else if(min(a,c)<=line[0].x2 && line[0].x2<=max(a,c) &&
				min(b,d)<=line[0].y2 && line[0].y2<=max(b,d))
			ans=1;
		if(ans)	printf("T\n");
		else	printf("F\n");
	}
}
