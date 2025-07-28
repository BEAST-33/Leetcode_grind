#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;
class Solution {
    public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            vector<vector<pair<int,int>>> edges(n);
            for (auto& it: flights){
                edges[it[0]].push_back({it[2],it[1]});
            }
            queue <pair<int,int> > q;
            vector <int> dist(n+1,INT_MAX);
            q.push({0,src});

            int level = 0;
            
            while (!q.empty() || level <= k){
                
                int n = q.size();
                
                for ( int i=0; i <n; i++){
                    auto it = q.front();
                    q.pop();
                    int node= it.second ;
                    int cost = it.first;
                    if ( node == dst){
                        continue;
                    }
                for ( auto it2 : edges[node]){
                    int node2 = it2.second;
                    int w = it2.first;
                    if ( w+ cost < dist[node2]){
                        dist[node2] = w+cost;
                        q.push({dist[node2],node2});
                    }
                    
                }
                }
                level++;
            
            }
            if (dist[dst]==INT_MAX) return -1;
            return dist[dst];
        }
    };