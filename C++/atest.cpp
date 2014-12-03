#include<stdio.h>
#include<math.h>
int main()
{
double d,v,ans;
while(scanf("%lf%lf",&d,&v)==2)
{
if(d==0 && v==0)
break;
ans=pow((pow(d,3)-6*v/3.1415926535897932384626433832795),1.0/3.0);
printf("%.3lf\n",ans);
}
}
