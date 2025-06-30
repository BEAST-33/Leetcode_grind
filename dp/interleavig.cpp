#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int i =0, j = 0, k = 0;
        int n = s1.size(), m = s2.size(), l = s3.size();
        if (n + m != l) return false;
        for (k = 0; k < l; k++) {
            if (i < n && s1[i] == s3[k]) {
                i++;
            } else if (j < m && s2[j] == s3[k]) {
                j++;
            } else {
                return false;
            }
        }
        return true;
    }
};//wrong approach
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length(), l = s3.length();
        if (m + n != l) return false;
        
        if (m < n) return isInterleave(s2, s1, s3);

        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int j = 1; j <= n; ++j) {
            dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
        }

        for (int i = 1; i <= m; ++i) {
            dp[0] = dp[0] && s1[i - 1] == s3[i - 1];
            for (int j = 1; j <= n; ++j) {
                dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) || (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        
        return dp[n];
    }
};