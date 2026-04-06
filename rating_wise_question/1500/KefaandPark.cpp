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

void dfs(ll curr, ll parent, vector<vector<ll>> &adj, ll &ans, ll &m, vector<ll> &isCat, ll currC) {
    
    if(isCat[curr]) currC++;
    else currC = 0;

    if(currC > m) return;

    bool isLeaf = true;

    for(auto child : adj[curr]){
        if(child != parent){
            isLeaf = false;
            dfs(child, curr, adj, ans, m, isCat, currC);
        }
    }

    if(isLeaf && currC <= m) ans++;
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

    ll n,m;
    cin>>n>>m;

    vector<ll> isCat(n);
    inputV(isCat,n);

    vector<vector<ll>> adj(n);

    for(ll i = 0; i<n-1; i++){
        ll a,b;
        cin>>a>>b;
        a--;
        b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll ans = 0;
  

    dfs(0,-1,adj,ans,m,isCat,0);

    cout<<ans<<endl;
}