#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Adjacency list: stores {destination_node, price}
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        // Min-priority queue: stores {cost, current_node, stops_made}
        // We use greater<> to make it a min-heap based on the first element (cost)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        // dist[i] stores the minimum stops to reach node i
        // This helps prune paths that are not better (more stops for the same node)
        vector<int> stops_arr(n, INT_MAX);

        // Start at the source with 0 cost and 0 stops
        pq.push({0, src, 0});
        
        while (!pq.empty()) {
            auto [cost, node, stops] = pq.top();
            pq.pop();
            
            // If we have already found a path to this node with fewer or equal stops, skip
            if (stops > stops_arr[node]) {
                continue;
            }
            
            // Update the minimum stops to reach this node
            stops_arr[node] = stops;

            // If we've reached the destination, return the cost.
            // Since we use a priority queue, the first time we reach the destination,
            // it's guaranteed to be the cheapest path.
            if (node == dst) {
                return cost;
            }
            
            // If we have stops left (at most k stops means at most k+1 flights)
            if (stops <= k) {
                for (auto& edge : adj[node]) {
                    int neighbor = edge.first;
                    int price = edge.second;
                    pq.push({cost + price, neighbor, stops + 1});
                }
            }
        }
        
        // If the loop finishes and we haven't reached the destination
        return -1;
    }
};