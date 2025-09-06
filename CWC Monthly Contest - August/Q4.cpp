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

bool check(const vector<ll>& a, const vector<ll>& b) {
    ll i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] >= b[j]) {
            j++;
        }
        i++;
    }
    return j == b.size();
}

bool check2(const vector<ll>& a, const vector<ll>& b, ll k) {
    ll n = a.size(), m = b.size();
    for (ll ip = 0; ip <= n; ip++) {
        ll i = 0, j = 0;
        bool used = false;

        while (j < m) {
            if (i == ip && !used) {
               
                if (k >= b[j]) {
                    j++;
                }
                used = true;
                continue;
            }

            if (i >= n) break;

            if (a[i] >= b[j]) {
                i++; j++;
            } else {
                i++;
            }
        }

        // cout<<used<<endl;


        if (j == m) return true;
    }
    return false;
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
    int n, m;
    cin>> n >> m;
    vector<ll> a(n), b(m);
    inputV(a, n);
    inputV(b, m);

   
    if (check(a, b)) {
        cout << 0 <<endl;
        return;
    }

    ll low = 1, high = 1e9;
    ll ans = -1;

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (check2(a, b, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }

        // cout<<low<<endl;
        // cout<<high<<endl;
    }

    cout <<ans<< endl;
}