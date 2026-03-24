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
    string s;
    cin >> s;

    ll x, y, z;
    cin >> x >> y >> z;

    ll aa, bb, cc;
    cin >> aa >> bb >> cc;

    ll m;
    cin >> m;

    ll a = 0, b = 0, c = 0;

    for (auto i : s) {
        if (i == 'B') a++;
        else if (i == 'S') b++;
        else c++;
    }

    ll ans = 0;

    while (true) {
        if (x >= a && y >= b && z >= c) {
            x -= a;
            y -= b;
            z -= c;
            ans++;
        } else {
            break;
        }
    }

    if (x == 0 && y == 0 && z == 0) {
        ll cost_per_burger = a * aa + b * bb + c * cc;
        ans += m / cost_per_burger;
        cout << ans << endl;
        return;
    }

    while (true) {
        ll needB = max(0LL, a - x);
        ll needS = max(0LL, b - y);
        ll needC = max(0LL, c - z);

        ll cost = needB * aa + needS * bb + needC * cc;

        if (cost <= m) {
            m -= cost;
            ans++;

            x = max(0LL, x - a);
            y = max(0LL, y - b);
            z = max(0LL, z - c);
        } else {
            break;
        }
    }

    cout << ans << endl;
}