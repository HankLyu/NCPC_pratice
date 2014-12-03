#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>
#include<string>

#define maxx 10005

using namespace std;

struct node
{
	char name[35];
	int num;
}tree[maxx];

int main()
{
	int test;
	vector<string> v;
	char s[35],*a,*b;
	scanf("%d",&test);
	gets(s);
	gets(s);
	while(test--){
		int num=0;
		while(gets(s)){
			if(s[0]!='\0'){
			/*	if(qq[s]==0){
					qq[s]=num++;
				}
			*/
			//printf("%s\n",s);
			v.push_back(s);
			}
			else	break;
		}
		sort(v.begin(),v.end());
		int len=v.size(),tmp=1;
		//printf("len=%d\n",len);
		for(int i=1;i<v.size();i++){
			if(v[i] == v[i-1]){
				tmp++;
			}
			else{
				cout<<v[i-1];
				printf(" %.4lf\n",(double)( (double)tmp/ (double)len)*100);
				tmp=1;
			}
		}
		v.clear();
		if(test)	printf("\n");
	}
	return 0;
}
