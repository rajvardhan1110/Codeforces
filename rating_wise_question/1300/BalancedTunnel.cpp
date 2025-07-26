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

bool hasCommon(const set<ll>& a, const set<ll>& b) {
    for (int x : a) {
        if (b.count(x)) return true;  
    }
    return false;
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

    ll n;
    cin>>n;

    vector<ll> a(n);
    vector<ll> b(n);

    inputV(a,n);
    inputV(b,n);

    // map<ll,set<ll>> mp1;
    // map<ll,set<ll>> mp2;

    // set<ll> dummy;

    // for(ll i = 0; i<n; i++){
    //     mp1[a[i]] = dummy;
    //     dummy.insert(a[i]);

    // }

    // set<ll> dummy2;

    // for(ll i = n-1; i>=0; i--){
    //     mp2[b[i]] = dummy2;
    //     dummy2.insert(b[i]);
    // }

    // ll ans = 0;

    // for(ll i = 0; i<n; i++){
    //     if(hasCommon(mp1[a[i]],mp2[a[i]])){
    //         ans++;
    //     }
    // }

    // cout<<ans<<endl;

    map<ll,ll> mp;

    for(ll i = 0; i<n; i++){
        mp[b[i]] = i+1;
    }

    ll ans = 0;
    ll maxi = -1;

    vector<ll> c;

    for(ll i =0; i<n; i++){
        c.push_back(mp[a[i]]);
    }

    for(auto i : c){
        if(i > maxi){
            maxi = i;
        }else{
            ans++;
        }
    }

    cout<<ans<<endl;

}