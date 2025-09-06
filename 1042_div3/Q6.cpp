#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MOD = 1000000007; // 1e9 + 7

const ll N = 200005;
vector<ll> adj[N];
ll deg[N], leaves[N], ss[N];


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

void dl(ll u, ll parent) {
    if (deg[u] == 1) { 
        leaves[u] = 1;
    }
    for (ll v : adj[u]) {
        if (v == parent) continue;
        dl(v, u);
        leaves[u] += leaves[v];
    }
}


void ds(ll u, ll parent) {
    ss[u] = 1;
    for (ll v : adj[u]) {
        if (v == parent) continue;
        ds(v, u);
        ss[u] += ss[v];
    }
}

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

void solve() {
    //Rajvardhan Patil

        ll n;


        cin >> n;

       
        for (ll i = 1; i <= n; i++) {
            adj[i].clear();
            deg[i] = leaves[i] = ss[i] = 0;
        }

       
        for (ll i = 0; i < n - 1; i++) {
            ll u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }

        
        
        for (ll i = 1; i <= n; i++) {
            if (deg[i] == n - 1) {
               cout<<0<<endl;
                return;
            }
        }
        

        
        dl(1, 0);
        ds(1, 0);

        ll tot = leaves[1];
        ll ans = INT_MAX;

        
        for (ll i = 1; i <= n; i++) {
            ll ops = 0;

            
            for (ll v : adj[i]) {
                if (ss[v] < ss[i]) {
                    if (ss[v] > 1) {
                        ops += leaves[v];
                    }
                }
            }

            
            if (i != 1) {
                ll outs = tot - leaves[i];
                if (n - ss[i] > 1) {
                    ops += outs;
                }
            }

            ans = min(ans, ops);
        }

        cout << ans << endl;
    

}