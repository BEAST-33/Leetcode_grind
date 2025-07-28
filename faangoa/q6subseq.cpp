#include <iostream>
#include <vector>

/**
 * @brief Solves the Count Subsequences problem.
 * * This function reads an integer N and an array of N integers. It then calculates
 * the number of non-empty subsequences that do not contain three consecutive
 * even or three consecutive odd numbers. The result is printed modulo 10^9 + 7.
 * * The solution uses a dynamic programming approach with constant space complexity.
 * It iterates through the array, maintaining counts of valid subsequences ending
 * in specific patterns (one even, two evens, one odd, two odds).
 */
void solve() {
    int n;
    std::cin >> n;
    
    // Define the modulus for the final answer
    long long mod = 1e9 + 7;

    // Initialize counts for subsequences ending in:
    // e1: one even, e2: two evens, o1: one odd, o2: two odds
    long long e1 = 0, e2 = 0, o1 = 0, o2 = 0;

    for (int i = 0; i < n; ++i) {
        int current_num;
        std::cin >> current_num;
        
        if (current_num % 2 == 0) { // Current number is Even
            // Calculate new subsequences ending in EE. This must use the old `e1` count.
            long long new_e2 = e1;
            // Calculate new subsequences ending in E.
            long long new_e1 = (1 + o1 + o2) % mod;
            
            // Update total counts
            e1 = (e1 + new_e1) % mod;
            e2 = (e2 + new_e2) % mod;
        } else { // Current number is Odd
            // Calculate new subsequences ending in OO. This must use the old `o1` count.
            long long new_o2 = o1;
            // Calculate new subsequences ending in O.
            long long new_o1 = (1 + e1 + e2) % mod;
            
            // Update total counts
            o1 = (o1 + new_o1) % mod;
            o2 = (o2 + new_o2) % mod;
        }
    }

    // The total number of valid non-empty subsequences is the sum of all counts.
    long long total = (e1 + e2 + o1 + o2) % mod;
    std::cout << total << std::endl;
}

int main() {
    // Fast I/O for performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    solve();
    
    return 0;
}