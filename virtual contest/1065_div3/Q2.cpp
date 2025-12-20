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

    for(ll i = 1; i<n-1; i++){
        if(arr[i] == -1){
            arr[i] = 0;
        }
    }

    if(arr[0] != -1 && arr[n-1] != -1){
        cout<<abs(arr[n-1]-arr[0])<<endl;
        printV(arr);
    }else if(arr[0] == -1 && arr[n-1] == -1){
        arr[0] = 0;
        arr[n-1] = 0;
        cout<<abs(arr[n-1]-arr[0])<<endl;
        printV(arr);
    }else if(arr[0] == -1){
        arr[0] = arr[n-1];
        cout<<abs(arr[n-1]-arr[0])<<endl;
        printV(arr);
    }else{
        arr[n-1] = arr[0];
        cout<<abs(arr[n-1]-arr[0])<<endl;
        printV(arr);
    }
}