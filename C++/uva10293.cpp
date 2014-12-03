#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	int fre[40],maxlen;
	char s[40];
	memset(fre,0,sizeof(fre));
	maxlen=0;
	while(scanf("%s",s)!=EOF){
		if(s[0]=='#'){
			for(int i=1;i<=30;i++)
				if(fre[i])
				printf("%d %d\n",i,fre[i]);
			maxlen=0;
			memset(fre,0,sizeof(fre));
			printf("\n");
			continue;
		}
		int len=strlen(s);
		int ans=0;
		int i;
		for(i=0;i<len;i++){
			if((s[i]<='z' && s[i]>='a') ||
				(s[i]<='Z' && s[i]>='A'))
				ans++;
			if(s[i]=='.' || s[i]=='!' || 
				s[i]=='?'|| s[i]==','){
				fre[ans]++;
		//		maxlen=max(ans,maxlen);
		//		printf("%d\n",ans);
				ans=0;
			}
		}
		if(ans !=0 && s[len-1]!='-'){
			fre[ans]++;
		//	maxlen=max(ans,maxlen);
		//	printf("%d\n",ans);
			ans=0;
			continue;
		}
		while(s[strlen(s)-1]=='-'){
			scanf("%s",s);
			len=strlen(s);
			for(int i=0;i<len;i++){
				if((s[i]<='z' && s[i]>='a') ||
					(s[i]<='Z' && s[i]>='A'))
					ans++;
				if(s[i]=='.' || s[i]=='!' || 
					s[i]=='?'|| s[i]==','){
					fre[ans]++;
		//			printf("%d\n",ans);
		//			maxlen=max(ans,maxlen);
					ans=0;
				}
			}
		}
		fre[ans]++;
		//maxlen=max(ans,maxlen);
		//printf("%d\n",ans);
		ans=0;
	}
	return 0;
}
