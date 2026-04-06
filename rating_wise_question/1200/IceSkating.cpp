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

int n;
vector<pair<int,int>> v;
vector<bool> vis;

void dfs(int i) {
    vis[i] = true;
    for (int j = 0; j < n; j++) {
        if (!vis[j]) {
            if (v[i].first == v[j].first || v[i].second == v[j].second) {
                dfs(j);
            }
        }
    }
}

void solve() {
    cin >> n;
    v.resize(n);
    vis.assign(n, false);

    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    int components = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
            components++;
        }
    }

    cout << components - 1 << endl;
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