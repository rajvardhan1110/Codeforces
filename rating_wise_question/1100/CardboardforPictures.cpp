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

// ll calculateArea(ll x, ll a, ll b, ll s2sum) {
//     // A·x² + B·x + sum(s²)
//     if (x > 1e9) return 1e18; // avoid overflow
//     return a * x * x + b * x + s2sum;
// }

ll binarySearchRoot(ll a, ll b, ll s2sum, ll c) {
    ll low = 0, high = 1e9, ans = -1;
    while (low <= high) {
        ll mid = (low + high) / 2;
        __int128 area = (__int128)a * mid * mid + (__int128)b * mid + (__int128)s2sum;

        if (area == (__int128)c) {
            return mid;
        }

        if (area > (__int128)c) {
            ans = mid;
            high = mid - 1;  // try smaller x
        } else {
            low = mid + 1;
        }
    }
    return ans;
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

    ll n,k;
    cin>>n>>k;

    vector<ll> arr(n);
    inputV(arr,n);

    ll a = 0;
    ll b = 0;
    ll ci = 0;

    for(auto i:arr){
        ci += i*i;
        b += i*2*2;
        a += 4;

    }

    // ll c = ci - k;

    cout<<binarySearchRoot(a,b,ci,k)<<endl;




}