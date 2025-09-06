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

    vector<ll> ans(n);

    map<ll,ll> mp;

    // ans[0] = arr[0];
    // mp[arr[0]] = 1;
    // maxi = 1;

    vector<ll> x(n+1);

    // for(ll i = 1; i<n; i++){
    //     if(mp[arr[i]] < maxi){
    //         ll cnt = 1;

    //     }else{
    //         extra.push_back(i);
    //     }
    // }



    for(ll i = 0; i<n; i++){
        if(!x[arr[i]]){
            ans[i] = arr[i];
            x[arr[i]] = 1;
        }
    }

   


    // for(auto i:s){
    //     cout<<i<<" ";
    // }

    vector<ll> notuse;

    for(ll i = 1; i<x.size(); i++){
        if(!x[i]){
            notuse.push_back(i);
        }
    }

    ll ind = 0;

    for(ll i = 0; i<n; i++){
        if(ans[i] == 0){
            ans[i] = notuse[ind];
            ind++;
        }
    }

    printV(ans);

}