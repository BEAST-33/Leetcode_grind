/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size();
        
        for ( int i=0;i<n;i++){
            mp[i]=1e9;
        }
        mp[0]=0;
        for (int i=0;i<n-1;i++){
            for (int j=1;j<=nums[i];j++){
            if (i + j < n && 1 + mp[i] < mp[i + j]) {
                    mp[i + j] = 1 + mp[i];
                }
        }
    }
        return mp[n-1];
    }
};
// @lc code=end

