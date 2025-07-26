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

bool check(ll mid, vector<pair<ll,ll>>& arr){
    ll l = 0;
    ll r = 0;

    for(ll i = 0; i<arr.size(); i++){
        l = l-mid;
        r = r+mid;

        ll st = max(l,arr[i].first);
        ll e = min(r,arr[i].second);

        if(st > e){
            return false;
        }else{
            l = max(arr[i].first,l);
            r = min(arr[i].second,r);
        }
    }

    return true;
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

    vector<pair<ll,ll>> arr(n);

    for(ll i = 0; i<n; i++){
        ll a;
        ll b;
        cin>>a>>b;

        arr.push_back({a,b});
    }

    ll l = 0;
    ll r = 10e9;
    ll ans = -1;

    while(l <= r){
        ll mid = (l+r) / 2;

        if(check(mid,arr)){
            ans = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }

    cout<<ans<<endl;
}