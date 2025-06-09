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

    vector<ll> arr(n);

    inputV(arr,n);

    vector<ll> pref;
    vector<ll> suf;

    // ll count = 0;

    for(ll i = 0; i<n; i++){
        if(arr[i] == 1){

            pref.push_back(i+1);

        }
    }

    for(int i=n-1; i>=0; i--){
        if(arr[i] == 1){
            suf.push_back(n-i);
        }
    }

    ll total = suf.size();

    // cout<<total<<endl;

    if(total < k){
        cout<<-1<<endl;
        return;
    }

    if(total == k){
        cout<<0<<endl;
        return;
    }

    ll req = total - k;


    ll ans = INT_MAX;

    ans = min(ans,pref[req-1]);
    ans = min(ans,suf[req-1]);

    for(int i=0; i<req-1; i++){
        ans = min(ans,suf[i]+pref[req-i-2]);
    }

    cout<<ans<<endl;


}