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

ll binarySearch(ll num,vector<ll>& maxi){
    ll ans = -1;
    ll i=0;
    ll j=maxi.size() - 1;


    while(i <= j){
        ll mid = (i+j) / 2;

        if(maxi[mid] <= num){
            ans = mid;
            i = mid + 1;
        }else{
            j = mid - 1;
        }
    }

    return ans;
    
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

    ll n,m;
    cin>>n>>m;

    vector<ll> a(n);
    vector<ll> b(m);

    inputV(a,n);
    inputV(b,m);


    vector<ll> prevsum(n);
    prevsum[0] = a[0];

    for(ll i=1; i<n; i++){
        prevsum[i] += prevsum[i-1] + a[i]; 
    }

    vector<ll> maxi(n);
    maxi[0] = a[0];

    for(ll i=1; i<n; i++){
        // prevsum[i] += prevsum[i-1] + a[i]; 
        maxi[i] = max(maxi[i-1],a[i]);
    }

    vector<ll> ans(m);

    for(ll i=0; i<m; i++){
        ll index = binarySearch(b[i],maxi);
        
        if(index == -1){
            ans[i] = 0;
        }else{
            ans[i] = prevsum[index];
        }
    }

    printV(ans);
}