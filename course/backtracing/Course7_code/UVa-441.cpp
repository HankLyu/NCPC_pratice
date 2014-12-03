#include <iostream>
using namespace std;
bool used[11];
int s[14],solution[11];
void permutation(int k, int n) 
{ 
    if (k == 6) 
    { 
        for (int i=0; i<6; i++) 
        {
            if(i>0) printf(" ");
            printf("%d",solution[i]);
        }
        printf("\n"); 
        return; 
    } 

    for (int i=0; i<n; i++) 
        if (!used[i]&&solution[k-1]<=s[i]) 
        { 
            used[i] = true; 

            solution[k] = s[i]; 
            permutation(k+1, n); 
            
            used[i] = false; 
            //if(k==5) continue;
        } 
}
int main()
{
    int n,i,t=0;
    while(scanf("%d",&n),n)
    {
        for(i=0;i<n;i++)
            scanf("%d",&s[i]);
        sort(s,s+n);
        if(t>0) printf("\n");
        permutation(0,n);
        ++t;
    }
    return 0;
}
