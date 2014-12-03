#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define maxx 1005

using namespace std;

struct node
{
	int t,s,num;
}word[maxx];

bool cmp(node a,node b)
{
	if( (double)a.s/(double)a.t> (double)b.s/(double)b.t)
		return true;
	if( (double)a.s/(double)a.t == (double)b.s/(double)b.t)
		if(a.num<b.num)	return true;
	return false;
}
int main()
{
	int test,n;
	scanf("%d",&test);
	while(test--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d %d",&word[i].t,&word[i].s);
			word[i].num=i+1;
		}
		sort(word,word+n,cmp);
		for(int i=0;i<n;i++){
			if(i)	printf(" ");
			printf("%d",word[i].num);
		}
		printf("\n");
		if(test)	printf("\n");
	}
	return 0;
}
