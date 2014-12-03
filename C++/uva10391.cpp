#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
#include<vector>

#define maxx 120005

using namespace std;

int main()
{
	string s[maxx];
	int n=0;
	char tmp[35];
	string a;
	map<string,int>qq;
	vector<string>ans;

	while(scanf("%s",tmp)!=EOF){
		s[n++]=tmp;
	}
	//n--;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if( s[i].size()>s[j].size() )
				swap(s[i],s[j]);
	int check,j,len;
	for(int i=0;i<n;i++){
		qq[s[i]]=1;
		check=0;
		len=s[i].size();
		for(j=0;j<=len;j++){
			a=s[i].substr(0,j);
			if(qq[a]==1){
				//cout<<s[i]<<endl;
				//cout<<"front: "<<a<<endl;
				a=s[i].substr(j,len);
				//cout<<"behind: "<<a<<endl;
				if(qq[a]==1){
					ans.push_back(s[i]);
					break;
				}
			}
		}
	}
	len=ans.size();
	sort(ans.begin(),ans.end());
	for(int i=0;i<len;i++)
		cout<<ans[i]<<endl;
	return 0;
}
