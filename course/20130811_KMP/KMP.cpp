/*KMP
string = 1~n
*/
#define MAXT 1000005
#define MAXP 1005
int pi[MAXP];//次長後綴長度
int ans;//match個數
char P[MAXP],T[MAXT];//pattern text
int Plen,Tlen;//字串長度
int main()
{
    int i,n,l,k,q,m,ans;
    while(scanf("%s%s",P,T)==2)
    {
        //prefix function 求pi[]
        k=0;
        for(q=2;q<=Plen;++q)
        {
            while(k>0&&P[k+1]!=P[q]) k=pi[k];
            if(P[k+1]==P[q]) ++k;
            pi[q]=k;
        }
        q=0;
        //KMP
        for(int i=1;i<=Tlen;++i)
        {
            while(q>0&&P[q+1]!=T[i]) q=pi[q];
            if(P[q+1]==T[i]) q++;
            if(q==Plen)
            {
                ans++;
                q=pi[q];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
