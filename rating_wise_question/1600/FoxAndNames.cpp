#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MOD = 1000000007; // 1e9 + 7

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

vector<vector<ll>> adj(26);
vector<ll> vis(26);
string ans;
bool hasCycle;

void dfs(ll node) {
    vis[node] = 1;

    for (ll nei : adj[node]) {
        if (vis[nei] == 0) {
            dfs(nei);
            if (hasCycle) return;
        }
        else if (vis[nei] == 1) {
            hasCycle = true;
            return;
        }
    }

    vis[node] = 2;
    ans.push_back(char('a' + node));
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
    ll n;
    cin >> n;

    vector<string> names(n);
    for (ll i = 0; i < n; i++) cin >> names[i];

    adj.assign(26, vector<ll>());
    vis.assign(26, 0);
    ans = "";
    hasCycle = false;

    for (ll i = 0; i < n - 1; i++) {
        string a = names[i];
        string b = names[i + 1];

        ll len = min(a.size(), b.size());
        bool found = false;

        for (ll j = 0; j < len; j++) {
            if (a[j] != b[j]) {
                adj[a[j] - 'a'].push_back(b[j] - 'a');
                found = true;
                break;
            }
        }

        if (!found && a.size() > b.size()) {
            cout << "Impossible"<<endl;
            return;
        }
    }

    for (ll i = 0; i < 26; i++) {
        if (vis[i] == 0) {
            dfs(i);
            if (hasCycle) {
                cout << "Impossible"<<endl;
                return;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}