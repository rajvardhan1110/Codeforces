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

int n, m;
vector<ll> boys, girls;
int dp[101][101];

int dfs(int i, int j) {
    if (i == n || j == m)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;

    if (abs(boys[i] - girls[j]) <= 1) {
        ans = 1 + dfs(i + 1, j + 1);
    } else {
        ans = max(dfs(i + 1, j), dfs(i, j + 1));
    }

    return dp[i][j] = ans;
}

void solve() {
    // Rajvardhan Patil
    cin >> n;
    inputV(boys, n);

    cin >> m;
    inputV(girls, m);

    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());

    memset(dp, -1, sizeof(dp));

    cout << dfs(0, 0) << "\n";
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
