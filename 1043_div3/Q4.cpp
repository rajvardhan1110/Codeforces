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
    //Rajvardhan Patil

    ll n, k;
    cin >> n >> k;

   
    vector<ll> cnt;
    {
        ll tmp = n;
        while (tmp > 0) {
            cnt.push_back(tmp % 3);
            tmp /= 3;
        }
        if (cnt.empty()) cnt.push_back(0);
    }

   
    ll m = 0;
    for (ll d : cnt) m += d;

    if (m > k) { 
        cout << -1 << endl;
        return;
    }

    
    ll D = min(k, n);
    if ((D % 2) != (m % 2)) --D;
    if (D < m) { 
        cout << -1 << endl;
        return;
    }

    ll s = (D - m) / 2; 

    vector<ll> pow3(40, 1);
    for (ll i = 1; i < 40; i++) pow3[i] = pow3[i - 1] * 3;

    
    ll ic = 3LL * n;
    for (ll i = 1; i < cnt.size(); ++i) {
        if (cnt[i] == 0) continue;
        ic += cnt[i] * ((ll)i * pow3[i - 1]);
    }

    if (s == 0) {
        cout << ic << endl;
        return;
    }

   
    ll maxp = (ll)cnt.size();
    vector<ll> avail(maxp, 0);
    for (ll i = 1; i < maxp; ++i) {
        if (cnt[i] == 0) continue;
        for (ll j = 0; j <= i - 1; ++j) {
            
            avail[j] += cnt[i] * pow3[i - 1 - j];
        }
    }

   
    ll minu = 0;
    for (ll j = maxp - 1; j >= 0 && s > 0; --j) {
        if (avail[j] == 0) continue;
        ll take = min(avail[j], s);
        minu += take * pow3[j]; 
        s -= take;
    }

    ll ans = ic - minu;
    cout << ans << endl;
}

