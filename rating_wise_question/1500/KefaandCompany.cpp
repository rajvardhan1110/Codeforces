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

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}

void solve() {
    //Rajvardhan Patil

    ll n,d;
    cin>>n>>d;

    vector<pair<ll,ll>> arr(n);

    for(ll i =0; i<n; i++){
        cin>>arr[i].first>>arr[i].second;
    }

    vector<ll> a;

    for(auto i : arr){
        a.push_back(i.first);
    }

    sort(arr.begin(),arr.end());
    sort(a.begin(),a.end());

    vector<ll> pre(n,0);
    pre[0] = arr[0].second;

    for(ll i = 1; i<n; i++){
        pre[i] += arr[i].second + pre[i-1];
    }


    ll ans = 0;

    for(ll i = n-1; i>=0; i--){
        ll ch = a[i] - d;

        auto x = upper_bound(a.begin(),a.end(),ch);

        ll ind = x - a.begin();

        ll curr = pre[i] - pre[ind] + arr[ind].second;

        ans = max(ans,curr);
    }


    cout<<ans<<endl;



}