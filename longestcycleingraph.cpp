#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;
#include <vector>
#include <algorithm> // Required for std::max

class Solution {
public:
    int longestCycle(std::vector<int>& edges) {
        int n = edges.size();
        int longest_cycle_len = -1;
        
        // visited_time[i] stores the "time" a node was visited in the current path.
        // A value of 0 means not visited yet.
        std::vector<int> visited_time(n, 0);
        int time = 1; // A global "clock" that increments with each node visit.

        // Iterate through each node in the graph.
        for (int i = 0; i < n; ++i) {
            // If the node hasn't been visited in any previous traversal.
            if (visited_time[i] == 0) {
                const int start_time = time; // Mark the start time for this new path.
                int current_node = i;

                // Traverse the path from the current node.
                while (current_node != -1 && visited_time[current_node] == 0) {
                    visited_time[current_node] = time++;
                    current_node = edges[current_node];
                }

                // If we stopped because we found a node that was already visited
                // AND it was visited during this specific traversal (its time is >= start_time),
                // then we have found a cycle.
                if (current_node != -1 && visited_time[current_node] >= start_time) {
                    int cycle_len = time - visited_time[current_node];
                    longest_cycle_len = std::max(longest_cycle_len, cycle_len);
                }
            }
        }
        return longest_cycle_len;
    }
};
class Solution {
    public:
        int result = -1;
    
        void dfs(int u, vector<int>& edges, vector<bool>& visited,
                 vector<int>& count, vector<bool>& inrecurr) {
            if (u == -1) return;
    
            visited[u] = true;
            inrecurr[u] = true;
            int v = edges[u];
            if (v != -1) {
                if (!visited[v]) {
                    count[v] = count[u] + 1;
                    dfs(v, edges, visited, count, inrecurr);
                } else if (inrecurr[v]) {
                    result = max(result, count[u] - count[v] + 1);
                }
            }
            inrecurr[u] = false;
        }
    
        int longestCycle(vector<int>& edges) {
            int n = edges.size();
            vector<bool> inrecurr(n, false);
            vector<bool> visited(n, false);
            vector<int> count(n, 1);
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    count[i] = 1;
                    dfs(i, edges, visited, count, inrecurr);
                }
            }
            return result;
        }
    };


class Solution {
    public:
        int dfs(int i , vector<int>& vis,vector<int>& curvis, vector<vector<int> >& graph, vector<int>& dist){
            vis[i]=1;
            curvis[i]=1;
            
            for (auto& v : graph[i]){
                if (!vis[v]){
                    dist[v]= dist[i]+1;
                    dfs(v,vis,curvis,graph,dist);
                }
                if (curvis[v]) return 
            }
            curvis[i]=0;
            dist
        }
        int longestCycle(vector<int>& edges) {
            int n =edges.size();
            vector<vector<int> > graph(n);
            for ( int i =0; i < n ;i++){
                if ( edges[i]!= -1)
                graph[i].push_back(edges[i]);
            }
            vector<int> vis(n+1,0);
            vector<int> curvis(n+1,0);
            vector<int> dist(n+1,0);
            int maxans=INT_MIN;
            for ( int i =0; i < n ;i++){
                if ( !vis[i] && edges[i] !=-1){
                    dist [i]=0;
                    int ans = dfs(i,vis,curvis,graph,dist);
                    maxans=max(maxans,ans);
                }
            }
            return maxans;

        }
    };