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

    ll n,k;
    cin>>n>>k;

    vector<ll> v(n);
    inputV(v,n);

    ll sum = 0;

    // vector<ll> s(n,0);

    // for(ll i=n-1; i>=0; i--){
    //     if(arr[i]==1){
    //         sum += 1;
    //     }

    //     s[i] = sum;
    // }

    // for(ll i=0; i<n; i++){
    //     if(s[i] > k){
    //         cout<<"NO"<<endl;
    //         return;
    //     }
    // }

    // cout<<"YES"<<endl;


        int idx1 = -1;
    bool f = false;
    int idx2 = -1;

    for (int i = 0; i <n; i++) {
        if (!f && v[i] == 1) {
            idx1 = i;
            f = true;
        }
        else if (v[i] == 1) {
            idx2 = i;
        }
    }

    // cout << idx1 << " " << idx2 << endl;

    if (idx1 != -1 && idx2 != -1) {
        if (idx2 - idx1 >= k) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;


}