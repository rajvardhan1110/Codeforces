#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll MAXN = 40000;

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

bool PowOfTwo(ll n) {
    return n > 0 && (n & (n - 1)) == 0;
}

ll binExpRecur(ll a, ll b) {
    if (b == 0) return 1;
    ll res = binExpRecur(a, b / 2);
    if (b & 1) return (a * ((res * res) % MOD)) % MOD;
    return (res * res) % MOD;
}


vector<ll> pal;
vector<ll> dp(MAXN + 1, 0);

bool isPalindrome(ll x) {
    ll rev = 0, orig = x;
    while (x > 0) {
        rev = rev * 10 + (x % 10);
        x /= 10;
    }
    return rev == orig;
}

void precompute() {
    for (ll i = 1; i <= MAXN; i++) {
        if (isPalindrome(i)) {
            pal.push_back(i);
        }
    }

    dp[0] = 1;
    for (ll p : pal) {
        for (ll s = p; s <= MAXN; s++) {
            dp[s] = (dp[s] + dp[s - p]) % MOD;
        }
    }
}


void solve() {
    // Rajvardhan Patil
    ll n;
    cin >> n;
    cout << dp[n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();  

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
