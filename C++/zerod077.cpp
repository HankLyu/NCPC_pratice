#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	int num,play=0;
	while(scanf("%d",&num)!=EOF && num!=0){
		float dis,v[10010];
		float t=0,tmp;
		play++;
		scanf("%f",&dis);
		for(int i=0;i<num;i++)
			scanf("%f",&v[i]);
		sort(v,v+num);
		if(num%2){
			for(int i=0;i<num-1;i++){
				tmp=dis*2/(v[i]+v[num-i-2]);
				t=t+tmp;
				//printf("%f %f\n",tmp,t);
			}
			t=t/(float)2;
			t=t+dis/v[num-1];
		}
		else{
			for(int i=0;i<num;i++){
				tmp=dis*2/(v[i]+v[num-i-1]);
				t=t+tmp;
				//printf("%f %f\n",tmp,t);
			}
			t=t/(float)2;
		}
		printf("Case %d: %d\n",play,(int)t);
	}//while
	return 0;
}
