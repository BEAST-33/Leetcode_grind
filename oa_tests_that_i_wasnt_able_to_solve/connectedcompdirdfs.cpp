// i have a 1 indexed array where A[i] has the index of the element to which a particular virus can transfer. all elements have a cost array. the job is to set filters to catch the virus with th emin cost. my idea was to find the the index having min cost in each connected component , wasnt able to implement it using bfs and traversing each node
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// Function to solve the virus filter problem
long long find_minimum_cost() {
    int n;
    std::cin >> n;

    // We use 1-based indexing to match the problem statement, so vectors are size n+1
    std::vector<int> A(n + 1);
    std::vector<int> cost(n + 1);

    for (int i = 1; i <= n; ++i) {
        std::cin >> A[i];
    }
    for (int i = 1; i <= n; ++i) {
        std::cin >> cost[i];
    }

    long long total_min_cost = 0;
    // States: 0 = unvisited, 1 = currently visiting, 2 = fully visited
    std::vector<int> states(n + 1, 0);

    // Iterate through each node to find all components
    for (int i = 1; i <= n; ++i) {
        // If state is 0, we've found a new, unprocessed component
        if (states[i] == 0) {
            
            // --- Step 1: Trace the path to find a cycle or an old component ---
            int current_node = i;
            while (states[current_node] == 0) {
                states[current_node] = 1; // Mark as 'visiting'
                current_node = A[current_node];
            }

            // --- Step 2: If we found a new cycle, calculate its minimum cost ---
            // A new cycle is found if we land on a node that is also 'visiting'
            if (states[current_node] == 1) {
                int cycle_start_node = current_node;
                int min_cycle_cost = cost[cycle_start_node];
                
                int temp_node = A[cycle_start_node];
                while (temp_node != cycle_start_node) {
                    min_cycle_cost = std::min(min_cycle_cost, cost[temp_node]);
                    temp_node = A[temp_node];
                }
                total_min_cost += min_cycle_cost;
            }
            // If states[current_node] is 2, our path simply merged into an already
            // processed component. No new filter is needed for this path.

            // --- Step 3: Mark all nodes in the current path as fully visited ---
            current_node = i;
            while (states[current_node] == 1) {
                states[current_node] = 2; // Mark as 'fully visited'
                current_node = A[current_node];
            }
        }
    }

    return total_min_cost;
}

int main() {
    // Standard setup for faster C++ I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout << find_minimum_cost() << std::endl;

    return 0;
}