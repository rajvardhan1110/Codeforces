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

ll cal(vector<ll> &arr, ll l, ll r) {
    int n = arr.size();
    vector<bool> vis(n + 2, false);

    for (ll i = l; i <= r; i++) {
        if (arr[i] <= n) vis[arr[i]] = true;
    }

    for (ll i = 0; i <= n + 1; i++) {
        if (!vis[i]) return i;
    }

    return n + 1; 
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

    ll len;
    cin >> len;
    
    ll n = 2*len;

    vector<ll> arr(n);
    inputV(arr, n);

    ll f = -1, s = -1;

    for (ll i = 0; i < n; i++) {
        if (arr[i] == 0) {
            if (f == -1) f = i;
            else s = i;
        }
    }

    ll mex = 1;

   
        ll l = f, r = f;

        while (l - 1 >= 0 && r + 1 < n && arr[l - 1] == arr[r + 1]) {
            l--;
            r++;
        }

        mex = max(mex, cal(arr, l, r));
    

   
        l = s, r = s;

        while (l - 1 >= 0 && r + 1 < n && arr[l - 1] == arr[r + 1]) {
            l--;
            r++;
        }

        mex = max(mex, cal(arr, l, r));
    

   
         l = f, r = s;
        bool pali = true;

        while (l <= r) {
            if (arr[l] != arr[r]) {
                pali = false;
                break;
            }
            l++;
            r--;
        }

        if (pali) {
            l = f;
            r = s;

            while (l - 1 >= 0 && r + 1 < n && arr[l - 1] == arr[r + 1]) {
                l--;
                r++;
            }

            mex = max(mex, cal(arr, l, r));
        }
    

    cout << mex << endl;
}