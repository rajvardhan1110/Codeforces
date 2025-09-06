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

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}

void solve() {
    //Rajvardhan Patil

    ll n;
    cin>>n;

    if(n == 1){
        cout<<"yes"<<endl;
        cout<<1<<" "<<1<<endl;
        return;
    }


    vector<ll> arr(n);
    inputV(arr,n);

    ll l = -1;
    ll r = -1;

    for(ll i =1; i<n; i++){
        if(arr[i] < arr[i-1]){
            if(l == -1){
                l = i-1;
                r = i;
            }else{
                r = i;
            }
        }else{
            if(l != -1){
                break;
            }
        }
    }

    // cout<<l<<" "<<r<<endl;

    vector<ll> dum = arr;
    sort(dum.begin(),dum.end());

    if(l == -1){
        cout<<"yes"<<endl;
        cout<<1<<" "<<1<<endl;
        return;
    }

    reverse(arr.begin()+l,arr.begin()+r+1);
    // printV(arr);

    if(dum == arr){
        cout<<"yes"<<endl;
        cout<<l+1<<" "<<r+1<<endl;
    }else{
        cout<<"no"<<endl;
    }
}