#include<cstdio>
#include<cstring>
#include<iostream>

#define maxx 510

using namespace std;

int main()
{
	int test,m,n;
	long long int a[maxx],p[maxx][maxx],num[maxx];
	scanf("%d",&test);
	while(test--){
		scanf("%d %d",&m,&n);
		long long int low,high,mid,ans;
		low=high=0;
		for(int i=0;i<m;i++){
			scanf("%lld",&a[i]);
			low=max(low,a[i]);
			high+=a[i];
		}
		low--;
		while(1){
			mid=(low+high)/2;
			if(mid==low)	break;
			ans=0;
			int j,k;
			for(j=0,k=0;j<m;j++){
				if(ans+a[j]>mid){
					k++;
					if(k==n)	break;
					ans=0;
				}
				ans+=a[j];
			}
			if(j==m)	high=mid;
			else		low=mid;
		}
		ans=0;
		memset(num,0,sizeof(num));
		for(int i=m-1,k=n-1;i>=0;i--){
			if(ans+a[i]>high || i==k-1){
				k--;
				ans=0;
			}
			ans+=a[i];
			p[k][num[k]++]=a[i];
		}
		for(int i=0;i<n;i++){
			for(int j=num[i]-1;j>=0;j--){
				if(i!=0 ||j!=num[i]-1)	printf(" ");
				printf("%lld",p[i][j]);
			}
			if(i!=n-1)	printf(" /");
		}
		printf("\n");

	}
	return 0;
}
