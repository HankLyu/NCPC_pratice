#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define maxx 55

using namespace std;

struct node{
	int x, y;
}p[maxx];

double cross(node a,node b){
	return a.x*b.y-b.x*a.y;
}
bool cmp(node a,node b){
	return cross(a,b)>0;
}
int main()
{
	int n=0,a,b;
	node ori;
	scanf("%d %d",&ori.x,&ori.y);
	while(scanf("%d %d",&a,&b)!=EOF){
			p[n].x=a-ori.x;
			p[n].y=b-ori.y;
		n++;
	}
	sort(p,p+n,cmp);
	printf("(%d,%d)\n",ori.x,ori.y);
	for(int i=0;i<n;i++)
		printf("(%d,%d)\n",p[i].x+ori.x,p[i].y+ori.y);
	return 0;
}
