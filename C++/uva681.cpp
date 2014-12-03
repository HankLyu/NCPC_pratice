/*#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

#define maxx 1005
using namespace std;

struct node{
	int x,y;
}p[maxx],stack[maxx];
int n;
double cross(node o,node a,node b){
	return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
bool cmp(node a,node b){
	return (a.x<b.x || (a.x==b.x && a.y<b.y));
}
bool operator ==(const node &a,const node &b){
	return (a.x==b.x && a.y==b.y);
}
bool operator !=(const node &a,const node &b){
	return (a.x!=b.x || a.y!=b.y);
}
int main()
{
	int test,tmp,x,y;
	scanf("%d",&test);
	printf("%d\n",test);
	while(test--){
		scanf("%d",&n);
		int top=0;
		n--;
		for(int i=0;i<n;i++)
			scanf("%d %d",&p[i].x,&p[i].y);
		sort(p,p+n,cmp);
		if(p[n]==p[0])	n--;
		for(int i=0;i<n;i++){
			while(top>1 && cross(stack[top-2],stack[top-1],p[i])<0)
				top--;
			stack[top++]=p[i];
		}
		for(int i=n-2,k=top+1;i>=0;i--){
			while(top>=k && cross(stack[top-2],stack[top-1],p[i])<0)
				top--;
			stack[top++]=p[i];
		}
		scanf("%d %d",&x,&y);
		printf("%d\n",top);
		int first,x=2e9,y=2e9;
		for(int i=0;i<top;i++){
			if(stack[i].y<y){
				x=stack[i].x;
				y=stack[i].y;
				tmp=i;
			}
			else if(stack[i].y==y && stack[i].x<x){
				x=stack[i].x;
				tmp=i;
			}
		}
		int t=top;
		for(int i=tmp;t>1;t--,i++){
			printf("%d %d\n",stack[i].x,stack[i].y);
			if(i==top-1)	i=0;
			//if(time<1)	break;
		}
		if(stack[tmp]!=stack[tmp-1])
			printf("%d %d\n",stack[tmp].x,stack[tmp].y);
		if(test){
			printf("-1\n");
			scanf("%d",&n);
		}
	}
	return 0;
}*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>

#define maxP 300000
typedef struct {
    int x, y;
}Point;
Point P[maxP], CH[maxP<<1];
int cmp(const void *i, const void *j) {
    Point *a, *b;
    a = (Point *)i, b = (Point *) j;
    if(a->y != b->y)
        return a->y - b->y;
    return a->x - b->x;
}
int Cross(Point *o, Point *a, Point *b) {
    return (a->x - o->x)*(b->y - o->y) - (a->y - o->y)*(b->x - o->x);
}
void Print(int N, Point CH[]) {
    int i;
    for(i = 0; i < N; i++)
        printf("%d %d\n", CH[i].x, CH[i].y);
}
void ConvexHull(int N, Point P[]) {
    qsort(P, N, sizeof(Point), cmp);
    int i, m = 0, t;
    for(i = 0; i < N; i++) {
        while(m >= 2 && Cross(&CH[m-2], &CH[m-1], &P[i]) <= 0)
            m--;
        CH[m++] = P[i];
    }
    for(i = N-1, t = m+1; i >= 0; i--) {
        while(m >= t && Cross(&CH[m-2], &CH[m-1], &P[i]) <= 0)
            m--;
        CH[m++] = P[i];
    }
    printf("%d\n", m);
    Print(m, CH);
}
int main() {
    int K, N, i;
    scanf("%d", &K);
    printf("%d\n", K);
    while(K--) {
        scanf("%d", &N);
        for(i = 0; i < N; i++)
            scanf("%d %d", &P[i].x, &P[i].y);
        if(K)    scanf("%d", &i);
        ConvexHull(N, P);
        if(K)    puts("-1");
    }
    return 0;
}
