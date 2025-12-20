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
    // Rajvardhan Patil

    int n, m;
    cin >> n >> m;

    vector<ll> city(n), tower(m);
    inputV(city, n);
    inputV(tower, m);

    ll ans = 0;

    for (ll c : city) {

        
        auto it = lower_bound(tower.begin(), tower.end(), c);

        ll d = LLONG_MAX;

        
        if (it != tower.end()) {
            d = min(d, llabs(*it - c));
        }

       
        if (it != tower.begin()) {
            it--;
            d = min(d, llabs(*it - c));
        }

        ans = max(ans, d);
    }

    cout << ans << endl;
}