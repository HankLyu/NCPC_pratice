#include<iostream>
#include<cstdio>
#include<cstring>

#define maxx 1000000

using namespace std;

int main()
{
	char a[maxx],b[maxx];
	while(scanf("%s %s",a,b)!=EOF){
		int alen=strlen(a),blen=strlen(b);
		int check=0;
		//printf("%d %d\n",alen,blen);
		for(int i=0;i<blen && check<alen;i++){
			if(a[check]==b[i])	check++;
		}
		if(check==alen)	printf("Yes\n");
		else			printf("No\n");
	}
	return 0;
}
