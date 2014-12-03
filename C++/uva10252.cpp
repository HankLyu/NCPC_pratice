#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define maxx 10005

using namespace std;

int main()
{
	int first=0;
	char cha[maxx],chb[maxx];
	int a[26],b[26],lena,lenb;
	while(gets(cha)){
		gets(chb);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		lena=strlen(cha);
		lenb=strlen(chb);
		
		for(int i=0;i<lena;i++)
			a[cha[i]-'a']++;
		for(int i=0;i<lenb;i++)
			b[chb[i]-'a']++;

		for(int i=0;i<26;i++){
			if(a[i]>0 && b[i]>0){
				if(a[i]>b[i])
					for(int j=0;j<b[i];j++)
						printf("%c",(char)(i+'a'));
				else
					for(int j=0;j<a[i];j++)
						printf("%c",(char)(i+'a'));
			}
		}
		printf("\n");
	}
	return 0;
}
