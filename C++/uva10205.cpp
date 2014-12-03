#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

#define maxx 105

using namespace std;

struct node{
	char num[10],suit[10];
}tmp[53],now[53],ori[53];
int shu[maxx][53],n;

void inti(){
	for(int i=1;i<53;i++){
		if(i%13==0)			strcpy(ori[i].num, "Ace");
		else if(i%13==12)	strcpy(ori[i].num, "King");
		else if(i%13==11)	strcpy(ori[i].num, "Queen");
		else if(i%13==10)	strcpy(ori[i].num, "Jack");
		else if(i%13==9)	strcpy(ori[i].num, "10");
		else 				ori[i].num[0]=(char)(i%13+'0'+1);
		if(i<=13) 		strcpy(ori[i].suit, "Clubs");
		else if(i<=26) 	strcpy(ori[i].suit, "Diamonds");
		else if(i<=39)	strcpy(ori[i].suit, "Hearts");
		else	strcpy(ori[i].suit, "Spades");
	}
}
void ansprint(){
	for(int i=1;i<53;i++)
		printf("%s of %s\n",now[i].num,now[i].suit);
}
int main()
{
	int test,change;
	char s[100];
	inti();
	scanf("%d",&test);
	while(test--){
		memcpy(now,ori,sizeof(ori));
		//ansprint();
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=52;j++)
				scanf("%d",&shu[i][j]);
		gets(s);
		while(gets(s) && s[0]!='\0'){
			change=atoi(s);
			for(int i=1;i<=52;i++){
				strcpy(tmp[i].num, now[shu[change][i]].num);
				strcpy(tmp[i].suit, now[shu[change][i]].suit);
			}
			memcpy(now,tmp,sizeof(tmp));
		}
		ansprint();
		if(test)	printf("\n");
	}
	return 0;
}
