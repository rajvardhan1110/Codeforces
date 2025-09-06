#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MOD = 1000000007;

void inputV(vector<ll> &v, int size) {
    v.resize(size);
    for (int i = 0; i < size; i++) {
        cin >> v[i];
    }
}

void printV(const vector<ll> &v) {
    for (ll val : v) {
        cout << val << " ";
    }
    cout << endl;
}

ll solve2(ll num, ll pos, vector<vector<ll>> &dp, ll k, ll n) {
    if (pos == k) return 1;

    if (dp[num][pos] != -1) return dp[num][pos];

    ll ans = 0;
    for (ll j = num; j <= n; j += num) {
        ans = (ans + solve2(j, pos + 1, dp, k, n)) % MOD;
    }

    return dp[num][pos] = ans;
} 

void solve() {
    // Rajvardhan Patil
    ll n, k;
    cin >> n >> k;

    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, -1));

    ll total = 0;
    for (ll i = 1; i <= n; ++i) {
        total = (total + solve2(i, 1, dp, k, n)) % MOD;
    }

    cout << total << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
