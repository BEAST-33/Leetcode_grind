#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;
class Solution {
    public:
    
        char dfs (char c , set<char>& visited,vector<set <char> > &edges ){
             char minimum = c ;
            for (auto& v: edges[c]){
                if (visited.find(v)==visited.end()){
                    visited.insert(v);
                    minimum = min (minimum,v);
                    dfs(v,visited,edges);
                }
            }
            return minimum;
        }
        string smallestEquivalentString(string s1, string s2, string baseStr) {
            int n = s1.size();
            vector<set <char> > edges(26) ;    
            for (int i =0 ;i < n; i++){
               edges[s1[i] - 'a'].insert(s2[i]);
               edges[s2[i - 'a']].insert(s1[i]);
            }
            
            int l = baseStr.size();
            string ans = "";
            for (int i =0 ;i < l; i++){
               set<char> visited ;
            char c = dfs(baseStr[i],visited,edges);
                ans+= c;
            }
            return ans;


        }
    };