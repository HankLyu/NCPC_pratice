#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

struct node
{
	int v;
	bool operator < (const node &in) const{
		return v>in.v;
	}
};
int main()
{
	priority_queue<node> q;
	int n;
	while(scanf("%d",&n) != EOF && n){
		int ans=0,num=0;
		int ar[5000]={0};
		node a;
		for(int i=0;i<n;i++){
			scanf("%d",&a.v);
			q.push(a);
		}
		while(!q.empty()){
			ans=ans+q.top().v;
			q.pop();
			ans=ans+q.top().v;
			q.pop();
			a.v=ans;
			if(!q.empty())
				q.push(a);
		//	printf("%d ",q.top().v);
			ar[num]=ans;
			ans=0;
			num++;
		}
		ans=0;
		for(int i=0;i<num;i++){
			//printf("%d ",ar[i]);
			ans=ans+ar[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
