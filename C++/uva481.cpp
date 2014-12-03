#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

#define maxx 1000000

using namespace std;

int num[maxx],n;
int pnt[maxx],dp[maxx];
vector<int>lis;

void print_LIS()
{
	int len=lis.size();
	for(int i=n-1,j=0;j<len && i>=0;i--)
		if(dp[i]==len-j){
			pnt[len-1-j]=num[i];
			j++;
		}
	for(int i=0;i<len;i++)
		printf("%d\n",pnt[i]);
}
void LIS()
{
	vector<int> :: iterator ltr;
	lis.clear();
	lis.push_back(num[0]);
	dp[0]=1;
	for(int i=1;i<n;i++)
		if(num[i]>lis[lis.size()-1]){
			lis.push_back(num[i]);
			dp[i]=lis.size();
		}
		else{
			ltr=lower_bound(lis.begin(),lis.end(),num[i]);
			dp[i]=ltr-lis.begin()+1;
			*ltr=num[i];
		}
	printf("%d\n-\n",lis.size());
	print_LIS();
}
int main()
{
	n=0;
	while(scanf("%d",&num[n++])!=EOF);
	LIS();
	return 0;
}
