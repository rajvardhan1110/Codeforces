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

void dfs(int i,int j,vector<vector<ll>>& arr,vector<vector<bool>> &vis,ll &sum){
    if(i < 0 || i >= arr.size() || j < 0 || j >= arr[0].size() || vis[i][j] || arr[i][j] == 0){
        return;
    }

    vis[i][j] = true;
    sum += arr[i][j];

    dfs(i,j-1,arr,vis,sum);
    dfs(i+1,j,arr,vis,sum);
    dfs(i-1,j,arr,vis,sum);
    dfs(i,j+1,arr,vis,sum);


}

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

    ll n,m;
    cin>>n>>m;

    vector<vector<ll>> arr(n,vector<ll> (m));

    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    vector<vector<bool>> vis(n,vector<bool> (m,false));

    ll ans = 0;

    for(ll i = 0; i<n; i++){
        
        for(ll j = 0; j<m; j++){
            if(arr[i][j] && !vis[i][j]){
                ll sum = 0;
                dfs(i,j,arr,vis,sum);
                ans = max(ans,sum);
            }
        }

        
    }

    cout<<ans<<endl;

}