#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;
class Solution {
    public:
        bool helper (int left, int right,vector<vector<int> >& dp,string s ){
            if (dp [left][right]!= -1) return dp [left][right];
            if (s[left]==s[right]){
                return helper(left+1,right-1,dp,s);
            }
            else {
                return false;
            }
        }


        int maxPalindromes(string s, int k) {
            int n = s.size();
            int ans =0;
            vector<vector<int> > dp(n+1,vector<int>(n+1,-1));
            int i = 0;
            while ( i<=n-k){
                bool istrue = false;
                for (int j = i + k - 1; j < n; j++) {
                    if (helper(i, j, dp, s)) {
                        ans++;
                        i = j+1;
                        istrue = true;
                        break;
                    }
                    if (!istrue){
                        i++;
                    }
                    
                }
            }
        
            
            return ans;
        }
    };