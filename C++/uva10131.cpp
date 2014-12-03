    /************************************************
    Problem: UVA 10131 -- Is Bigger Smarter?
    Author: Bruce Chen
    Language: C++
    Time: 0.012 sec
    ************************************************/
     
    #include <iostream>
    #include <stdio.h>
    #include <string>
    #include <string.h>
    #include <algorithm>
    #include <vector>
     
    using namespace std;
     
    typedef struct
    {
            int weight, IQ, id;
    }ELE;
     
    bool cmp (ELE a, ELE b)
    {
            if(a.weight < b.weight) return true;
            else if(a.weight == b.weight)
            {
                    return a.IQ > b.IQ;
            }
            else return false;
    }
     
    int main()
    {
            vector<ELE> ele;
            ELE temp;
            int count = 0;
            while(~scanf("%d%d", &temp.weight, &temp.IQ))
            {
                    temp.id = count+1;
                    ele.push_back(temp);
                    count++;
            }
           
            sort(ele.begin(), ele.end(), cmp);
           
            int dp[1005];
            for(int i = 0 ; i < count ; i++) dp[i] = 1;
                           
            for(int i = count-1 ; i >= 0 ; i--)
            {
                    for(int j = i-1 ; j >= 0 ; j--)
                    {
                            if(ele[j].IQ > ele[i].IQ && ele[j].weight != ele[i].weight)    
                            {
                                    if(dp[j] < dp[i]+1) dp[j] = dp[i] + 1;
                            }              
                    }
            }
           
            int len = *(max_element(dp, dp+count)); //get the maximum element in dp array
           
            printf("%d\n", len);   
     
            int now = len;
           
            for(int i = 0 ; i < count ; i++)
            {
                    if(dp[i] == now)
                    {
                            printf("%d\n", ele[i].id);
                            now--;
                    }
            }
     
            return 0;
    }
