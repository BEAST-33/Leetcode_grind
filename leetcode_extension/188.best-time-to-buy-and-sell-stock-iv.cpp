#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
   
    vector<vector<vector<int>>> dp;
    int helper(int i, vector<int> &prices, int buy,int limit)
    {
        if (i == prices.size())
            return 0;
        if(!limit && buy){
            return 0;
        }
            if(dp[i][buy][limit]!=-1)return dp[i][buy][limit];
        
        int nottake = helper(i + 1, prices, buy,limit);
        int val;
        if (buy)
        {
            int take = helper(i + 1, prices, 0,limit-1)-prices[i];
            val = max(nottake, take);
        }
        else
        {
            int take = helper(i + 1, prices, 1,limit)+prices[i];
            val = max(nottake, take);
        }
        return dp[i][buy][limit]=val;
    }
    int maxProfit(int k,vector<int> &prices)
    {   
        
        dp = vector<vector<vector<int>>>(prices.size(), vector<vector<int>>(2, vector<int>(k+1, -1)));
        return helper(0, prices, 1,k);
      
    }
};