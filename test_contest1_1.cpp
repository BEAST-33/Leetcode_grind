#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
using vl = vector<ll>;
#define ff(i, n) for (int i = 0; i < n; i++)
#define pb push_back

class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int cntz = 0;
        int n = nums.size();
        ff(i, n) {
            if (nums[i] == 0) cntz++;
        }
        int j = n - 1;
        int iter = cntz;
        int cnt2 = 0;
        while (iter--) {
            if (nums[j] == 0) cnt2++;
            j--;
        }
        return (cntz - cnt2);
    }
};

void test(vector<int> nums, int expected, const string& desc) {
    Solution sol;
    int got = sol.minimumSwaps(nums);
    bool pass = (got == expected);
    cout << (pass ? "[PASS]" : "[FAIL]") << " " << desc
         << " | expected=" << expected << " got=" << got << "\n";
}

int main() {
    // Basic cases
    test({0, 1, 0, 1, 1, 0}, 1, "3 zeros, 1 swap needed");
    test({0, 0, 0}, 0, "all zeros, no swap");
    test({1, 1, 1}, 0, "no zeros, nothing to move");
    test({1, 0, 1, 0}, 1, "2 zeros, 1 swap");
    test({1, 1, 0, 0}, 0, "zeros already at end");
    test({0, 0, 1, 1}, 2, "zeros at front, 2 swaps");
    test({0}, 0, "single zero");
    test({1}, 0, "single one");
    test({0, 1, 0, 1, 0}, 2, "3 zeros alternating");
    // Edge: zeros already grouped at end
    test({1, 1, 1, 0, 0, 0}, 0, "zeros grouped at end already");
    return 0;
}
