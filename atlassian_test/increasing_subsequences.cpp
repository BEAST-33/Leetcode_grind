#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
//there is a string of numbers, find the bitwise or of elements forming a strictly increasing subsequence and return a list of these bitwise or results in ascending order 
using namespace std;

// Helper to generate all strictly increasing subsequences using recursion
void dfs(const vector<int>& nums, int index, vector<int>& path, set<int>& result) {
    for (int i = index; i < nums.size(); ++i) {
        if (path.empty() || nums[i] > path.back()) {
            path.push_back(nums[i]);

            // Compute bitwise OR of the current strictly increasing subsequence
            int or_result = 0;
            for (int num : path)
                or_result |= num;

            result.insert(or_result);

            dfs(nums, i + 1, path, result);
            path.pop_back();
        }
    }
}

vector<int> bitwiseOrOfIncreasingSubsequences(const string& num_str) {
    vector<int> nums;
    for (char c : num_str)
        nums.push_back(c - '0');

    set<int> result;
    vector<int> path;
    dfs(nums, 0, path, result);

    return vector<int>(result.begin(), result.end()); // sorted by default in set
}

int main() {
    string input = "1352";
    vector<int> output = bitwiseOrOfIncreasingSubsequences(input);

    for (int val : output)
        cout << val << " ";
    cout << endl;

    return 0;
}
