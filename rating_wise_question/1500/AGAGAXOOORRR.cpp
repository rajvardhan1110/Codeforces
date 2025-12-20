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
    cin>>n;

    vector<ll> arr(n);
    inputV(arr,n);

    vector<ll> left(n);
    vector<ll> right(n);

    left[0] = arr[0];
    right[n-1] = arr[n-1];

    // for(ll i = 1; i<n; i++){
    //     left[i] = (arr[i] ^ left[i-1]);
    // }

    // for(ll i = n-2; i>=0; i--){
    //     right[i] = (arr[i] ^ right[i+1]);
    // }

    // for(ll i = 0; i<n-1; i++){
    //     if(left[i] == right[i+1]){
    //         cout<<"YES"<<endl;
    //         return;
    //     }
    // }

    ll x = 0;

    for(auto i : arr){
        x = (x ^ i);
    }

    if(x == 0){
        cout<<"YES"<<endl;
        return;
    }

    ll k = 0;
    ll cnt = 0;

    for(ll i =0; i<n; i++){
        k ^= arr[i];

        if(k == x){
            k = 0;
            cnt++;
        }
    }

    if(cnt >= 2){
        cout<<"YES"<<endl;
        return;
    }

    cout<<"NO"<<endl;
}