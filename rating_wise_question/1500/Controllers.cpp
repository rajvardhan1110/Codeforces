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
    //Rajvardhan Patil

    ll n;
    cin >> n;

    string s;
    cin >> s;

    ll q;
    cin >> q;

    ll pos = 0, neg = 0;
    for (char c : s) {
        if (c == '+') pos++;
        else neg++;
    }

    while (q--) {
        ll a, b;
        cin >> a >> b;

        if (a == b) {
            if (pos == neg) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }

        ll need = (neg - pos) * b;
        ll divi = a - b;

        if (need % divi != 0) {
            cout << "NO\n";
            continue;
        }

        ll k = need / divi; 

        ll L = max(0LL, k);
        ll R = min(pos, neg + k);

        if (L <= R) cout << "YES\n";
        else cout << "NO\n";
    }
}
