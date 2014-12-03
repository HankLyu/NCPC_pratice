#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>

#define maxx 40

using namespace std;

int main()
{
	int test;
	string s;
	scanf("%d",&test);
	while(test--){
		cin>>s;
		int len=s.length();
		if(len==1 && (s[0]=='1' || s[0]=='4'))
			printf("+\n");
		else if(len==2 && s[0]=='7' && s[1]=='8')
			printf("+\n");
		else if(s[len-1]=='5'&& s[len-2]=='3')
			printf("-\n");
		else if(s[0]=='9' && s[len-1]=='4')
			printf("*\n");
		else printf("?\n");
	}
	return 0;
}
