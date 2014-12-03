#include<vector>
vector<int>a; //declaration
a.push_back(1); //insertion 
for(int i=0; i<a.size(); i++)
	cout<<a[i]<<" ";
vector<int>::iterator itr;
for(itr=in.begin(); itr!=in.end(); itr++)
	cout<<*itr<<“ ";
a.clear();
#include <queue>
queue<int> que;
que.push(1);
que.push(2);
cout<<que.front();
while(!que.empty()) que.pop();
#include<stack>
stack<int> stk;
stk.push(1);
stk.push(2);
cout<<stk.top();
while(!stk.empty()) stk.pop();
#include<map>
map<int,int>QQ;
QQ[8]=-1;
printf("%d\n",QQ[8]);
QQ.clear;
#include<cmath>
M_E			e	2.71828
M_PI		pi	3.1415926
acos(-1)	pi
M_LOG2E		log2(e)
M_LOG10E	log10(e)
