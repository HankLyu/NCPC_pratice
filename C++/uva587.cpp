#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

#define maxx 1500

using namespace std;

int main(){
	int test=1,dirnum=0;
	double x=0,y=0,dis=0;
	char s[maxx],dir[5],c[maxx];
	while(scanf("%s",s)){
		if(strcmp(s,"END")==false)	break;
		x=0,y=0;
		int len=strlen(s);
		for(int i=0;i<len;i++){
			if(s[i]<='9' && s[i]>='0')
				dis=dis*10+s[i]-'0';
			if(s[i]<='Z' && s[i]>='A')
				dir[dirnum++]=s[i];
			if(s[i]==',' || s[i]=='.'){
				if(dirnum==2)	dis=dis/sqrt(2);
				for(int j=0;j<dirnum;j++){
					switch(dir[j]){
						case 'N':	y+=dis;	break;
						case 'S':	y-=dis;	break;
						case 'E':	x+=dis;	break;
						case 'W':	x-=dis;	break;
						default:	break;
					}
				}
				dis=0.0;
				dirnum=0;
			}
		}
		printf("Map #%d\n",test++);
		printf("The treasure is located at (%.3lf,%.3lf).\n",x,y);
		printf("The distance to the treasure is %.3lf.\n\n",
			sqrt(x*x+y*y));
	}
	return 0;
}
