#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

#define row 10005
#define col 80

using namespace std;

int n,m;
char str1[row][col],str2[col][row];
int pi1[col],pi2[row];

int gcd(int a,int b){
	if(a==0)	return b;
	return gcd(b%a,a);
}
int lcm(int a,int b){
	return a*b/gcd(a,b);
}
int findnext(char p[],int next[]){
	int len=strlen(p),i=0,j=-1;
	memset(next,0,sizeof(next));
	next[0]=-1;
	while(i<=len){
		while(j==-1 || i<len && p[i]==p[j]){
			i++;	j++;
			next[i]=j;
		}
		j=next[j];
	}
	return len-next[len];
}
int main(){
	int t1,t2;
	while(scanf("%d %d",&n,&m)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%s",str1[i]);
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++)
				str2[j][i]=str1[i][j];
		t1=t2=1;
		for(int i=0;i<n;i++){
			t1=lcm(t1,findnext(str1[i],pi1));
			if(t1>m){
				t1=m;
				break;
			}
		}
		for(int j=0;j<m;j++){
			t2=lcm(t2,findnext(str2[j],pi2));
			if(t2>n){
				t2=n;
				break;
			}
		}
		printf("%d\n",t1*t2);
	}
	return 0;
}
