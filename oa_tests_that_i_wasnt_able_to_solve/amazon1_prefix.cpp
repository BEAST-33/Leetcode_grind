#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Calculates the maximum number of zeroes achievable in the sequence.
 *
 * @param sequenceData A vector of positive integers.
 * @return The maximum number of zeroes.
 */
int calculateMaxZeroes(std::vector<int> sequenceData) {
    int n = sequenceData.size();
    if (n == 0) {
        return 0;
    }

    // 1. Precompute the minimum value for each prefix
    std::vector<int> min_left(n);
    min_left[0] = sequenceData[0];
    for (int i = 1; i < n; ++i) {
        min_left[i] = std::min(min_left[i - 1], sequenceData[i]);
    }

    int zeros = 0;
    long long ops_from_right = 0; // Cumulative operations committed from the right

    // 2. Iterate from right to left, making greedy choices
    for (int i = n - 1; i >= 0; --i) {
        long long current_val = sequenceData[i];
        long long max_allowed_ops = min_left[i];

        // 3. Check if we can make the current element zero
        if (ops_from_right <= current_val && current_val <= max_allowed_ops) {
            zeros++;
            // Greedily commit to making this a zero
            ops_from_right = current_val;
        }
    }

    return zeros;
}

int main() {
    // Example from the problem description
    std::vector<int> sequenceData = {3, 2, 4, 4, 2};
    int max_zeros = calculateMaxZeroes(sequenceData);
    // Expected output: 3
    std::cout << "For sequence [3, 2, 4, 4, 2], max zeroes: " << max_zeros << std::endl;

    // Another example
    std::vector<int> sequenceData2 = {1, 2, 3, 4, 5};
    int max_zeros2 = calculateMaxZeroes(sequenceData2);
    // Expected output: 1
    std::cout << "For sequence [1, 2, 3, 4, 5], max zeroes: " << max_zeros2 << std::endl;

    return 0;
}