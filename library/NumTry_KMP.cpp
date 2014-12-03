char s[maxx],input[maxx];
int len,pi[maxx];
scanf("%s",s+1);
s[0]='#';
len=strlen(s);
memset(pi,0,sizeof(pi));
int k=0;
for(int i=2;i<len;i++){
	while(k>0 && s[k+1]!=s[i])	k=pi[k];
	if(s[k+1]==s[i])	k++;
	pi[i]=k;
}
//suffix is same as prefix in whole string
int tmp=len-1,num=0;
a[num++]=len-1;
while(pi[tmp]){
	a[num++]=pi[tmp];
	tmp=pi[tmp];
}
///////w in t occurence times
int ans=0,l=0;
for(int i=1;i<lent;i++){
	while(w[l+1]!=t[i] && l)	l=piw[l];
	if(w[l+1]==t[i])	l++;
	if(l==lenw-1)	{
		ans++;
		l=piw[l];
	}
}
