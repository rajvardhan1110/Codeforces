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
    ll n;
    ll k;
    cin >> n >> k;

    vector<ll> a(n);
    inputV(a,n);

    sort(a.begin(), a.end());

    vector<ll> l;   
    vector<ll> sl;  

    while (k > 0 && l != a) {
        k--;

        sl = l;
        l = a;

        
        vector<ll> F(n + 1, 0);
        for (ll x : a) {
            if (x <= n) F[x]++;
        }

        
        ll mex = 0;
        while (mex <= n && F[mex] > 0) mex++;

        vector<ll> B;
        ll mm = 0;

        for (ll x : a) {
            if (F[x] > 1) {
                B.push_back(mex);
            } else {
                B.push_back(mm);
            }
            if (x == mm) mm++;
        }

        sort(B.begin(), B.end());
        a = B;

        
        if (a == sl) {
            k &= 1;
        }
    }

    ll ans = 0;
    for (ll x : a) ans += x;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
