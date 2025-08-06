#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1547 lang=cpp
 *
 * [1547] Minimum Cost to Cut a Stick
 */

// @lc code=start

int f(int i,int j,int n,vector<int>& cuts,vector<vector <int> >& dp){
    if ( j-i <=1)return 0;
    int localmini= 1e9;
    if(dp[i][j]!=-1)return dp[i][j];
    for (int k =i+1 ;k<j;k++){
                localmini =min(localmini,f(i,k,n,cuts,dp)+f(k,j,n,cuts,dp)+cuts[j]-cuts[i]);
            
        }
        
        
        return dp[i][j]=localmini;
}
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int k = cuts.size();
        vector<vector <int> > dp(k ,vector<int> (k,-1));
        int ans =f(0,k-1,n,cuts,dp);
        return ans;
    }

};
// @lc code=end

