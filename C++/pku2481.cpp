#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

#define maxx 100005

using namespace std;

struct node{
	int s,e,id;
}cow[maxx];
int s[maxx],n;
int ans[maxx];

bool cmp(node a,node b){
	return a.e>b.e || (a.e==b.e && a.s<b.s);
}
int lowbit(int x){
	return x&(-x);
}
void change(int end,int delta){
	for(int i=end;i<maxx;i+=lowbit(i))
		s[i]+=delta;
}
int getsum(int end){
	int tmp=0;
	for(int i=end;i>0;i-=lowbit(i))
		tmp+=s[i];
	return tmp;
}

int main()
{
	while(scanf("%d",&n)!=EOF && n){
		for(int i=0;i<n;i++){
			scanf("%d %d",&cow[i].s,&cow[i].e);
			cow[i].s++,cow[i].e++;
			cow[i].id=i;
		}
		sort(cow,cow+n,cmp);
		memset(s,0,sizeof(s));
		memset(ans,0,sizeof(ans));
		for(int i=0;i<n;i++){
			if(i && cow[i].s==cow[i-1].s && cow[i].e==cow[i-1].e){
				ans[cow[i].id]=ans[cow[i-1].id];
				change(cow[i].s,1);
			}
			else{
				ans[cow[i].id]=getsum(cow[i].s);
				change(cow[i].s,1);
			}
		}
		for(int i=0;i<n-1;i++)
			printf("%d ",ans[i]);
		printf("%d\n",ans[n-1]);
	}
	return 0;
}
