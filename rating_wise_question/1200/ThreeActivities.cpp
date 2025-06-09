#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MOD = 1000000007; // 1e9 + 7

void inputV(vector<ll> &v, ll size) {
    v.resize(size);
    for (ll i = 0; i < size; i++) {
        cin >> v[i];
    }
}

void prllV(const vector<ll> &v) {
    for (ll val : v) {
        cout << val << " ";
    }
    cout << endl;
}

void createsieve(vector<bool> &prime, ll n) {
    prime[0] = prime[1] = false;
    for (ll i = 2; i * i < n; i++) {
        if (prime[i]) {
            for (ll j = i * i; j < n; j += i) {
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

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
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
    vector<ll> c(n);

    inputV(a,n);
    inputV(b,n);
    inputV(c,n);

    vector<pair<ll,ll>> aa;
    vector<pair<ll,ll>> bb;
    vector<pair<ll,ll>> cc;

    for(ll i = 0; i<n; i++){
        aa.push_back({a[i],i});
        bb.push_back({b[i],i});
        cc.push_back({c[i],i});
    }

    sort(aa.rbegin(),aa.rend());
    sort(bb.rbegin(),bb.rend());
    sort(cc.rbegin(),cc.rend());


    ll ans = 0;

    for(ll i=0; i<3; i++){
        for(ll j=0; j<3; j++){
            for(ll k=0; k<3; k++){
                ll sum = 0;

                if((aa[i].second != bb[j].second) && (aa[i].second != cc[k].second) && (bb[j].second != cc[k].second)){
                    ll sum = aa[i].first + bb[j].first + cc[k].first;

                    ans = max(ans,sum);
                }
            }
        }
    }

    cout<<ans<<endl;
}