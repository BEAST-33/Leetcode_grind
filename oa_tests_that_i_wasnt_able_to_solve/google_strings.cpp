//there is a coder who types fast and makes mistake by swapping consecutive letters of a string . if he does swap i and i+1 he cant swap i+1 and i+2 , he can however type correctly also no of unique strings he can make in total . how to do this in cpp. in less than 30 mins.
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>

 long solve(string& s){
    set<string> uniquestrings;
    helper(0,s,uniquestrings);
    return uniquestrings.size();
 }
 void helper(int idx, string& s, set<string>& uniquestrings){
    int n = s.size();
   vector<vector<int> > dp(n , vector<int> (n+1,0));
   for ( int i=0;i<=n;i++){
    dp[0]= 1;
   }
   for ( int i=1;i<n;i++){
    for (int j=0;j<=n;j++ )
        int nottake = dp[i-1][j];
        int take=0;

        dp[i][j]= take + nottake;

   }


 }

