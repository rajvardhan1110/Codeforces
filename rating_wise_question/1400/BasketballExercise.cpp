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

ll solve2(vector<ll>& a,vector<ll>& b,ll ind,ll prev,vector<vector<ll>>& dp){
    if(ind == a.size()){
        return 0;
    }

    if(dp[ind][prev+1] != -1){
        return dp[ind][prev+1];
    }

    if(prev == -1){
        ll skip = solve2(a,b,ind+1,prev,dp);
        ll F = a[ind] + solve2(a,b,ind+1,0,dp);
        ll S = b[ind] + solve2(a,b,ind+1,1,dp);

        dp[ind][prev+1] = max({skip,F,S});
    }else{
        ll skip = solve2(a,b,ind+1,prev,dp);

        ll take = 0;

        if(prev == 0){
            take = b[ind] + solve2(a,b,ind+1,1,dp);
        }else{
            take = a[ind] + solve2(a,b,ind+1,0,dp); 
        }

        dp[ind][prev+1] = max(skip,take);
    }

    return dp[ind][prev+1];
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

    ll n;
    cin>>n;

    vector<ll> a(n);
    vector<ll> b(n);

    inputV(a,n);
    inputV(b,n);

    vector<vector<ll>> dp(n,vector<ll> (3,-1));

    cout<<solve2(a,b,0,-1,dp)<<endl;
}