#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std

bool helper( int idx,vector<int> &arr,int k,int sum ){
    if (idx == arr.size()){
        return false;
    }
    sum += arr[idx];
    if ( sum == k)return true;
    if (helper(idx+1,arr,k,sum)) return true;
    sum -= arr[idx];
    if (helper(idx+1,arr,k,sum)) return true;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    return helper(0,arr,k,0);

}
bool helper( int idx,int k ,vector<int> &arr,vector<vector<int> >& dp,int target ){
    if (idx == arr.size()){
        return false;
    }
    if ( k == target )
    return dp[idx][k] = true;
    if (dp[idx][k] != -1) return dp[idx][k];

    bool nottake =helper(idx+1,k,arr,dp,target) ;
    if (arr[idx]<=target - k)
    bool take = helper(idx+1,k+arr[idx],arr,dp,target);
    return dp[idx][k] = take || nottake ;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int> > dp(n , vector<int>(k+1,0));
    for ( int i = 0; i <k+1; i++){
        dp[i][0]=1;
    }
    
    int target = k;
    return helper(0,0,arr,dp,target);

}
