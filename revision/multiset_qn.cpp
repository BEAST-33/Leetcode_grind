#include <iostream>
#include <set>       // Required for std::multiset
#include <iterator>  // Required for std::next

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int Q;
    std::cout << "Enter the number of queries: ";
    std::cin >> Q;

    // A multiset keeps elements sorted automatically and allows duplicates.
    std::multiset<int> data;

    std::cout << "Enter " << Q << " queries (num k):\n";
    for (int i = 0; i < Q; ++i) {
        int num, k;
        std::cin >> num >> k;

        // 1. Insert the new number. Time complexity: O(log N)
        data.insert(num);

        // 2. Find the k-th largest element.
        // Get a reverse iterator to the largest element (the end of the set).
        auto it = data.rbegin();

        // Advance the iterator k-1 times to reach the k-th largest element.
        // This step has a time complexity of O(k).
        std::advance(it, k - 1);
        
        // Print the element.
        std::cout << "k-th largest: " << *it << "\n";
    }

    return 0;
}