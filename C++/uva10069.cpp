#include<iostream>
#include<cstdio>
#include<cstring>

#define xmax 10005
#define zmax 105
#define maxn 30
#define base 10000

using namespace std;

char x[xmax],z[zmax];
int f[xmax][maxn],last[xmax][maxn];
int n;

void add_bignum(int a[],int b[],int c[])
{
	int sum;
	for(int i=maxn-1;i>=1;i--){
		sum=b[i]+c[i];
		a[i]+=sum%base;
		a[i-1]+=sum/base;
	}
	a[0]+=b[0]+c[0];
}
void print_ans(int d[])
{
	int i,len=0,rlen=0;
	char s[120],str[5];
	for(i=0;i<maxn;i++)
		if(d[i]){
			sprintf(str,"%d",d[i]);
			rlen=strlen(str);
			for(int j=0;j<rlen;j++)
				s[len++]=str[j];
				s[len]='\0';
			break;
		}
	for(int j=i+1;j<maxn;j++){
		sprintf(str,"%d",d[j]);
		rlen=strlen(str);
		for(int k=0;k<4-rlen;k++)
			s[len++]='0';
		for(int m=0;m<rlen;m++)
			s[len++]=str[m];
	}
	s[len]='\0';
	printf("%s\n",s);
}
int main()
{
	scanf("%d",&n);
	while(n--){
		scanf("%s %s",x,z);
		int xlen=strlen(x),zlen=strlen(z);
		int count=0;
		memset(f,0,sizeof(f));
		memset(last,0,sizeof(last));
		for(int j=xlen-1;j>=0;j--){
			if(z[zlen-1]==x[j])	count++;
			f[j][maxn-1]=count;
		}
		for(int i=zlen-2;i>=0;i--)
			for(int j=xlen-1;j>=0;j--){
				if(z[i]==x[j]){
					memcpy(last[j],f[j],maxn*sizeof(int));
					memset(f[j],0,maxn*sizeof(int));
					add_bignum(f[j],last[j+1],f[j+1]);
				}
				else{
					memcpy(last[j],f[j],maxn*sizeof(int));
					memcpy(f[j],f[j+1],maxn*sizeof(int));
				}
			}
		print_ans(f[0]);
	}
	return 0;
}
