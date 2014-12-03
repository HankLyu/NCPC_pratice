#include<iostream>
#include<cstdio>
#include<cstring>

#define maxx 3005

using namespace std;

struct node
{
	int top,bottom;
	int num;
}cube[maxx];
int n,num;
int lis[maxx],pre[maxx];

void print_LIS(int x)
{
	if(pre[x]!=-1)	print_LIS(pre[x]);
	printf("%d ",cube[x].num+1);
	switch(x%6){
		case 0:	printf("front\n");	break;
		case 1:	printf("back\n");	break;
		case 2: printf("left\n");	break;
		case 3: printf("right\n");	break;
		case 4:	printf("top\n");	break;
		case 5: printf("bottom\n");	break;
		default:	break;
	}
}
void LIS()
{
	int set;
	for(int i=0;i<num;i++)
		for(int j=i+1;j<num;j++)
			if(cube[i].num<cube[j].num && cube[i].bottom == cube[j].top
					&& lis[j]<lis[i]+1){
				lis[j]=lis[i]+1;
				pre[j]=i;
				set=i;
			}
	int ans=0;
	for(int i=0;i<num;i++)
		if(ans<lis[i]){
			ans=lis[i];
			set=i;
		}
	printf("%d\n",ans+1);
	print_LIS(set);
	
}
int main()
{
	int test=0;
	while(scanf("%d",&n)!=EOF && n){
		if(test)	printf("\n");
		else	test++;
		num=0;
		int a,b,c,d,e,f;
		for(int i=0;i<n;i++){
			scanf("%d %d %d %d %d %d",&a, &b, &c, &d, &e, &f);
			cube[num].top=a, cube[num].bottom=b, cube[num++].num=i;//front
			cube[num].top=b, cube[num].bottom=a, cube[num++].num=i;//back
			cube[num].top=c, cube[num].bottom=d, cube[num++].num=i;//left
			cube[num].top=d, cube[num].bottom=c, cube[num++].num=i;//right
			cube[num].top=e, cube[num].bottom=f, cube[num++].num=i;//top
			cube[num].top=f, cube[num].bottom=e, cube[num++].num=i;//bottom
		}
		memset(lis,0,sizeof(lis));
		memset(pre,-1,sizeof(pre));
		printf("Case #%d\n",test++);
		LIS();
		//for(int i=0;i<num;i++)
		//	printf("%d top=%d bottom=%d num=%d dp=%d pre=%d\n",
		//	i,cube[i].top,cube[i].bottom,cube[i].num,lis[i],pre[i]);
	}
	return 0;
}
