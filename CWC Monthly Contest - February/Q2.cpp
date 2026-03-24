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

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

void solve() {

    ll n;
    cin >> n;

    vector<ll> arr(n);
    inputV(arr, n);

    ll ans = LLONG_MAX;

    ll s = accumulate(arr.begin(), arr.end(), 0LL);

    for (int start = 0; start < n; start++) {

        vector<ll> temp;
        for (int j = 0; j < n; j++) {
            temp.push_back(arr[(start + j) % n]);
        }

        ll cs = 0;
        for (int len = 0; len < n; len++) {
            cs += temp[len];
            ans = min(ans, llabs(2 * cs - s));
        }
    }

    cout << ans << endl;
}
