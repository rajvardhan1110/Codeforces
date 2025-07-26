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

    map<pair<ll,ll>,pair<ll,map<ll,ll>>> First;
    map<pair<ll,ll>,pair<ll,map<ll,ll>>> Side;
    map<pair<ll,ll>,pair<ll,map<ll,ll>>> End;

    for(ll i =0; i<n-2; i++){

        First[{arr[i],arr[i+1]}].first += 1;
        First[{arr[i],arr[i+1]}].second[arr[i+2]] += 1;

        Side[{arr[i],arr[i+2]}].first += 1;
        Side[{arr[i],arr[i+2]}].second[arr[i+1]] += 1;

        End[{arr[i+1],arr[i+2]}].first += 1;
        End[{arr[i+1],arr[i+2]}].second[arr[i]] += 1;

    }

    ll ans = 0;

    for(auto i : First){

        ll total = i.second.first;
        for(auto j : i.second.second){

            total -= j.second;
            ll multi = j.second;

            ans += total*multi;

        }
    }

    for(auto i : Side){

        ll total = i.second.first;
        for(auto j : i.second.second){

            total -= j.second;
            ll multi = j.second;

            ans += total*multi;

        }
    }

    for(auto i : End){

        ll total = i.second.first;
        for(auto j : i.second.second){

            total -= j.second;
            ll multi = j.second;

            ans += total*multi;

        }
    }

    cout<<ans<<endl;

    
}