#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	int test,n;
	scanf("%d",&test);
	while(test--){
		scanf("%d",&n);
		int a=0,b=0,tmp=n;
		while(tmp>0){
			if(tmp%2==1)	a++;
			tmp=tmp/2;
		}
		while(n>0){
			switch(n%10){
				case 0:	b+=0;	break;
				case 1:	b+=1;	break;
				case 2: b+=1;	break;
				case 3: b+=2;	break;
				case 4: b+=1;	break;
				case 5: b+=2;	break;
				case 6: b+=2;	break;
				case 7: b+=3;	break;
				case 8: b+=1;	break;
				case 9:	b+=2;	break;
				defalut:b+=0;	break;
			}
			n=n/10;
		}
		printf("%d %d\n",a,b);
	}
	return 0;
}
