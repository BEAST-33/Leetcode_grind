#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// This function checks if it's possible to produce a given number of alloy units ('num_alloys')
// within the specified 'budget'.
//
// Parameters:
// - n: The number of different metals available.
// - budget: The maximum amount of money that can be spent.
// - stock: A vector representing the initial quantity of each metal available.
// - composition: A vector where composition[i] is the amount of metal 'i' needed for one unit of alloy.
// - cost: A vector where cost[i] is the price to buy one unit of metal 'i'.
//
// Returns:
// - true if 'num_alloys' can be produced within the budget.
// - false otherwise.
bool can_produce(long long num_alloys, int n, long long budget, const vector<int>& stock, const vector<int>& composition, const vector<int>& cost) {
    long long current_cost = 0;

    // Iterate through each metal to calculate the cost.
    for (int i = 0; i < n; ++i) {
        // Calculate the total amount of metal 'i' required to produce 'num_alloys' units.
        long long required_metal = num_alloys * composition[i];

        // If the required amount is more than what's in stock, we need to buy the difference.
        if (required_metal > stock[i]) {
            long long to_buy = required_metal - stock[i];
            current_cost += to_buy * cost[i];
        }

        // If the running cost already exceeds the budget, we can stop early.
        if (current_cost > budget) {
            return false;
        }
    }

    // If we get through all metals without exceeding the budget, it's possible.
    return true;
}

int main() {
    // --- Example Input ---
    // Number of metals
    int n = 3;
    // Maximum budget
    long long budget = 100;
    // Stock of each metal
    vector<int> stock = {10, 20, 5};
    // Composition for one alloy unit
    vector<int> composition = {2, 1, 3};
    // Cost to buy one unit of each metal
    vector<int> cost = {3, 4, 5};

    // --- Binary Search to find the maximum number of alloys ---

    // 'low' is the minimum possible number of alloys (0).
    long long low = 0;
    // 'high' is a safe upper bound. We can estimate it.
    // A loose upper bound could be budget + max_stock, but 2e14 is very safe.
    long long high = 2e14;
    // 'ans' will store the maximum number of alloys we can make.
    long long ans = 0;

    // Perform binary search on the number of alloys.
    while (low <= high) {
        // Calculate the middle point to test.
        long long mid = low + (high - low) / 2;

        // Check if it's possible to produce 'mid' alloys.
        if (can_produce(mid, n, budget, stock, composition, cost)) {
            // If we can produce 'mid' alloys, it might be possible to produce even more.
            // So, we store 'mid' as a potential answer and search in the upper half.
            ans = mid;
            low = mid + 1;
        } else {
            // If we can't produce 'mid' alloys, we need to try a smaller number.
            // So, we search in the lower half.
            high = mid - 1;
        }
    }

    // Output the result.
    cout << "Maximum number of alloy units that can be made: " << ans << endl;

    return 0;
}
