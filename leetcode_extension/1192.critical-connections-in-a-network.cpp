#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1192 lang=cpp
 *
 * [1192] Critical Connections in a Network
 */

// @lc code=start

class Solution {
public:
    int cnt =0;
    vector<vector<int>> ans;
    vector<int> dbearray;
    int dfs(int u,int p,vector<vector<int>> &adj,vector<int>& visited,vector<int>& arrival,vector<int>& departure){
        visited[u]=1;
        
        int dbe =arrival[u]=cnt++;
        for( auto v : adj[u]){
            if ( v == p)continue;
            if (!visited[v]){
                int dbe_of_child=dfs(v,u,adj,visited,arrival,departure);

                dbe = min(dbe,dbe_of_child);
                if (dbe_of_child>arrival[u])ans.push_back({v,u});
            }
            else{
            dbe = min (dbe,arrival[v]);
            }
            
        } 
        
        dbearray[u]=dbe;
        departure[u]= cnt++;
        return dbe;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        dbearray.resize(n);
        for ( auto& pair : connections){
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        }
        vector<int> arrival(n,0);
        vector<int> departure(n,0);
        vector<int> visited(n,0);
        dfs(0,-1,adj,visited,arrival,departure);
        return ans;
    }
};
// @lc code=end

