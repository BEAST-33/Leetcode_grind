#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// DFS to find connected indices that can be swapped among each other
void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& component) {
    visited[node]= true;
    component.push_back(node);
    for ( int neighbour : adj[node]){
        if (!visited[neighbour]) {
            dfs(neighbour, adj, visited, component);
        }
    }
}

int main() {
    int N, M;
    cin >> N;

    // 1-based indexing: so use N+1
    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    cin >> M;

    // Adjacency list for the graph of swappable indices
    vector<vector<int>> adj(N + 1);

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Visited vector to track which indices we've processed
    vector<bool> visited(N + 1, false);

    // Process each connected component
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            vector<int> indices;  // stores all positions in this connected component
            dfs(i, adj, visited, indices);
            vector<int> values;
            for (int idx : indices) {
                values.push_back(A[idx]);
            }

            // Sort indices (positions) in increasing order
            sort(indices.begin(), indices.end());

            // Sort values in decreasing order to place largest in odd positions
            sort(values.rbegin(), values.rend());

            // Assign values back to array A at sorted positions
            for (int j = 0; j < indices.size(); ++j) {
                A[indices[j]] = values[j];
            }
        }
    }

    // Compute F(A) = A[1] - A[2] + A[3] - A[4] + ...
    long long result = 0;
    for (int i = 1; i <= N; ++i) {
        if (i % 2 == 1) result += A[i];  // odd index: add
        else result -= A[i];            // even index: subtract
    }

    cout << result << endl;
    return 0;
}