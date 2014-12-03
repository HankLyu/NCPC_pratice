#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

struct node{
	int m,n;
};
bool slt(node a,node b){
	return a.m*b.n<b.m*a.n;
}
bool operator !=(node a,node b){
	return a.m!=b.m || a.n!=b.n;
}
int main()
{
	node left,right;
	node dest,trace;
	string path;
	while(scanf("%d %d",&dest.m,&dest.n)!=EOF){
		if(dest.m==1 && dest.n==1)	break;
		path="";
		trace.m=1,trace.n=1;
		left.m=0,left.n=1;
		right.m=1,right.n=0;
		while(dest != trace){
			if(slt(dest,trace)){
				path+="L";
				right=trace;
				trace.m+=left.m;
				trace.n+=left.n;
			}
			else{
				path+="R";
				left=trace;
				trace.m+=right.m;
				trace.n+=right.n;
			}
		}
		printf("%s\n",path.c_str());
	}
	return 0;
}
