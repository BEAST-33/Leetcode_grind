#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;
int solution ( string& s ){
    int n = s.size();
    vector<int> left (n,0);
    vector<int> right (n,0);
    if (n<2){
        return 0;
    }
    for ( int i =0;i<n;i++){
       if (s[i]=='<' || s[i] =='?'){
        if (i-1>=0)left[i] = left[i-1]+1;
        else left[i]=1;
       }
       else left [i] = 0;
        
    }
    for ( int i =n-1;i>=0;i--){
        if (s[i]=='>' || s[i] =='?'){
         if (i+1<n)right[i] = right[i+1]+1;
         else right[i]=1;
        }
        else right [i] = 0;
         
     }
     int ans=0;
    
     for ( int i =0;i<n-1;i++){
        int loc = min(left[i],right[i+1]);
        ans = max(ans,loc);
     }
return ans*2;
    
}

// Test cases for the solution function
int main() {
    vector<pair<string, int> > testcases = {
        {"<", 0},                // Single character
        {">", 0},                // Single character
        {"?", 0},                // Single character
        {"<<", 0},               // All '<'
                  // Mixed with more length
        {"<><<>>?", 4},          // Mixed with '?' at end
        {"", 0},                 // Empty string
        {"<><><><><>", 2},       // Alternating pattern
        {"?????", 4},            // All '?', longer
                   // Mixed with '?'
        {"<><<><<><<", 2},       // Repeated pattern
    };
    for (size_t i = 0; i < testcases.size(); ++i) {
        string s = testcases[i].first;
        int expected = testcases[i].second;
        int result = solution(s);
        cout << "Test " << i+1 << ": input='" << s << "' | Expected: " << expected << ", Got: " << result;
        if (result == expected) cout << " [PASS]" << endl;
        else cout << " [FAIL]" << endl;
    }
    return 0;
}
