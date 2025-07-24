//distance to cycle in undirected graph for all the nodes in the graph

#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> distanceToCycle(int n, vector<vector<int>>& edges) {
       vector <unordered_set<int> > graph(n);
       for ( auto& pair : edges){
        graph[pair[0]].insert(pair[1]);
        graph[pair[1]].insert(pair[0]);
       }
       queue <int> q;
       vector <int> orderedqueue;
       vector<int> dist(n, 0);
       unordered_map <int, int> parent;
        for ( int i =0 ; i<n; i++){
            if (graph[i].size()==1 )
                q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            orderedqueue.push_back(node);
            q.pop();
            for ( auto& neighbor : graph[node]){
                parent[node] = neighbor;
                graph[neighbor].erase(node);
                if (graph[neighbor].size() == 1) {
                    q.push(neighbor);
                }
            }
        }

        while(!orderedqueue.empty()){
            int node = orderedqueue.back();
            orderedqueue.pop_back();
            for ( auto& neighbor : graph[node]){
                if (parent[node] == neighbor){
                    dist[node] = dist[neighbor] + 1;
                }
            }
        }
        return dist;
    }
};