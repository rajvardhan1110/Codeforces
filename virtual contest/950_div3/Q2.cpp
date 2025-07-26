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

    ll n,f,k;

    cin>>n>>f>>k;

    vector<ll> arr(n);
    inputV(arr,n);

    f--;
    k--;

    ll fev = arr[f];

    sort(arr.rbegin(),arr.rend());
   


    bool falg = true;

    

    if(fev > arr[k]){
        cout<<"YES"<<endl;
        return;
    }else if(fev < arr[k]){
        cout<<"NO"<<endl;
        return;
    }else if(fev == arr[k]){
        if(k+1 < n){
            if(fev == arr[k+1]){
                cout<<"MAYBE"<<endl;
            }else{
                cout<<"YES"<<endl;
            }
        }else{
            cout<<"YES"<<endl;
        }
    }
}