/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int l = times.size();
        vector<vector<pair<int,int>>> adj;
        for ( int i =0; i<l ; i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue <pair<int,int>,vector<pair<int,int>>, less<pair<int,int>>> pq;
        int time = 0;
        for ( auto v : adj[k]){
                pq.push({v.second,v.first});
                time = max(time,v.second);
            }
            int cnt =0;
            
        while(!pq.empty()){
            auto it = pq.top();

            pq.pop();
            cnt++;
            int val =0;
            for ( auto v : adj[it.second]){
                val = max(val,v.second);
                pq.push({v.second,v.first});
            }
            time+= val;
        }
        return time;

    }
};
// @lc code=end

