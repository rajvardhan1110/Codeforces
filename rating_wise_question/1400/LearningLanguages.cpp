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

void dfs(vector<ll> &vis,vector<vector<ll>> &cantalk,ll i){
    vis[i] = 1;

    for(auto j : cantalk[i]){
        if(vis[j] == 0){
            dfs(vis,cantalk,j);
        }
    }
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

    vector<vector<ll>> lan(m+1);
    bool flag = false;

    for(ll i = 0; i<n; i++){
        ll x;
        cin>>x;

        if(x > 0){
            flag = true;
        }

        while(x--){
            ll a;
            cin>>a;

            lan[a].push_back(i);
        }
    }

    if(!flag){
        cout<<n<<endl;
        return;
    }

    vector<vector<ll>> cantalk(n);
    for(ll i = 1; i<=m; i++){
        for(ll j = 0; j<lan[i].size(); j++){
            for(ll k = j+1; k<lan[i].size(); k++){
                cantalk[lan[i][j]].push_back(lan[i][k]);
                cantalk[lan[i][k]].push_back(lan[i][j]);
            }
        }
    }


    vector<ll> vis(n,0);

    ll ans = 0;

    for(ll i = 0; i<n; i++){
        if(vis[i] == 0){
            ans++;

            dfs(vis,cantalk,i);
        }
    }

    cout<<ans-1<<endl;

}