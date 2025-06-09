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

    if(n==1){
        cout<<1<<endl;
        return;
    }

    if(n==2){
        if(arr[0] == arr[1]){
            cout<<1<<endl;
            return;
        }else{
            cout<<2<<endl;
            return;
        }
    }

    vector<ll> v;

    ll prev = arr[0];
    v.push_back(arr[0]);

    for(ll i=1; i<n; i++){
        if(arr[i] != prev){
            v.push_back(arr[i]);
            prev=arr[i];
        }
    }

    ll ans = v.size();
    ll ni = ans;


    for(ll i=1; i<ni-1; i++){
        if(v[i] > v[i-1] && v[i] < v[i+1]){
            ans--;
        }else if(v[i] < v[i-1] && v[i] > v[i+1]){
            ans--;
        }
    }

    cout<<ans<<endl;
}