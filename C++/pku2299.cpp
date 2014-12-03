#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

#define maxx 500005

using namespace std;

long long int t,a[maxx],n;

void merge(int low,int high){
	int b[maxx],k=-1,mid=(low+high)>>1;
	for(int i=low,j=mid+1;i<=mid||j<=high;){
		if(i>mid)		b[++k]=a[j++];
		else if(j>high)	b[++k]=a[i++];
		else if(a[i]>a[j]){
			b[++k]=a[j++];
			t+=1+mid-i;
		}
		else	b[++k]=a[i++];
	}
	k=0;
	for(int i=low;i<=high;i++)	a[i]=b[k++];
}
void mergesort(int low,int high){
	if(high>low){
		mergesort(low,(low+high)/2);
		mergesort(1+(low+high)/2,high);
		merge(low,high);
	}
}
int main()
{
	while(scanf("%lld",&n)!=EOF && n){
		for(int i=0;i<n;i++)
			scanf("%lld",&a[i]);
		t=0;
		mergesort(0,n-1);
		printf("%lld\n",t);
	}
	return 0;
}
