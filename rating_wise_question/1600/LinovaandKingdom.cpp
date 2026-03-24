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

vector<vector<int>> adj;
vector<int> depth;
vector<int> subtree;

void dfs(int node, int parent) {
    subtree[node] = 1;

    for (int child : adj[node]) {
        if (child == parent) continue;

        depth[child] = depth[node] + 1;
        dfs(child, node);

        subtree[node] += subtree[child];
    }
}

void solve() {
    // Rajvardhan Patil
    
    int n, k;
    cin >> n >> k;

    adj.assign(n + 1, vector<int>());
    depth.assign(n + 1, 0);
    subtree.assign(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    vector<ll> values;

    for (int i = 1; i <= n; i++) {
        ll val = (ll)depth[i] - (subtree[i] - 1);
        values.push_back(val);
    }

    sort(values.rbegin(), values.rend());

    ll ans = 0;
    for (int i = 0; i < k; i++) {
        ans += values[i];
    }

    cout << ans << "\n";
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
