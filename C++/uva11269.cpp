#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

#define maxx 25

using namespace std;

struct job{
	int a,b;
}all[maxx],first[maxx],last[maxx];

bool fircmp(job a,job b){
	return a.a<b.a;
}
bool lascmp(job a,job b){
	return a.b>b.b;
}
int main(){
	int n,fn,ln;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%d",&all[i].a);
		for(int i=0;i<n;i++)
			scanf("%d",&all[i].b);
		fn=ln=0;
		for(int i=0;i<n;i++)
			if(all[i].a <= all[i].b)	first[fn++]=all[i];
			else						last[ln++]=all[i];
		sort(first,first+fn,fircmp);
		sort(last,last+ln,lascmp);
		int ans=0,delay=0,more=0;
		for(int i=0;i<fn-1;i++){
			ans+=first[i].a;
			//more+=first[i].b-first[i+1].a;
		}
		for(int i=0;i<fn-1;i++)	more+=first[i].b;
		for(int i=1;i<fn;i++)	delay+=first[i].a;
		if(ln==0)	{
			more-=delay;
			if(more<0)	more=0;
			ans+=first[fn-1].a+first[fn-1].b+more;
		}
		else{
			ans+=first[fn-1].a;
			more+=first[fn-1].b;
			for(int i=0;i<ln-1;i++){
				ans+=last[i].a;
			}
			for(int i=0;i<ln-1;i++)	more+=last[i].b;
			if(fn!=0)	delay+=last[0].a;
			for(int i=1;i<ln;i++)	{
				delay+=last[i].a;
			}
			ans+=last[ln-1].a+last[ln-1].b;
			//printf("ans=%d more=%d delay=%d\n",ans,more,delay);
			more-=delay;
			if(more<0)	more=0;
			ans+=more;
		}
		printf("%d\n",ans);
	}
	return 0;
}
