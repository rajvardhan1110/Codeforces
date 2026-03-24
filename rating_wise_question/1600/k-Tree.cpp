#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MOD = 1000000007; // 1e9 + 7

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

void createsieve(vector<bool> &prime, int n) {
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < n; i++) {
        if (prime[i]) {
            for (int j = i * i; j < n; j += i) {
                prime[j] = false;
            }
        }
    }
}

bool PowOfTwo(ll n) {
    return n > 0 && (n & (n - 1)) == 0;
}

ll binExpRecur(ll a, ll b) {
    if (b == 0) return 1;
    ll res = binExpRecur(a, b / 2);
    if (b & 1) {
        return (a * ((res * res) % MOD)) % MOD;
    } else {
        return (res * res) % MOD;
    }
}

ll n, k, d;
ll dp[105][2];  

ll dfs(ll sum, ll usedBig) {
    if (sum == 0) {
        return usedBig ? 1 : 0;
    }

    if (sum < 0) return 0;

    if (dp[sum][usedBig] != -1)
        return dp[sum][usedBig];

    ll ans = 0;

    for (ll w = 1; w <= k; w++) {
        ll newUsedBig = usedBig || (w >= d);
        ans = (ans + dfs(sum - w, newUsedBig)) % MOD;
    }

    return dp[sum][usedBig] = ans;
}

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}

void solve() {
    //Rajvardhan Patil

    cin >> n >> k >> d;

    for (int i = 0; i <= n; i++) {
        dp[i][0] = dp[i][1] = -1;
    }

    cout << dfs(n, 0) << endl;
}