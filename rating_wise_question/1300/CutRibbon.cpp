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

ll solve2(vector<ll>& coins,ll amount,vector<ll>& dp){
        if(amount == 0){
            return 0;
        }

        if(amount < 0){
            return INT_MIN;
        }

        if(dp[amount] != -1){
            return dp[amount];
        }

        ll mini = INT_MIN;

        for(ll i=0; i<coins.size(); i++){
            ll ans = solve2(coins,amount - coins[i],dp);

            if(ans != INT_MIN){
                mini = max(mini,ans+1);
            }
        }

        dp[amount] = mini;



        return mini;
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
    //Rajvardhan Patil

    ll n,a,b,c;
    cin>>n>>a>>b>>c;

    vector<ll> arr(3);
    arr[0]=a;
    arr[1]=b;
    arr[2]=c;

    vector<ll> dp(n+1,-1);

    ll bb = solve2(arr,n,dp);

    cout<<bb<<endl;


}