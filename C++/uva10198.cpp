#include<iostream>
#include<stdio.h>
#include<string.h>
#define maxn 1007
#define maxl 90
using namespace std;

typedef struct
{
    long l,s[maxl];
}bign;
void Add(bign &c,bign &a,bign &b)
{
    memset(&c,0,sizeof(c));
    c.l=(a.l>b.l?a.l:b.l);
    for(long i=0;i<c.l;i++)
    {
       c.s[i]+=a.s[i]+b.s[i];
       if(c.s[i]>=100000)
       {
          c.s[i]-=100000;
          c.s[i+1]++;
       }
    }
    if(c.s[c.l]) c.l++;
}
void Print(bign &a)
{
    printf("%ld",a.s[a.l-1]);
    for(long i=a.l-2;i>=0;i--)
      printf("%05ld",a.s[i]);
}

long n;
bign d[maxn]={{1,{1}},{1,{2}},{1,{5}},{1,{13}}};

int main()
{
    for(long i=4;i<=1000;i++)
    {
       //  d[i]=d[i-1]+d[i-1]+d[i-2]+d[i-3]
       bign t1,t2;
       Add(t1,d[i-1],d[i-1]);
       Add(t2,t1,d[i-2]);
       Add(d[i],t2,d[i-3]);
    }
    
    while(cin>>n)
    {
       Print(d[n]);
       cout<<endl;
    }
return 0;
}
