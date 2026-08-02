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

ll binExpRecur(ll arr, ll b) {
    if (b == 0) return 1;
    ll res = binExpRecur(arr, b / 2);
    if (b & 1) {
        return (arr * ((res * res) % MOD)) % MOD;
    } else {
        return (res * res) % MOD;
    }
}

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}

void solve() {
    //Rajvardhan Patil

    ll n;
    cin >> n;

    vector<ll> arr(n);
    inputV(arr, n);

    vector<ll> minir(n + 1);
    minir[n - 1] = arr[n - 1];
    for (ll i = n - 2; i >= 0; i--) {
        minir[i] = min(arr[i], minir[i + 1]);
    }

    ll count = 0;
    for (ll i = 0; i < n; i++) {
        count += (arr[i] - minir[i]);
    }

    vector<ll> prev(n, -1);
    stack<ll> s;

    for (ll i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (!s.empty()) prev[i] = s.top();
        s.push(i);
    }

    ll extra = 0;

    for (ll k = 0; k < n; k++) {
        ll check;
        if (k + 1 < n) {
            check = minir[k + 1];
        } else {
            check = 1e18; 
        }

        if (arr[k] < check) {
            ll addi = k - prev[k] - 1;
            extra = max(extra, addi);
        }
    }

    cout << count + extra << endl;


}