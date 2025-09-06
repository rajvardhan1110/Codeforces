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
    //Rajvardhan Patil
    ll n;
    ll k;
        cin >> n >> k;

    vector<ll> s(n), t(n);
       inputV(s,n);
       inputV(t,n);

        
        if (k == 0) {
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            if (s == t)
                cout << "YES"<<endl;
            else
                cout << "NO"<<endl;
            return;
        }

        map<ll ,ll> d;
       
        for (auto  x : s) {
            ll  rem = x % k;
            ll  tmin = min(rem, k - rem);
            d[tmin]++;
        }

       
        for (auto  x : t) {
            ll  rem = x % k;
            ll  tmin = min(rem, k - rem);
            d[tmin]--;
        }

        
        for (auto p : d) {
            if (p.second != 0) {
               cout<<"NO"<<endl;
               return;
            }
        }
    cout<<"YES"<<endl;
    }
