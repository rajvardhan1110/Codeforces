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

    vector<ll> a(n);
    vector<ll> b(n);
    inputV(a,n);
    inputV(b,n);

    vector<pair<ll,ll>> c(n);

    for(ll i =0; i<n; i++){
        c[i] = {a[i]-b[i],i+1};
    }

    vector<ll> ans;

    sort(c.begin(),c.end(),[](pair<ll,ll>&a,pair<ll,ll> &b){
        if(a.first == b.first){
            return a.second < b.second;
        }

        return a.first > b.first;
    });

    ans.push_back(c[0].second);

    for(ll i = 1; i<n; i++){
        if(c[i].first == c[0].first){
            ans.push_back(c[i].second);
        }else{
            break;
        }
    }

    cout<<ans.size()<<endl;

    for(auto i:ans){
        cout<<i<<" ";
    }

    cout<<endl;


}