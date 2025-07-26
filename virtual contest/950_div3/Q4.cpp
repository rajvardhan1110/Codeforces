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

    ll ind = -1;

    ll prev = __gcd(arr[0],arr[1]);

    for(ll i = 1; i<n-1; i++){
        if(__gcd(arr[i],arr[i+1]) < prev){
            ind = i;
            break;
        }else{
            prev = __gcd(arr[i],arr[i+1]);
        }
    }

    if(ind == -1){
        cout<<"YES"<<endl;
        return;
    }


    vector<ll> imin;

    for(ll i = 0; i<n-1; i++){
        if(i == ind-1){
            continue;
        }

        if(i+1 == ind-1){
            if(i+2 < n){
                imin.push_back(__gcd(arr[i],arr[i+2]));
            }
        }else{
            imin.push_back(__gcd(arr[i],arr[i+1]));
        }
    }

    bool flag1 = true;

    for(ll i =1; i<imin.size(); i++){
        if(imin[i] < imin[i-1]){
            flag1 = false;
            break;

        }
    }

    if(flag1){
        cout<<"YES"<<endl;
        return;
    }

    vector<ll> ieq;

    for(ll i = 0; i<n-1; i++){
        if(i == ind){
            continue;
        }

        if(i+1 == ind){
            if(i+2 < n){
                ieq.push_back(__gcd(arr[i],arr[i+2]));
            }
        }else{
            ieq.push_back(__gcd(arr[i],arr[i+1]));
        }
    }

    bool flag2 = true;

    for(ll i =1; i<ieq.size(); i++){
        if(ieq[i] < ieq[i-1]){
            flag2 = false;
            break;

        }
    }

    if(flag2){
        cout<<"YES"<<endl;
        return;
    }

    vector<ll> inext;

    for(ll i = 0; i<n-1; i++){
        if(i == ind+1){
            continue;
        }

        if(i+1 == ind+1){
            if(i+2 < n){
                inext.push_back(__gcd(arr[i],arr[i+2]));
            }
        }else{
            inext.push_back(__gcd(arr[i],arr[i+1]));
        }
    }

    bool flag3 = true;

    for(ll i =1; i<inext.size(); i++){
        if(inext[i] < inext[i-1]){
            flag3 = false;
            break;

        }
    }

    if(flag3){
        cout<<"YES"<<endl;
        return;
    }


    cout<<"NO"<<endl;
    
}