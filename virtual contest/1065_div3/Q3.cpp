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

    vector<ll> a(n);
    vector<ll> b(n);

    inputV(a,n);
    inputV(b,n);

    ll a0=0,a1=0,b0=0,b1=0;

    for(auto i : a){
        if(i == 0){
            a0++;
        }else{
            a1++;
        }
    }

    for(auto i : b){
        if(i == 0){
            b0++;
        }else{
            b1++;
        }
    }

    //a1,b1

    for(ll i = 0; i<n; i++){
        if(a[i] != b[i]){

            if(i&1){//m
                if(b1&1){

                }else{
                    b1++;
                    a1--;
                }
            }else{//a
                if(a1&1){

                }else{
                    a1++;
                    b1--;
                }
            }


        }
    }

    if((a1&1) && (b1&1) || (a1%2 == 0 && b1%2 == 0)){
        cout<<"Tie"<<endl;
    }else if(a1&1){
        cout<<"Ajisai"<<endl;
    }else{
        cout<<"Mai"<<endl;
    }
}