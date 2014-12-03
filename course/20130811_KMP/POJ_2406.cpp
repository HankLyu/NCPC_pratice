#include <iostream>
#define MAXN 1000005
using namespace std;
char s[MAXN];
int pi[MAXN];
int main()
{
    int i,n,l,k,q,m,ans;
    while(scanf("%s",s+1),s[1]!='.')
    {
        ans=1;
        pi[1]=0;
        k=0;
        l=strlen(s+1);
        for(q=2;q<=l;++q)
        {
            while(k>0&&s[k+1]!=s[q])
            {
                k=pi[k];
            }
            if(s[k+1]==s[q])
            {
                ++k;
            }
            pi[q]=k;
            if(q==l&&q%(q-pi[q])==0)
            {
                ans=max(ans,q/(q-pi[q]));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
