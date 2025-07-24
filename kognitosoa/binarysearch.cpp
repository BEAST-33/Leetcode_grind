#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// This function checks if it's possible for n players to collect m points within a given time 't'.
// It assumes players and points vectors are sorted.
bool check(long long t, int n, int m, const vector<int>& players, const vector<int>& points) {
    int point_idx = 0; // Index of the first uncollected point.

    // Greedily assign points to each player from left to right.
    for (int i = 0; i < n; ++i) {
        if (point_idx >= m) {
            // All points have been collected.
            return true;
        }

        long long p_pos = players[i];
        long long start_pos = points[point_idx];
        
        long long dist_to_start = abs(p_pos - start_pos);

        if (dist_to_start > t) {
            // Player cannot even reach the first point of the segment.
            // If they are to the left, a player further right might still be able to help.
            // If they are to the right, no subsequent player (further right) can help.
            if (p_pos < start_pos) {
                continue;
            } else {
                return false;
            }
        }

        // This player CAN help. Let's calculate the maximum reach.
        long long reach;
        if (p_pos < start_pos) {
            // Player is to the left. The only efficient strategy is to sweep right.
            // Time to clear segment [start_pos, k] is (k - p_pos). So k <= p_pos + t.
            reach = p_pos + t;
        } else { // p_pos >= start_pos
            // Player is at or to the right. They have two strategies.
            
            // Strategy 1: Go left to start_pos, then sweep right.
            // Time remaining after reaching start_pos is (t - dist_to_start).
            // From start_pos, they can reach: start_pos + (t - dist_to_start).
            long long reach1 = start_pos + (t - dist_to_start);
            
            // Strategy 2: Go right to point k, then sweep left to start_pos.
            // Time taken = (k - p_pos) + (k - start_pos) <= t
            // Solving for k gives: k <= (t + p_pos + start_pos) / 2
            long long reach2 = (t + p_pos + start_pos) / 2;

            reach = max(reach1, reach2);
        }
        
        // Find how many points are within the calculated reach using binary search.
        auto it = upper_bound(points.begin() + point_idx, points.end(), reach);
        point_idx = distance(points.begin(), it);
    }

    // After all players have moved, check if all points are collected.
    return point_idx >= m;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> players(n);
    for (int i = 0; i < n; ++i) {
        cin >> players[i];
    }

    vector<int> points(m);
    for (int i = 0; i < m; ++i) {
        cin >> points[i];
    }

    // The greedy check function requires sorted arrays.
    sort(players.begin(), players.end());
    sort(points.begin(), points.end());

    long long low = 0;
    // A safe upper bound for time.
    long long high = 4000000000LL; 
    long long ans = high;

    // Binary search for the minimum time.
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid, n, m, players, points)) {
            // This time is possible, so it's a potential answer.
            // Try for an even smaller time.
            ans = mid;
            high = mid - 1;
        } else {
            // This time is not enough, need more time.
            low = mid + 1;
        }
    }

    cout << ans << endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}