#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MOD = 1000000007; // 1e9 + 7


ll recur(ll i, ll prevind, ll prevGCD, const vector<ll> &A, vector<vector<map<ll,ll>>> &dp) {
    if (i == (ll)A.size()) {
        return 0;
    }

    if (prevind != -1 && dp[i][prevind].count(prevGCD)) {
        return dp[i][prevind][prevGCD];
    }

    //skip kela
    ll ans = recur(i + 1, prevind, prevGCD, A, dp);

    //curr ghetala
    if (prevind == -1) {
        
        ans = max(ans, 1 + recur(i + 1, i, 0, A, dp));
    } else {
        ll newG = __gcd(A[prevind], A[i]);
        if (newG >= prevGCD) {
            ans = max(ans, 1 + recur(i + 1, i, newG, A, dp));
        }
    }

    if (prevind != -1) {
        dp[i][prevind][prevGCD] = ans;
    }
    return ans;
}


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
    cin >> n;
    vector<ll> arr(n);
    inputV(arr,n);

    vector<vector<map<ll,ll>>> dp(n, vector<map<ll,ll>>(n));

    ll ans = recur(0, -1, 0, arr, dp);


    cout<<ans<<endl;
}