/*#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

struct node
{
	double x,y;
}p1,p2,p3,p4,ans;

int main()
{
	int test;
	double x1,x2,x3,x4,y1,y2,y3,y4;
	scanf("%d",&test);
	printf("INTERSECTING LINES OUTPUT\n");
	while(test--){
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf",
			&x1,&y1, &x2,&y2, &x3,&y3, &x4,&y4);
		int a=(x4-x3)*(y2-y1)-(y4-y3)*(x2-x1);
		if(a!=0){
			double b=( (x1-x3)*(y2-y1)-(y1-y3)*(x2-x1) )/a;
			ans.x=(x4-x3)*b+x3;
			ans.y=(y4-y3)*b+y3;
			printf("POINT %.2lf %.2lf\n",ans.x, ans.y);
		}
		else{
			bool check=0;
			if(x4-x3 !=0){
				double b=(x1-x3)/(x4-x3);
				if(abs(b*(y4-y3)+y3 -y1) > 2e-5)
					printf("NONE\n"),check=1;
			}
			else if(x3 != x1)	printf("NONE\n"),check=1;
			else if(x4-x3 !=0){
				double b=(x2-x3)/(x4-x3);
				if(abs(b*(y4-y3)+y3-y2)>2e-5)
					printf("NONE\n"),check=1;
			}
			else if(x3 != x2)	printf("NONE\n"),check=1;
			
			if(!check) printf("LINE\n");
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}*/
    #include <iostream>  
    #include<cstdio>

	using namespace std;  
    int main()  
    {  
        int N,x1,x2,x3,x4,y1,y2,y3,y4;  
        int a,b,c,d,e,f;  
        scanf("%d",&N);  
        printf("INTERSECTING LINES OUTPUT\n");  
        for(int i=0;i<N;i++)  
        {  
            scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);  
            a=y2-y1;  
            b=x2*y1-x1*y2;  
            c=x2-x1;  
            d=y4-y3;  
            e=x4*y3-x3*y4;  
            f=x4-x3;  
            if(a*f==c*d)//两直线斜率相等  
            {  
                if(b*f==e*c&&b*d==e*a)//两直线重合  
                {  
                    printf("LINE\n");  
                    continue;  
                }  
                else  
                {  
                    printf("NONE\n");//两直线平行但不重合  
                    continue;  
                }  
            }  
            else//斜率不相等，必有交点  
            {  
                double y=((double)(a*e-b*d))/(a*f-c*d);  
                double x=(y*c-b)/a;  
                printf("POINT %.2f %.2f\n",x,y);  
            }  
        }  
        printf("END OF OUTPUT\n");  
        return 0;  
    }  
