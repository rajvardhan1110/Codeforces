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

void solve();

void dfs(ll curr,vector<ll> &grp,vector<vector<ll>>& adj,bool &flag){
    if(flag){
        return;
    }

    if(grp[curr] == -1){
        grp[curr] = 0;
    }

    for(auto i : adj[curr]){
        if(grp[i] != -1){
            if(grp[i] == grp[curr]){
                flag = true;
                return;
            }
        }else{
            grp[i] = !grp[curr];
            dfs(i,grp,adj,flag);
        }
    }
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

void solve() {
    //Rajvardhan Patil

    ll n,e;
    cin>>n>>e;

    vector<vector<ll>> adj(n+1);
    vector<pair<ll,ll>> ed;

    for(ll i = 0; i<e; i++){
        ll u,v;
        cin>>u>>v;

        adj[v].push_back(u);
        adj[u].push_back(v);

        ed.push_back({u,v});
    }

    vector<ll> grp(n+1,-1);

    bool flag = false;

    
    dfs(1, grp, adj, flag);
        

    if(flag){
        cout<<"NO"<<endl;
        return;
    }


    cout<<"YES"<<endl;

    for(auto i : ed){
        ll u = i.first;

        if(grp[u] == 0){
            cout << 1;
        }else{
            cout << 0;
        }
    }



}