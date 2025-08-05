
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ans =0;
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        auto fn = [&](int n, int m) {
            if (m<0) {ans++;return;}
            if(n<0){return;}
            if (s[n]==t[m]){
                fn(n-1,m-1);
            }
            else{
                fn(n-1,m);
            }
        };
        fn(n-1,m-1);

    }
   

};