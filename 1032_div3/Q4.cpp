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

void solve() {
    // Rajvardhan Patil
    ll n;
    cin >> n;
    vector<ll> a, b;
    inputV(a, n);
    inputV(b, n);

    vector<pair<ll, ll>> ops;

    
    for (ll i = 0; i < n - 1; ++i) {
        bool check = false;
        for (ll j = 0; j < n - 1 - i; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                ops.push_back({1, j + 1});
                check = true;
            }
        }
        if (!check) break;
    }

    
    for (ll i = 0; i < n - 1; ++i) {
        bool check = false;
        for (ll j = 0; j < n - 1 - i; ++j) {
            if (b[j] > b[j + 1]) {
                swap(b[j], b[j + 1]);
                ops.push_back({2, j + 1});
                check = true;
            }
        }
        if (!check) break;
    }

    
    for (ll i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
            swap(a[i], b[i]);
            ops.push_back({3, i + 1});
        }
    }

    
    cout << ops.size() << endl;
    for (auto &[type, idx] : ops) {
        cout << type << " " << idx << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}
