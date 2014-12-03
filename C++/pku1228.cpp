#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

#define maxx 1005
#define eps 1e-8

using namespace std;

struct node{
	double x,y;
};
bool cmp(node a,node b){
	if(fabs(a.y-b.y)<=eps)
		return a.x<b.x;
	return a.y<b.y;
}
double cross(node o,node a,node b){
	return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
int scan(node p[],int n,node res[]){
	int top;
	sort(p,p+n,cmp);
	if(n<0)	return 0;
	res[0]=p[0];
	if(n==1)	return 1;
	res[1]=p[1];
	if(n==2)	return 2;
	
	top=1;
	for(int i=2;i<n;i++){
		while(top>=1 && cross(res[top],res[top-1],p[i])<0)	top--;
		res[++top]=p[i];
	}
	for(int i=n-2;i>=0;i--){
		while(top>=1 && cross(res[top],res[top-1],p[i])<0)	top--;
		res[++top]=p[i];
	}
	return top;
}
node p[maxx],res[maxx];
bool solve(int n){
	bool flag=false;
	bool mark=false;
	for(int i=2;i<n+2;i++){
		if(cross(res[(i-2+n)%n],res[(i-1+n)%n],res[i%n])!=0){
			if(flag==false)	return false;
			flag=false;
			mark=true;
		}
		else flag=true;
	}
	if(!mark)	return false;
	return true;
}
int main()
{
	int test,n;
	scanf("%d",&test);
	while(test--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%lf %lf",&p[i].x,&p[i].y);
		int ret=scan(p,n,res);
		if(solve(ret))	printf("YES\n");
		else	printf("NO\n");
	}
}
