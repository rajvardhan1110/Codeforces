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

void printV(const vector<ll> &v) {
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

int main() {
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

    ll n,k;
    cin>>n>>k;


    vector<ll> arr(n);
    inputV(arr,n);

    map<ll,ll> mp;  

    for (ll w : arr) {
        mp[w]++;
    }

    ll height = 0;

    while (n > 0) {
        ll remaining = k;
        for (auto i = mp.rbegin(); i != mp.rend(); ++i) {
            ll width = i->first;
            while (mp[width] > 0 && width <= remaining) {
                ll fit = min(mp[width], remaining / width);
                mp[width] -= fit;
                remaining -= fit * width;
                n -= fit;
            }
        }
        height++;
    }

    cout<<height<<endl;

    // multiset<ll> s;

    // for(auto i:arr){
    //     s.insert(i);
    // }

    // ll height = 1;
    // ll left = k;
    // while(!s.empty()){

    //     auto it = s.upper_bound(left);

    //     if(it == s.begin()){
    //         height++;
    //         left = k;
    //     }else{
    //         it--;
    //         ll box = *it;
    //         left -= box;
    //         s.erase(it);

    //     }

    // }

    // cout<<height<<endl;
}