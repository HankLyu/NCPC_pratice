#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>

#define maxx 1000005

using namespace std;

struct node{
	int x,y;
}tmp;
vector<node>p;
void move(char s){
	switch (s){
		case '8':	tmp.y++;	p.push_back(tmp);	break;
		case '2':	tmp.y--;	p.push_back(tmp);	break;
		case '6':	tmp.x++;	p.push_back(tmp);	break;
		case '4':	tmp.x--;	p.push_back(tmp);	break;
		case '9':	tmp.y++;	tmp.x++;	p.push_back(tmp);	break;
		case '7':	tmp.y++;	tmp.x--;	p.push_back(tmp);	break;
		case '3':	tmp.y--;	tmp.x++;	p.push_back(tmp);	break;
		case '1':	tmp.y--;	tmp.x--;	p.push_back(tmp);	break;
		default: break;
	}
}
long long int cross(node a,node b){
	return a.x*b.y-a.y*b.x;
}
int main()
{
	int test;
	char s[maxx];
	scanf("%d",&test);
	while(test--){
		scanf("%s",s);
		p.clear();
		int len=strlen(s);
		tmp.x=0,tmp.y=0;
		for(int i=0;i<len-1;i++)
			move(s[i]);
		len=p.size();
		len--;
		long long int area=0.0,ans;
		for(int i=0;i<len;i++)
			area+=cross(p[i],p[i+1]);
		if(area<0)	area=-area;
		if(area%2==0)	printf("%lld\n",area/2);
		else	printf("%lld.5\n",area/2);
		/*area=abs(area)/2;
		ans=(int)area;
		if(fabs(area-ans)<2e-10)
			printf("%d\n",(int)ans);
		else{
			ans+=0.5;
			printf("%.1lf\n",ans);
		}*/
	}
	return 0;
}
