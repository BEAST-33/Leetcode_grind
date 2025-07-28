//i had a tree given and given q queries each having U V X. if U and V has the root as the common ancestor then swap the subtrees rooted at u and v, if they dont then dont swat and find the sum of the subtree rooted at X. after each query reswap if previously swapped . what is the best way to solve this
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// --- Global Variables for Simplicity ---
// All functions can access these directly.
int n;
int root = 1; // Assuming 1-based indexing
std::vector<std::vector<int>> adj;
std::vector<long long> value;
std::vector<int> parent;
std::vector<int> depth;
std::vector<long long> subtree_sum;
std::vector<int> start_time;
std::vector<int> end_time;
int timer = 0;

// --- Helper Functions ---

// 1. DFS for pre-computation
void dfs(int u, int p, int d) {
    parent[u] = p;
    depth[u] = d;
    start_time[u] = ++timer;
    subtree_sum[u] = value[u];

    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
            subtree_sum[u] += subtree_sum[v];
        }
    }
    end_time[u] = ++timer;
}

// 2. Simple LCA function using parent pointers
int get_lca(int u, int v) {
    if (depth[u] < depth[v]) {
        std::swap(u, v);
    }
    while (depth[u] > depth[v]) {
        u = parent[u];
    }
    if (u == v) {
        return u;
    }
    while (parent[u] != parent[v]) {
        u = parent[u];
        v = parent[v];
    }
    return parent[u];
}

// 3. O(1) Ancestor check using Euler tour times
bool is_ancestor(int u, int v) {
    return start_time[u] <= start_time[v] && end_time[v] <= end_time[u];
}


// --- Main Program ---
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // --- 1. Read Input ---
    std::cin >> n; // Read the number of nodes

    // Resize all global vectors based on n
    adj.resize(n + 1);
    value.resize(n + 1);
    parent.resize(n + 1);
    depth.resize(n + 1);
    subtree_sum.resize(n + 1);
    start_time.resize(n + 1);
    end_time.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        std::cin >> value[i]; // Read value for each node
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v; // Read each edge
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // --- 2. Run Pre-computation ---
    dfs(root, root, 0); // Start DFS from the root

    // --- 3. Process Queries ---
    int q;
    std::cin >> q; // Read the number of queries
    while (q--) {
        int u, v, x;
        std::cin >> u >> v >> x; // Read each query

        int lca_node = get_lca(u, v);

        if (lca_node != root) {
            // Case 1: No swap. Answer is the pre-computed sum.
            std::cout << subtree_sum[x] << "\n";
        } else {
            // Case 2: Swap happens. Calculate the new sum.
            long long current_sum = subtree_sum[x];
            
            if (is_ancestor(x, u)) {
                current_sum += subtree_sum[v] - subtree_sum[u];
            }
            
            if (is_ancestor(x, v)) {
                current_sum += subtree_sum[u] - subtree_sum[v];
            }

            std::cout << current_sum << "\n";
        }
    }

    return 0;
}