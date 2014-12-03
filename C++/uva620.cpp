#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main()
{
	int test;
	string s;
	scanf("%d",&test);
	while(test--){
		cin>>s;
		if( !(s.length()%2) )
			printf("MUTANT\n");
		else if(s.length() ==1){
			if(s[0]=='A')	printf("SIMPLE\n");
			else			printf("MUTANT\n");
		}
		else{
			if(s[s.length()-1]=='B' && s[s.length()-2]=='A')
				printf("FULLY-GROWN\n");
			else if(s[0]=='B' && s[s.length()-1]=='A')
				printf("MUTAGENIC\n");
			else printf("MUTANT\n");
		}
	}
	return 0;
}
