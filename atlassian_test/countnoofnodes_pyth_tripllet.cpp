#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // Required for std::sort
#include <array>     // For a simple stack-allocated array

/**
 * @brief Performs Breadth-First Search to find shortest paths from a start node.
 * * @param start_node The node to start the search from.
 * @param n Total number of nodes in the graph.
 * @param adj The adjacency list representation of the graph.
 * @return A vector containing the shortest distance from start_node to every other node.
 */
std::vector<int> bfs(int start_node, int n, const std::vector<std::vector<int>>& adj) {
    std::vector<int> distances(n, -1); // Initialize distances to -1 (unreachable)
    std::queue<int> q;

    // The distance to the start node itself is 0
    if (start_node < n) {
        distances[start_node] = 0;
        q.push(start_node);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (distances[v] == -1) {
                distances[v] = distances[u] + 1;
                q.push(v);
            }
        }
    }
    return distances;
}

/**
 * @brief Finds the number of nodes whose distances from x, y, and z form a Pythagorean triplet.
 * * @param n The total number of nodes (0 to n-1).
 * @param edges A list of pairs representing the undirected edges.
 * @param x The first special node.
 * @param y The second special node.
 * @param z The third special node.
 * @return The count of nodes satisfying the condition.
 */
int findNodesWithPythagoreanDistances(int n, const std::vector<std::vector<int>>& edges, int x, int y, int z) {
    if (n == 0) return 0;
    
    // Step 1: Build the graph using an adjacency list
    std::vector<std::vector<int>> adj(n);
    for (const auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    // Step 2: Calculate distances from x, y, and z to all other nodes
    std::vector<int> dist_from_x = bfs(x, n, adj);
    std::vector<int> dist_from_y = bfs(y, n, adj);
    std::vector<int> dist_from_z = bfs(z, n, adj);

    // Step 3: Iterate through all nodes and check the Pythagorean condition
    int pythagorean_node_count = 0;
    for (int w = 0; w < n; ++w) {
        // Use long long to prevent overflow when squaring, just in case.
        long long a = dist_from_x[w];
        long long b = dist_from_y[w];
        long long c = dist_from_z[w];

        // A standard Pythagorean triplet consists of POSITIVE integers.
        // This also implicitly checks that the node 'w' is reachable from x, y, and z.
        if (a > 0 && b > 0 && c > 0) {
            // Sort the sides to easily check the condition a^2 + b^2 = c^2
            std::array<long long, 3> sides = {a, b, c};
            std::sort(sides.begin(), sides.end());

            // Check the Pythagorean theorem
            if ((sides[0] * sides[0]) + (sides[1] * sides[1]) == (sides[2] * sides[2])) {
                pythagorean_node_count++;
            }
        }
    }

    return pythagorean_node_count;
}

// Example usage
int main() {
    // Let's create a graph where one node (10) satisfies the condition
    // for x=0, y=1, z=2. Let the distances be 3, 4, 5.
    int n = 13;
    std::vector<std::vector<int>> edges = {
        {0, 3}, {3, 4}, {4, 10},             // Path x -> 10 has length 3
        {1, 5}, {5, 6}, {6, 7}, {7, 10},     // Path y -> 10 has length 4
        {2, 8}, {8, 9}, {9, 11}, {11, 12}, {12, 10} // Path z -> 10 has length 5
    };
    int x = 0, y = 1, z = 2;

    int result = findNodesWithPythagoreanDistances(n, edges, x, y, z);

    std::cout << "Input: n=" << n << ", x=" << x << ", y=" << y << ", z=" << z << std::endl;
    std::cout << "Result: Number of nodes satisfying the condition is " << result << std::endl; // Expected: 1

    return 0;
}