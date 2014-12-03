#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	char a[20]={0},b[20]={0};
	int ans=0,tmp;
	while(scanf("%s %s",a,b)!=EOF){
		if(a[0]=='0' && b[0]=='0')	break;
		ans=0;
		int i,j;
		tmp=0;
		for(i=strlen(a)-1,j=strlen(b)-1;i>=0 && j>=0;i--,j--){
			tmp=a[i]-'0'+b[j]-'0'+tmp;
			//printf("%d %d tmp=%d\n",a[i]-'0',b[j]-'0',tmp);
			if(tmp>9){
				ans++;
				tmp=1;
			}
			else tmp=0;
		}
		while(i>=0 && a[i]=='9' && tmp==1){
			ans++;
			i--;
			tmp=1;
		}
		while(j>=0 && b[j]=='9' && tmp==1){
			ans++;
			j--;
			tmp=1;
		}
		if(ans==0)	printf("No carry operation.\n");
		if(ans==1)	printf("1 carry operation.\n");
		if(ans>1)	printf("%d carry operations.\n",ans);
	}
	return 0;
}
