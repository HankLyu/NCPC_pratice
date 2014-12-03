#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 305
using namespace std;
int n=8,m=15,t,X,Y,id;
bool my[MAXN],md1[MAXN],md2[MAXN],tmp;
int solution[MAXN];
void print_solution()
{
    printf("%2d     ",++id);
    for(int i=1;i<=n;++i)
    {
        printf(" %d",solution[i]);
    }
    putchar('\n');
}
void backtrack(int x)   // each row
{
    if(x==X)
    {
        backtrack(x+1);
        return;
    }
    if (x == n+1)	              //find a solution
    {
        print_solution();
    }
    for (int y=1; y<=n; ++y)  // try and recursion
    {
        int d1 = (x+y) % m, d2 = (x-y+m) % m;
        if (!my[y] && !md1[d1] && !md2[d2]) {
            // set up the constraint
            my[y] = md1[d1] = md2[d2] = true;
            solution[x] = y;
            backtrack(x+1);
            // back up the constraint
            my[y] = md1[d1] = md2[d2] = false;
        }
    }
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&Y,&X);
        memset(my,0,sizeof(my));
        memset(md1,0,sizeof(md1));
        memset(md2,0,sizeof(md2));
        int d1 = (X+Y) % m, d2 = (X-Y+m) % m;
        my[Y] = md1[d1] = md2[d2] = true;
        solution[X]=Y;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        id=0;
        backtrack(1);
        if(t) putchar('\n');
    }
    return 0;
}
