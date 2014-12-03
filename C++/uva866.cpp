#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>

#define maxx 10000

using namespace std;

struct node
{
	double x,y;
	bool operator<(const node&t)const{
		return x<t.x;
	}
}tmp;
struct node2
{
	double x1,y1,x2,y2;
}l[maxx];

map<node,int> qq;
vector<node>p;
int ans,n;

bool check(double x,double y,node2 l)
{
	if( min(l.x1,l.x2)<=x && x<=max(l.x1,l.x2) &&
		min(l.y1,l.y2)<=y && y<=max(l.y1,l.y2))
		return true;
	return false;
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		scanf("%d",&n);
		ans=n;
		for(int i=0;i<n;i++)
			scanf("%lf %lf %lf %lf",
				&l[i].x1, &l[i].y1, &l[i].x2, &l[i].y2);
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++){
				double a,b,c,d,e,f;
				a=l[i].y2-l[i].y1, b=l[i].x1-l[i].x2;
				c=l[j].y2-l[j].y1, d=l[j].x1-l[j].x2;
				e=a*l[i].x1+b*l[i].y1;
				f=c*l[j].x1+d*l[j].y1;
				if(a*d != c*b){
					double x=(e*d-b*f)/(a*d-b*c);
					double y=(a*f-e*c)/(a*d-b*c);
					if(check(x,y,l[i]) && check(x,y,l[j])){
						tmp.x=x,tmp.y=y;
						if(qq[tmp]==1)
							ans++;
						else{
							qq[tmp]++;
							ans+=2;
						}
					}
				}
			}
		printf("%d\n",ans);
		qq.clear();
		p.clear();
		if(test)	printf("\n");
	}
	return 0;
}
