#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;
class Solution {
    public:
        string minWindow(string s, string t) {
            vector<int> mp(128,0);
            for ( auto& c : t)mp[c]++;
            int len = s.size();
            int start =0;
            int end =0;
            int counter = 0;
            int n = t.size();
            int startstr =0 ;
            int minlen = INT_MAX;
            while(end<len){
                if (mp[s[end]]>0)
                counter++;
                mp[s[end]]--;
                end++;
                while ( counter == n){
                    if ((end- start)<minlen ){
                        startstr = start ;
                        minlen = end-start;
                    }
                    mp[s[start]]++;
                    if (mp[s[start]]>0 )counter--;
                    
                    start++;
                }
            }
            if ( minlen == INT_MAX) return "";
            return s.substr(startstr,minlen);
        }
    };