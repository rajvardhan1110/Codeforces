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

    ll a,b;
    cin>>a>>b;

    ll fora = 0;
    ll forb= 0;

    forb = (b/2);
    if(b % 2 != 0){
        forb++;
    }

    // cout<<"forb->"<<forb<<endl;

    
    if(b % 2 != 0){
        fora = (forb-1) * 7;
        fora += 11;
    }else{
        fora = (forb) * 7;
    }



    // cout<<"fora->"<<fora<<endl;

    if(a <= fora){
        cout<<forb<<endl;
    }else{
        a -= fora;

        ll extra = a / 15;
        if(a % 15 != 0){
            extra++;
        }

        cout<<forb+extra<<endl;
    }
}