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
    cin >> t;
    while (t--) {
        solve();
    }
}

void solve() {
    //Rajvardhan Patil

    ll n;
    cin>>n;

    if(n == 1){
        cout<<"FastestFinger"<<endl;
        return;
    }

    ll cnt = 0;
    ll even = 0;

     while (n % 2 == 0) {
        n /= 2;
        even++;
    }

   
    for (ll i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
           if(i&1){
            cnt++;
           }else{
            even++;
           }
            n /= i;
        }
    }

   
    if (n > 2) {
        if(n&1){
            cnt++;
        }else{
            even++;
        }
    }

    if(even == 0){
        cout<<"Ashishgup"<<endl;
        return;
    }

    

    // if(cnt&1){
    //     if(even == 1){
    //         cout<<"FastestFinger"<<endl;
    //     }else{
            
    //         cout<<"Ashishgup"<<endl;
    //     }
        
    // }else{
    //     if(even == 1){
    //         cout<<"Ashishgup"<<endl;
    //     }else{
    //         cout<<"FastestFinger"<<endl;
    //     }
    // }

    if(cnt > 0){
       if(even == 1 && cnt == 1){
        cout<<"FastestFinger"<<endl;
       }else{
        cout<<"Ashishgup"<<endl;
       }
    }else{
        if(even == 1){
            cout<<"Ashishgup"<<endl;
        }else{
            cout<<"FastestFinger"<<endl;
        }
        
    }

   
}