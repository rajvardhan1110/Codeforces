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
    // Rajvardhan Patil

    ll n;
    cin >> n;

    vector<ll> a(n + 1), b(n + 1);

    for (ll i = 1; i <= n; i++) cin >> a[i];  
    for (ll i = 1; i <= n; i++) cin >> b[i]; 


    vector<ll> prefB(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        prefB[i] = prefB[i - 1] + b[i];
    }

    vector<ll> diff(n + 2, 0);

    vector<ll> partial(n + 2, 0);

    for (ll i = 1; i <= n; i++) {
        ll low = i, high = n;
        ll k = i - 1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll required = prefB[mid] - prefB[i - 1];

            if (required <= a[i]) {
                k = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (k >= i) {
            diff[i]++;
            diff[k + 1]--;
        }

        ll used = prefB[k] - prefB[i - 1];
        ll remain = a[i] - used;

        if (k + 1 <= n) {
            partial[k + 1] += remain;
        }
    }

    vector<ll> ans(n + 1, 0);
    ll active = 0;

    for (ll i = 1; i <= n; i++) {
        active += diff[i];
        ans[i] = active * b[i] + partial[i];
    }

    for (ll i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}