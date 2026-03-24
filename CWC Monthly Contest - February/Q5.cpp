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

void prllV(const vector<ll> &v) {
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

bool check(ll x) {
    ll sq = sqrt(x);
    return sq * sq == x;
}

void solve2(vector<ll> &arr, ll rem, ll n, ll &ans) {
    for (auto val : arr){
        ans = max(ans, val);
    } 

    if (rem == 0) return;  

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (i == j) continue;

            ll xorVal = arr[i] ^ arr[j];
            if (check(xorVal)) {
                arr[i] += arr[j];            
                solve2(arr, rem - 1, n, ans); 
                arr[i] -= arr[j];            
            }
        }
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

    ll n, k;
    cin >> n >> k;

    vector<ll> arr(n);
    inputV(arr,n);

    ll ans = 0; 

    solve2(arr, k, n, ans);

    cout << ans << endl;
}