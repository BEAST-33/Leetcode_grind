#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
class Solution {
    public:
        bool helper(int idx, int target , vector<int>& nums,vector<vector <int >>& dp){
            if (idx == nums.size())return false;
            if (target == 0) return  true;
            if (dp[idx][target]!= -1) return dp[idx][target];
                        bool take = false;
            if ( nums[idx]<=target){
                take = helper( idx+1,target-nums[idx],nums,dp);
            }
            bool nottake = helper(idx+1,target,nums,dp);
            return dp[idx][target] =take || nottake ;
        }
        int minimumDifference(vector<int>& nums) {
            int sum =0;
            for ( auto ele : nums)sum+= ele;
            int n = nums.size();
            vector<vector <int >> dp (n+1 , vector<int>(sum+1,-1));
            for ( int i =0 ; i<=sum ;i++){
                bool dum = helper(0,i,nums,dp);
            }
            int mini = INT_MAX;
            for ( int i = 0; i<=sum ;i++){
                if ( dp[0][i]==1){
                    int diff = abs(i - (sum -i));
                    mini = min(mini ,diff);
                }
            }
            return mini;
        }
    };