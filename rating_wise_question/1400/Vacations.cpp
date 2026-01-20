#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MOD = 1000000007; // 1e9 + 7

ll n;
vector<ll> a;
ll dp[105][3];

void inputV(vector<ll> &v, ll size) {
    v.resize(size);
    for (ll i = 0; i < size; i++) {
        cin >> v[i];
    }
}

void printV(const vector<ll> &v) {
    for (ll val : v) {
        cout << val << " ";
    }
    cout << endl;
}

void createsieve(vector<bool> &prime, ll n) {
    prime[0] = prime[1] = false;
    for (ll i = 2; i * i < n; i++) {
        if (prime[i]) {
            for (ll j = i * i; j < n; j += i) {
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

ll dfs(ll day, ll last) {
    if (day > n) return 0;

    if (dp[day][last] != -1)
        return dp[day][last];

    ll ans = 1 + dfs(day + 1, 0); 

    if ((a[day] == 1 || a[day] == 3) && last != 1) {
        ans = min(ans, dfs(day + 1, 1));
    }

    
    if ((a[day] == 2 || a[day] == 3) && last != 2) {
        ans = min(ans, dfs(day + 1, 2));
    }

    return dp[day][last] = ans;
}

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}

void solve() {
    // Rajvardhan Patil
    cin >> n;

    a.resize(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << dfs(1, 0) << endl;
}