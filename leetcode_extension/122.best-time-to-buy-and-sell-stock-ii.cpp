/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
   
    vector<vector<int>> dp;
    int helper(int i, vector<int> &prices, int buy)
    {
        if (i == prices.size())
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
            int take = helper(i + 1, prices, 1)+prices[i];
            val = max(nottake, take);
        }
        
        return dp[i][buy]=val;
    }
    int maxProfit(vector<int> &prices)
    {   int n = prices.size();
        dp.resize(prices.size()+1, vector<int>(2, -1));
        int maxi = 0;
        dp[n][0]=dp[n][1]=0;
        for ( int i = n-1;i>=0;i--){
            for ( int j =0;j<=1;j++){
                int nottake = dp[i + 1][j];
                int take;
                if (j)
        {
            take = dp[i + 1][0]-prices[i];
            
        }
        else
        {
            take = dp[i + 1][1]+prices[i];
        }
        
        dp[i][j]= max(take,nottake);
            }
        }
        return dp[0][1];
    }
};
// @lc code=end
