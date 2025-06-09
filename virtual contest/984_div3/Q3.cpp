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
    string s;
    cin >> s;
    ll q;
    cin >> q;
    ll n = s.size();
    set<ll> se;

    
    for (ll i = 0; i <= n - 4; i++) {
        if (s[i] == '1' && s[i+1] == '1' && s[i+2] == '0' && s[i+3] == '0') {
            se.insert(i);
        }
    }

    while (q--) {
        ll index, replace;
        cin >> index >> replace;
        ll ind = index - 1;

        if (s[ind] == (replace + '0')) {
            cout << (se.empty() ? "NO" : "YES") << endl;
            continue;
        }

        
        if (ind - 3 >= 0 && ind + 0 < n) {
            if (s[ind-3] == '1' && s[ind-2] == '1' && s[ind-1] == '0' && s[ind] == '0') {
                se.erase(ind-3);
            }
        }
        if (ind - 2 >= 0 && ind + 1 < n) {
            if (s[ind-2] == '1' && s[ind-1] == '1' && s[ind] == '0' && s[ind+1] == '0') {
                se.erase(ind-2);
            }
        }
        if (ind - 1 >= 0 && ind + 2 < n) {
            if (s[ind-1] == '1' && s[ind] == '1' && s[ind+1] == '0' && s[ind+2] == '0') {
                se.erase(ind-1);
            }
        }
        if (ind + 3 < n) {
            if (s[ind] == '1' && s[ind+1] == '1' && s[ind+2] == '0' && s[ind+3] == '0') {
                se.erase(ind);
            }
        }

        
        s[ind] = replace + '0';

        
        if (ind - 3 >= 0 && ind + 0 < n) {
            if (s[ind-3] == '1' && s[ind-2] == '1' && s[ind-1] == '0' && s[ind] == '0') {
                se.insert(ind-3);
            }
        }
        if (ind - 2 >= 0 && ind + 1 < n) {
            if (s[ind-2] == '1' && s[ind-1] == '1' && s[ind] == '0' && s[ind+1] == '0') {
                se.insert(ind-2);
            }
        }
        if (ind - 1 >= 0 && ind + 2 < n) {
            if (s[ind-1] == '1' && s[ind] == '1' && s[ind+1] == '0' && s[ind+2] == '0') {
                se.insert(ind-1);
            }
        }
        if (ind + 3 < n) {
            if (s[ind] == '1' && s[ind+1] == '1' && s[ind+2] == '0' && s[ind+3] == '0') {
                se.insert(ind);
            }
        }

        cout << (se.empty() ? "NO" : "YES") << endl;
    }
}