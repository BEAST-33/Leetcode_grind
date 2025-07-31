#include <iostream>
#include <vector>
#include <numeric>   // For std::accumulate
#include <algorithm> // For std::sort
#include <vector>

long long calculate_operations(std::vector<int>& arr) {
    if (arr.empty()) {
        return 0;
    }

    long long n = arr.size();

    // Step 1: Calculate sum to determine the final state
    long long sum = std::accumulate(arr.begin(), arr.end(), 0LL);

    // Step 2: Determine the target values
    long long target_low = sum / n;
    long long num_high_values = sum % n;

    // Step 3: Sort the initial array to match it against the final state
    std::sort(arr.begin(), arr.end());

    // Step 4: Calculate the total deficit (number of operations)
    long long operations = 0;
    // The first (n - num_high_values) elements in the sorted array
    // should become target_low. The rest should become target_low + 1.
    for (long long i = 0; i < n; ++i) {
        long long current_val = arr[i];
        long long target_val;

        if (i < n - num_high_values) {
            target_val = target_low;
        } else {
            target_val = target_low + 1;
        }

        if (current_val < target_val) {
            operations += (target_val - current_val);
        }
    }

    return operations;
}

int main() {
    // Example 1
    std::vector<int> arr1 = {0, 0, 15, 5};
    std::cout << "Array: {0, 0, 15, 5}" << std::endl;
    std::cout << "Total operations required: " << calculate_operations(arr1) << std::endl;
    std::cout << "-------------------------" << std::endl;

    // Example 2
    std::vector<int> arr2 = {10, 20, 60};
    std::cout << "Array: {10, 20, 60}" << std::endl;
    std::cout << "Total operations required: " << calculate_operations(arr2) << std::endl;
    std::cout << "-------------------------" << std::endl;
    
    // Example 3
    std::vector<int> arr3 = {10, 2, 4}; // Sum=16, n=3. Final state {5, 5, 6}
    std::cout << "Array: {10, 2, 4}" << std::endl;
    std::cout << "Total operations required: " << calculate_operations(arr3) << std::endl;


    return 0;
}