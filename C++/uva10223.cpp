#include<iostream>
#include<cstdio>
#include<map>

using namespace std;

int main(){
	long long int f=1;
	map<long long int,int>qq;
	qq[1]=1;
	for(int i=2;i<=100;i++){
		f=f*(4*i-2)/(i+1);
		qq[f]=i;
	}
	while(scanf("%lld",&f)!=EOF){
		printf("%d\n",qq[f]);
	}
	return 0;
}
