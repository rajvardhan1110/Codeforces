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

    ll mini = *min_element(arr.begin(),arr.end());

    ll check = mini;

    ll cnt = 0;

    for(ll i =0; i<n; i++){
        if(arr[i] == mini){
            cnt++;
        }else{
            check &= arr[i];
        }
    }

    if(check != mini){
        cout<<0<<endl;
        return;
    }

    ll ans = 0;

    ll f = 1;

    for(ll i =1; i<=n-2; i++){
        f = (f*i) %MOD;
    }

    ll mincnt = (cnt*(cnt-1)) % MOD;

    ans = (((1LL * f)%MOD) * mincnt) % MOD;

    cout<<ans<<endl;


}