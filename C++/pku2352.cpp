#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

#define maxx 32005

using namespace std;

int s[maxx],ans[maxx];

int lowbit(int in){
	return in&(-in);
}
int getsum(int end){
	int tmp=0;
	while(end){
		tmp+=s[end];
		end -= lowbit(end);
	}
	return tmp;
}
void change(int end,int maxsize,int delta){
	for(int i=end;i<=maxsize;i+=lowbit(i))
		s[i]+=delta;
}
int main()
{
	int n,x,y,tmp,left=0;
	while(scanf("%d",&n)!=EOF){
		memset(ans,0,sizeof(ans));
		memset(s,0,sizeof(s));
		for(int i=0;i<n;i++){
			scanf("%d %d",&x,&y);
			x++;
			ans[getsum(x)]++;
			change(x,maxx,1);
		}
		for(int i=0;i<n;i++)
			printf("%d\n",ans[i]);
	}
	return 0;
}
