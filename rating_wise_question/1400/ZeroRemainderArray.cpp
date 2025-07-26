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

    vector<ll> rem(n,0);

    for(ll i = 0; i<n; i++){
        if(arr[i] % k != 0){
            rem[i] = k - (arr[i]%k);
        }
    }

    map<ll,ll> mp;

    for(ll i = 0; i<n; i++){
        mp[rem[i]]++;
    }

    vector<pair<ll,ll>> sol;

    for(auto i : mp){
        if(i.first != 0){
            sol.push_back({i.second,i.first});
        }
    }

    ll si = sol.size();

    ll ans = 0;

    sort(sol.begin(),sol.end());

    if(si > 0){
        ans = ((sol.back().first-1)*k) + sol.back().second + 1;
    }

    cout<<ans<<endl;


}