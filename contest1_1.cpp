#include <bits/stdc++.h>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpl = vector<pll>;
using ld = long double;
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(x) ((int)(x).size())
#define ft first
#define st second
#define ff(i, n) for (int i = 0; i < n; i++)
#define fb(i, n) for (int i = n-1; i >=0; i--)
#define ff1(i, n) for (int i = 1; i <= n; i++)
#define fb1(i, n) for (int i = n; i > 0; i--)
#define pn(x) cout << x << endl
#define ps(x) cout << x << " "
#define yesno(c) cout << ((c) ? "YES" : "NO") << endl
#define read(x) ll x; cin >> x;
#define read2(x, y) ll x, y; cin >> x >> y;
#define read3(x, y, z) ll x, y, z; cin >> x >> y >> z;
#define readv(v, n) vl v(n); ff(i, n) cin >> v[i];
#define readv1(v, n) vl v(n+1); ff(i, n) cin >> v[i+1];
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int N = 2e5 + 5;
template<class T> bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> void madd(T &a, T b) {
    a += b;
    if (a >= MOD) a -= MOD;
}
ll primegen(ll i) {
    if (i <= 0) return -1;

    static vl primes;
    if (primes.empty()) primes.pb(2);

    ll candidate = primes.back() + 1;
    if (candidate % 2 == 0) candidate++;

    while ((ll)primes.size() < i) {
        bool is_prime = true;
        for (ll p : primes) {
            if (p * p > candidate) break;
            if (candidate % p == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) primes.pb(candidate);
        candidate += 2;
    }

    return primes[i - 1];
}
ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}
ll modInverse(ll n) {
    return power(n, MOD - 2);
}
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int cntz = 0;
        int n = nums.size();
        ff(i, n) if (nums[i] == 0) cntz++;
        if (cntz == 0 || cntz == n) return 0;
        int cur = 0;
        ff(i, cntz) if (nums[i] == 0) cur++;
        int best = cur;
        for (int i = cntz; i < n; i++) {
            if (nums[i] == 0) cur++;
            if (nums[i - cntz] == 0) cur--;
            best = max(best, cur);
        }
        return cntz - best;
    }
};