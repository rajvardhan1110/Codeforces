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

    ll n,k;
    cin>>n>>k;


    vector<ll> arr(n);
    inputV(arr,n);

    ll ind1 = 0;
    ll ind2 = n-1;

    ll cnt1 = 0;
    ll cnt2 = 0;
    

    ll i = 0;

    while(cnt1 < k && i<n){
        if(arr[i] == arr[0]){
            cnt1++;
            ind1 = i;
        }

        i++;
    }

    if(cnt1 < k){
        cout<<"NO"<<endl;
        return;
    }

    i = n-1;

    while(cnt2 < k && i >= 0){
        if(arr[i] == arr[n-1]){
            cnt2++;
            ind2 = i;
        }

        i--;
    }

    if(cnt2 < k){
        cout<<"NO"<<endl;
        return;
    }

    if(ind1 < ind2){
        cout<<"YES"<<endl;
    }else{
        if(arr[0] == arr[n-1]){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }



    
}