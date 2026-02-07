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
    // Rajvardhan Patil

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--; 
    }

   
    bool sorted = true;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] >= a[i]) {
            sorted = false;
            break;
        }
    }

    if (sorted) {
        cout << 0 << endl;
        return;
    }

    int stage = 0;   
    int answer = 1; 

    for (int i = 0; i < n; i++) {
        if (a[i] == i) {
            if (stage == 1) {
                stage = 2; 
            }
        } else {
            if (stage == 0) {
                stage = 1; 
            } else if (stage == 2) {
                answer = 2; 
                break;
            }
        }
    }

    cout << answer << endl;
}
