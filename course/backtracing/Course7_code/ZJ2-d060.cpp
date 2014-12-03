#include <iostream>
using namespace std;
char Sudoku[10][10];
bool usedx[10][10],usedy[10][10],used[4][4][10];
void backtrack(int x, int y)
{
    while(1)
    {
        if(y==9) 
        {
            x++;
            y=0;
        }
        if(x==9)
        {
            for(int i=0;i<9;i++)
                for(int j=0;j<9;j++)
                {
                    printf("%c",Sudoku[i][j]);
                    if(j==8) printf("\n");
                }
        }
        if(x==9) break;
        if(Sudoku[x][y]=='0') break;
        y++;
    }
    if(x==9) return;
    for(int n=1;n<=9;n++)
    {
        if(!usedx[x][n]&&!usedy[y][n]&&!used[x/3][y/3][n])
        {
            //cout<<x<<" "<<y<<" "<<n<<'\n';
            usedx[x][n]=usedy[y][n]=used[x/3][y/3][n]=true;
            Sudoku[x][y]=char(n+48);
            backtrack(x,y+1);
            usedx[x][n]=usedy[y][n]=used[x/3][y/3][n]=false;
            Sudoku[x][y]='0';
        }
    }
}
int main()
{
    int i,j,k,l;
    for(i=0;i<20;i++)
    {
        for(j=0;j<9;j++)
            scanf("%s",Sudoku[j]);
        for(j=0;j<10;j++)
            for(k=1;k<=9;k++)
            {
                usedx[j][k]=false;
                usedy[j][k]=false;
            }
        for(j=0;j<4;j++)
            for(k=0;k<4;k++)
                for(l=1;l<=9;l++)
                    used[j][k][l]=false;
        for(j=0;j<9;j++)
            for(k=0;k<9;k++)
            {
                if(Sudoku[j][k]!='0')
                {
                    usedx[j][int(Sudoku[j][k])-48]=true;
                    usedy[k][int(Sudoku[j][k])-48]=true;
                    used[j/3][k/3][int(Sudoku[j][k])-48]=true;
                }
            }
        backtrack(0,0);
    }
    system("pause");
    return 0;
}
