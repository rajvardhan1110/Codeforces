#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MOD = 1000000007;

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

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> freq(10, 0);
    for (char c : s) freq[c - '0']++;

    int best1 = 0;
    for (int x : freq) best1 = max(best1, x);

    int best2 = 0;
    for (char A = '0'; A <= '9'; A++) {
        for (char B = '0'; B <= '9'; B++) {
            if (A == B) continue;

            int len = 0;
            char expected = A;

            for (char c : s) {
                if (c == expected) {
                    len++;
                    expected = (expected == A ? B : A);
                }
            }

            if (len % 2 == 1) len--;
            best2 = max(best2, len);
        }
    }

    int ans = n - max(best1, best2);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
