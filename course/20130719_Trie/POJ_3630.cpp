#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct NODE
{
	int next[10];
	bool isword;
}trie[60050];
int root = 1,NW;
bool tmp;
void ini()
{
	NW = 1;
	memset(trie, 0, sizeof(trie));
}
void insert(char word[])
{
	int i,l,j;
	int ptr;			//ptr is for the traversal.
	l = strlen(word);
	for(i=0, ptr=root; i<l; i++)
	{
		j = (int)word[i]-48;
		if(trie[ptr].next[j]==0)
			trie[ptr].next[j] = ++NW;
		ptr = trie[ptr].next[j];
		if(trie[ptr].isword==true) tmp=1;
	}
	trie[ptr].isword = true;
	for(i=0;i<10;++i)
	{
		if(trie[ptr].next[i])
		{
			tmp=true;
			break;
		}
	}
}
int main()
{
	int t,n,i,j;
	char input[15];
	scanf("%d",&t);
	while(t--)
	{
		ini();
		scanf("%d",&n);
		tmp=0;
		while(n--)
		{
			scanf("%s",input);
			insert(input);
		}
		if(tmp) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
