/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool cycle;
    void toposort(int i , vector<vector<int>>& adj,vector<int>& visited,stack <int>&st ){
        visited[i] = 1;
        for ( auto v : adj[i]){
            if (!visited[v]){
                toposort(v,adj,visited,st);
            }
            if ( visited[v] ==1 )cycle =true;
        }
        st.push(i);
        visited [i]=2;
        return;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        int n = numCourses;
        cycle =false;
        for ( auto& ele : prerequisites){
            adj[ele[1]].push_back(ele[0]);
        }
        vector<int> visited(numCourses,0);
        vector<int> ans;
        stack <int> st;
        for ( int i =0;i<n;i++){
            if(!visited[i])toposort(i,adj,visited,st);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        if (!cycle)return ans;
        else return {};
        
    }
};
// @lc code=end

