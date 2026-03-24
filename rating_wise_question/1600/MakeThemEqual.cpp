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

ll totalBits(ll n) {
    if (n == 0) return 1;
    return floor(log2(n)) + 1;
}

ll countSetBits(ll n) {
    int count = 0;
    while (n) {
        n = n & (n - 1);
        count++;
    }
    return count;
}

// ll solve2(vector<ll>& op,vector<ll>& coins,vector<vector<ll>>& dp,ll k, ll i){
//     if(i == op.size()){
//         return 0;
//     }

//     if(dp[i][k] != -1){
//         return dp[i][k];
//     }

//     ll take = 0;
//     ll nottake = 0;

//     if(op[i] <= k){
//         take = coins[i] + solve2(op,coins,dp,k-op[i],i+1);
//     }

//     nottake = solve2(op,coins,dp,k,i+1);

//     return dp[i][k] = max(take,nottake);
// }



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

    ll n,k;
    cin>>n>>k;

    vector<ll> arr(n);
    vector<ll> coins(n);

    inputV(arr,n);
    inputV(coins,n);

    vector<ll> op(n);

    ll MAXN = 1000;

    vector<ll> d(MAXN + 1, 1e9);

    queue<ll> q;

    d[1] = 0;
    q.push(1);

    while (!q.empty()) {
        ll a = q.front();
        q.pop();

        for (ll x = 1; x <= a; x++) {
            ll next = a + a / x;

            if (next <= MAXN && d[next] > d[a] + 1) {
                d[next] = d[a] + 1;
                q.push(next);
            }
        }
    }

    // printV(op);

    for(ll i = 0; i<n; i++){
        op[i] = d[arr[i]];
    }

    // vector<vector<ll>> dp(n,vector<ll> (k+1,-1));

    // ll ans = solve2(op,coins,dp,k,0);

    // cout<<ans<<endl;

    k = min(k, 12LL * n);

    vector<ll> dp(k + 1, 0);

    for (ll i = 0; i < n; i++) {
        for (ll j = k; j >= op[i]; j--) {
            dp[j] = max(dp[j], coins[i] + dp[j - op[i]]);
        }
    }

    cout << dp[k] << endl;
}