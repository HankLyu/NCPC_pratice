#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>

using namespace std;

int main()
{
	char a[100],b[100],s[100];
	map<string,string>qq;
	while(gets(s)){
		if(s[0]=='\0')	break;
		sscanf(s,"%s %s",a,b);
		qq[b]=a;
	}
	while(scanf("%s",s)!=EOF){
		if((qq[s][0]<='z'&&qq[s][0]>='a')||
			(qq[s][0]<='Z'&&qq[s][0]>='A'))
			cout<<qq[s]<<endl;
		else		printf("eh\n");
	}
}
