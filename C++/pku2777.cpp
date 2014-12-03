#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

#define maxx 100005

using namespace std;

int l,t,o;
int tb[maxx*3]={0};

void insert(int l,int r,int a,int b,int id,int c){
	if(l==a && r==b){
		tb[id]=c;
		return ;
	}
	if(tb[id]>0){
		tb[id*2]=tb[id*2+1]=tb[id];
		tb[id]=0;
	}
	int mid=(l+r)/2;
	if(b<=mid)	insert(l,mid,a,b,id*2,c);
	else if(a>mid)	insert(mid+1,r,a,b,id*2+1,c);
	else{
		insert(l,mid,a,mid,id*2,c);
		insert(mid+1,r,mid+1,b,id*2+1,c);
	}
}
void query(int l,int r,int a,int b,int id,int &ans){
	if(l==a && r==b && tb[id]>0){
		ans |= (1<<tb[id]);	return ;
	}
	if(tb[id]>0){
		tb[id*2]=tb[id*2+1]=tb[id];
	}
	int mid=(l+r)/2;
	if(b<=mid)	query(l,mid,a,b,id*2,ans);
	else if(a>mid)	query(mid+1,r,a,b,id*2+1,ans);
	else{
		query(l,mid,a,mid,id*2,ans);
		query(mid+1,r,mid+1,b,id*2+1,ans);
	}
}
int getnum(int x){
	int ans=0;
	for(int i=1;i<=t;i++)
		if(x&(1<<i))	ans++;
	return ans;
}
int main(){
	scanf("%d %d %d",&l,&t,&o);
	tb[1]=1;
	char s[5];
	int a,b,c;
	while(o--){
		scanf("%s",s);
		if(s[0]=='C'){
			scanf("%d %d %d",&a,&b,&c);
			if(a>b)	swap(a,b);
			insert(1,l,a,b,1,c);
		}
		else{
			scanf("%d %d",&a,&b);
			c=0;
			if(a>b)	swap(a,b);
			query(1,l,a,b,1,c);
			printf("%d\n",getnum(c));
		}
	}
	return 0;
}
