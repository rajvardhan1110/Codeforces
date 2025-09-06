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


ll sum(ll n) {
    if (n < 10) return n * (n + 1) / 2;
    
    int len = 0;
    ll temp = n;
    while (temp > 0) {
        temp /= 10;
        len++;
    }

    ll p10 = 1;
    for (int i = 1; i < len; i++) p10 *= 10;

    int first = n / p10;
    ll rest = n % p10;

    ll res = (ll)first * (first - 1) / 2 * p10;
    res += (ll)first * sum(p10 - 1);
    res += (ll)first * (rest + 1);
    res += sum(rest);
    return res;
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

    ll k;
    cin>>k;

    ll len = 1;
    ll start = 1;
    ll ans = 0;

    while (true) {
        ll end = start * 10 - 1;
        ll tnum = end - start + 1;
        ll t_digitwise = tnum * len;

        if(k >= t_digitwise) {
            ans += sum(end) - sum(start - 1);
            k -= t_digitwise;
            start *= 10;
            len++;
        }else {
            ll alll = k / len;
            ll extra = k % len;

            if (alll > 0) {
                ans += sum(start + alll - 1) - sum(start - 1);

                start += alll;
            }

            if (extra > 0) {
                string s = to_string(start);
                for (int i = 0; i < extra; i++) {
                    ans += s[i] - '0';
                }
            }
            break;
        }
    }

    cout << ans << endl;
}


