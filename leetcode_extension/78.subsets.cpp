/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

void rechelper(int i,vector<int>& nums,vector<vector<int>> &ans,vector<int>&curr){
if ( i == nums.size())return ;

curr.push_back(nums[i]);
ans.push_back(curr);
rechelper(i+1,nums,ans,curr);
curr.pop_back();
rechelper(i+1,nums,ans,curr);
} 
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;vector<vector<int>> ans;
        ans.push_back(curr);
        
        rechelper(0,nums,ans,curr);
        return ans;
    }
};
// @lc code=end

