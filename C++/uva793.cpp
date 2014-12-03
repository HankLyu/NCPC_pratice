#include<iostream>
#include<cstdio>
#include<cstring>

#define maxx 10000

using namespace std;

int p[maxx],rank[maxx];
int n;

int FindSet(int x)
{
	if(x!=p[x])
		p[x]=FindSet(p[x]);
	return p[x];
}
void Link(int x,int y)
{
	if(rank[x]>rank[y])
		p[y]=x;
	else{
		p[x]=y;
		if(rank[x]==rank[y])
			rank[y]++;
	}
}
void Union(int x,int y)
{
	Link(FindSet(x),FindSet(y));
}
int main()
{
	int test;
	char s[maxx],c;
	scanf("%d",&test);
	for(int t=0;t<test;t++){
		if(t)	printf("\n");
		scanf("%d",&n);
		gets(s);
		int a,b;
		int istrue=0,nottrue=0;
		memset(rank,0,sizeof(rank));
		for(int i=0;i<=n;i++)	p[i]=i;
		while(gets(s) && s[0]!='\0'){
			sscanf(s,"%c %d %d",&c,&a,&b);
			//printf("%c %d %d\n",c,a,b);
			if(c=='c'){
				//printf("do c\n");
				Union(a,b);
			}
			else if(c=='q'){
				//printf("do q\n");
				if(FindSet(a)==FindSet(b))	istrue++;
				else						nottrue++;
			}
		}
		printf("%d,%d\n",istrue,nottrue);
	}
	return 0;
}
