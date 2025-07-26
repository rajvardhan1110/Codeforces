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

    bool inc = false;
    bool dec = false;
    vector<ll> ans;
    ans.push_back(arr[0]);

    if(arr[0] < arr[1]){
        inc = true;
    }else{
        dec = true;
    }

    ll num = arr[1];

    for(ll i = 2; i<n; i++){
        if(inc){
            if(num > arr[i]){
                ans.push_back(num);
                num = arr[i];
                inc = false;
                dec= true;
            }else{
                num = arr[i];
            }
        }else{
            if(num < arr[i]){
                ans.push_back(num);
                num = arr[i];
                inc = true;
                dec = false;
            }else{
                num = arr[i];
            }
        }
    }

    ans.push_back(num);

    cout<<ans.size()<<endl;
    printV(ans);
}