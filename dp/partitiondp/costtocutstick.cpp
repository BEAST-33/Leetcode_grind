#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        vector<int>cuts2 (n+2);
        cuts2[0]=0;
        for ( int i =0 ;i<n;i++){
            cuts2[i+1]= cuts[i];
        }
        cuts2[n+1] = n;
        rec(0,n+1,cuts2)
     }
};