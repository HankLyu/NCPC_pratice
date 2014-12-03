#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>

#define maxx 10005

using namespace std;
struct node{
	long long int beg,end,h;
};
node old[maxx],newt[maxx*10];
bool isshowed[maxx];
long long int totalid,num,ind[maxx*2];
long long int buildtree(long long int beg,long long int end,long long int id){
	newt[id].beg=beg,newt[id].end=end,newt[id].h=0;
	long long int mid=(beg+end)>>1;
	totalid=max(totalid,id);
	if(end>beg+1)
		return 1+buildtree(beg,mid,2*id)+buildtree(mid,end,2*id+1);
	return 1;
}
void addheight(long long int beg,long long int end,long long int id,long long int h){
	if(beg==ind[newt[id].beg] && end==ind[newt[id].end]){
		newt[id].h=h;
		return ;
	}
	if(newt[id].beg>=newt[id].end)	return ;
	long long int mid=(newt[id].beg+newt[id].end)>>1;
	if(newt[id].h){
		newt[2*id].h=newt[id].h;
		newt[2*id+1].h=newt[id].h;
		newt[id].h=0;
	}
	if(ind[mid]>=end)	addheight(beg,end,2*id,h);
	else if(ind[mid]<=beg)	addheight(beg,end,2*id+1,h);
	else{
		addheight(beg,ind[mid],2*id,h);
		addheight(ind[mid],end,2*id+1,h);
	}
}
void dealdata(long long int id){
	if(newt[id].h){
		isshowed[newt[id].h]=true;
		return ;
	}
	if(2*id<=totalid)	dealdata(2*id);
	if(2*id+1<=totalid)	dealdata(2*id+1);
}
int main(){
	int test,n;
	scanf("%d",&test);
	while(test--){
		memset(old,0,sizeof(old));
		memset(newt,0,sizeof(newt));
		memset(ind,0,sizeof(ind));
		memset(isshowed,false,sizeof(isshowed));
		num=totalid=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%lld %lld",&old[i].beg,&old[i].end);
			old[i].h=i+1;
			ind[num++]=old[i].beg-1,ind[num++]=old[i].end;
		}
		sort(ind,ind+num);
		int j=1;
		for(int i=1;i<num;i++)
			if(ind[i] !=ind[j-1])	ind[j++]=ind[i];
		ind[j]=ind[j-1]+1;
		num=j;
		buildtree(0,num-1,1);
		for(int i=0;i<n;i++)
			addheight(old[i].beg-1,old[i].end,1,old[i].h);
		dealdata(1);
		j=0;
		for(int i=0;i<maxx;i++)
			j+=isshowed[i];
		printf("%d\n",j);
	}
	return 0;
}
