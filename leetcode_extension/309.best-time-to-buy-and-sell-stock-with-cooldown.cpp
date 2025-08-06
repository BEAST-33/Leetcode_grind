#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
   
    vector<vector<int>> dp;
    int helper(int i, vector<int> &prices, int buy)
    {
        if (i >= prices.size())
            return 0;
            if(dp[i][buy]!=-1)return dp[i][buy];
        int nottake = helper(i + 1, prices, buy);
        int val;
        if (buy)
        {
            int take = helper(i + 1, prices, 0)-prices[i];
            val = max(nottake, take);
        }
        else
        {
            int take = helper(i + 2, prices, 1)+prices[i];
            val = max(nottake, take);
        }
        
        return dp[i][buy]=val;
    }
    int maxProfit(vector<int> &prices)
    {   
        dp.resize(prices.size(), vector<int>(2, -1));
        return helper(0, prices, 1);
    }
};