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
    // inputV(arr,n);

    vector<pair<ll,ll>> pa(n);

    for(ll i = 0; i<n; i++){
        cin>>arr[i];

        pa[i] = {arr[i],i};
    }

    sort(pa.begin(),pa.end());

    vector<ll> addi(n);
    addi[0] = pa[0].first;

    for(ll i = 1; i<n; i++){
        addi[i] = pa[i].first + addi[i-1];
    }

    vector<ll> ans(n);

    for(ll i=0; i<n; i++){
        ll found = i;
        ll j = i;

        while(j < n){
            pair<ll,ll> temp = {addi[j]+1,INT_MIN};
            ll ind = lower_bound(pa.begin(),pa.end(),temp) - pa.begin();
            ind--;

            if(ind == j){
                break;

            }


            found += ind - j;
            j = ind;
        }

        ans[pa[i].second] = found;
    }

    printV(ans);
}