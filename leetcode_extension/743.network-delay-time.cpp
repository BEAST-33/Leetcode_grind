/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        int l = times.size();
        vector<vector<pair<int, int>>> adj(n+1);
        for (int i = 0; i<l; i++)
        {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,k});
        vector<int> time(n+1, 1e9);
        time[k]=0;
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            if ( it.first > time[it.second])continue;
            for (auto [node, cost] : adj[it.second])
            {
                 
                if (cost + it.first < time[node]){
                    time[node] = cost + it.first;
                    pq.push({cost + it.first, node});
            }
            
            }
        }
       
        int ans=0;
         for (int i =1 ;i<=n;i++){
            if (time[i]==1e9)return -1;
            ans=max(ans,time[i]);
         }
        return ans;
    
}
};
// @lc code=end
