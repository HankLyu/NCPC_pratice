#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct node{
	int num;
	char suit;
};
struct node2{
	int rank;
	int remain[5];
};

bool cmp(node a,node b){
	return a.num<b.num;
}
int change(char a){
	if(a=='A')	return 14;
	if(a=='K')	return 13;
	if(a=='Q')	return 12;
	if(a=='J')	return 11;
	return a-'0';
}
node2 deside(node a[]){
	node2 tmp;
	memset(&tmp,0,sizeof(tmp));
	int len=1,i;
	for(i=1;i<5;i++){
		if(a[i-1].num==a[i].num)	len++;
		if(len>1 && a[i-1].num!=a[i].num)	break;
	}
	if(len==4){
		tmp.rank=8;
		tmp.remain[0]=a[i-1].num;
		return tmp;
	}
	if(len==3){
		if(i==3 && a[i].num==a[i+1].num){
			tmp.rank=7;
			tmp.remain[0]=a[0].num;
			return tmp;
		}
		tmp.rank=4;
		tmp.remain[0]=a[2].num;
		return tmp;
	}
	if(len==2){
		if(i==2 && a[i].num==a[i+1].num){
			if(a[i].num==a[i+2].num){
				tmp.rank=7;
				tmp.remain[0]=a[3].num;
				return tmp;
			}
			tmp.rank=3;
			tmp.remain[0]=max(a[i].num,a[0].num);
			tmp.remain[1]=min(a[i].num,a[0].num);
			return tmp;
		}
		if(i==2 && a[i+1].num==a[i+2].num){
			tmp.rank=3;
			tmp.remain[0]=max(a[i+1].num,a[0].num);
			tmp.remain[1]=min(a[i+1].num,a[0].num);
			return tmp;
		}
		if(i==2){
			tmp.rank=2;
			tmp.remain[0]=a[0].num;
			tmp.remain[1]=a[4].num;
			tmp.remain[2]=a[3].num;
			tmp.remain[3]=a[2].num;
			return tmp;
		}
		if(i==3){
			if(a[i].num==a[i+1].num){
				tmp.rank=3;
				tmp.remain[0]=a[4].num;
				tmp.remain[1]=a[2].num;
				return tmp;
			}
			tmp.rank=2;
			tmp.remain[0]=a[i-1].num;
			tmp.remain[1]=a[4].num;
			tmp.remain[2]=a[3].num;
			tmp.remain[3]=a[0].num;
			return tmp;
		}
		if(i==4){
			tmp.rank=2;
			tmp.remain[0]=a[i-1].num;
			tmp.remain[1]=a[4].num;
			tmp.remain[2]=a[1].num;
			tmp.remain[3]=a[0].num;
			return tmp;
		}
		tmp.rank=2;
		tmp.remain[0]=a[i-1].num;
		tmp.remain[1]=a[2].num;
		tmp.remain[2]=a[1].num;
		tmp.remain[3]=a[0].num;
		return tmp;
	}
	if(a[1].num-a[0].num==1 && a[2].num-a[0].num==2 && 
		a[3].num-a[0].num==3 && a[4].num-a[0].num==4){
		if(a[0].suit==a[1].suit && a[0].suit==a[2].suit &&
			a[0].suit==a[3].suit && a[0].suit==a[4].suit){
			tmp.rank=8;
			tmp.remain[0]=a[4].num;
		}
		tmp.rank=5;
		tmp.remain[0]=a[4].num;
		return tmp;
	}
	if(a[0].suit==a[1].suit && a[0].suit==a[2].suit &&
		a[0].suit==a[3].suit && a[0].suit==a[4].suit){
		tmp.rank=5;
		for(int i=0;i<5;i++){
			tmp.remain[i]=a[4-i].num;
		}
		return tmp;
	}
	tmp.rank=1;
	for(int i=0;i<5;i++)
		tmp.remain[i]=a[4-i].num;
	return tmp;
}
int main()
{
	char s1[5][3],s2[5][3];
	node p1[5],p2[5];
	node2 black,white;
	while(scanf("%s %s %s %s %s %s %s %s %s %s",
		s1[0],s1[1],s1[2],s1[3],s1[4],
		s2[0],s2[1],s2[2],s2[3],s2[4]) !=EOF){
		for(int i=0;i<5;i++){
			if(strlen(s1[i])==2){
			p1[i].num=change(s1[i][0]);
			p1[i].suit=s1[i][1];
			}
			else{
				p1[i].num=10;
				p1[i].suit=s1[i][2];
			}
			if(strlen(s2[i])==2){
				p2[i].num=change(s2[i][0]);
				p2[i].suit=s2[i][0];
			}
			else{
				p2[i].num=10;
				p2[i].suit=s2[i][0];
			}
		}
		sort(p1,p1+5,cmp);
		sort(p2,p2+5,cmp);
		black=deside(p1);
		white=deside(p2);
		/*printf("black rank %d\n",black.rank);
		for(int i=0;i<5;i++)
			printf("%2d ",black.remain[i]);
		printf("\nwhite rank %d\n",white.rank);
		for(int i=0;i<5;i++)
			printf("%2d ",white.remain[i]);
		printf("\n");*/
		if(black.rank != white.rank){
			if(black.rank>white.rank)	printf("Black wins.\n");
			else	printf("White wins.\n");
			continue;
		}
		int istie=1;
		for(int i=0;i<5;i++){
			if(black.remain[i]>white.remain[i]){
				printf("Black wins.\n");
				istie=0;
				break;
			}
			if(black.remain[i]<white.remain[i]){
				printf("White wins.\n");
				istie=0;
				break;
			}
		}
		if(istie)	printf("Tie.\n");
	}
	return 0;
}
