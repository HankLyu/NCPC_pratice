#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>

#define maxx 100005

using namespace std;

struct node
{
	double x1,y1,x2,y2;
	bool top;
	int name;
}tmp;
int len;
vector<node>s;

double cross(double x1,double y1,double x2,double y2)
{
	return x1*y2-x2*y1;
}
bool check(int j,int i)
{
	double d1,d2,d3,d4;
	d1=cross(s[j].x1-s[i].x1, s[j].y1-s[i].y1,
			 s[i].x2-s[i].x1, s[i].y2-s[i].y1);
	
	d2=cross(s[j].x2-s[i].x1, s[j].y2-s[i].y1,
			 s[i].x2-s[i].x1, s[i].y2-s[i].y1);
	
	d3=cross(s[i].x1-s[j].x1, s[i].y1-s[j].y1,
			 s[j].x2-s[j].x1, s[j].y2-s[j].y1);

	d4=cross(s[i].x2-s[j].x1, s[i].y2-s[j].y1,
			 s[j].x2-s[j].x1, s[j].y2-s[j].y1);
	if(d1*d2<=0 && d3*d4<=0){
		s.erase(s.begin()+j),len--;
		return true;
	}
	return false;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF && n){
		s.clear();
		for(int i=1;i<=n;i++){
			scanf("%lf %lf %lf %lf"
				,&tmp.x1, &tmp.y1, &tmp.x2, &tmp.y2);
			tmp.name=i;
			s.push_back(tmp);
			len=s.size();
			for(int j=0;j<len-1;j++){
				//printf("j=%d len-1=%d\n",j,len-1);
				if(check(j,len-1))	j--;
			}
		}
		printf("Top sticks:");
		int first=0;
		len=s.size();
		for(int i=0;i<len;i++){
		//	printf("%d ",s[i].top);
				if(first) printf(",");
				else first++;
				printf(" %d",s[i].name);
		//		ans.push_back(i);
		}
		printf(".\n");
	}
	return 0;
}
