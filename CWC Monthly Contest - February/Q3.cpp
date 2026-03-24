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

    ll n,s,p;
    cin>>n>>s>>p;

    ll ys=0,rp=0,rs=0,yp=0,os=0,pp=0,ps=0,op=0;

    for(ll i = 0; i<s; i++){
        string s;
        cin>>s;

        if(s == "yellow"){
            ys++;
        }else if(s ==  "red"){
            rs++;
        }else if(s ==  "orange"){
            os++;
        }else if(s ==  "purple"){
            ps++;
        }
    }

    for(ll i = 0; i<p; i++){
        string s;
        cin>>s;

        if(s == "yellow"){
            yp++;
        }else if(s ==  "red"){
            rp++;
        }else if(s ==  "orange"){
            op++;
        }else if(s ==  "purple"){
            pp++;
        }
    }

    ll total = s*p;

    // total -= (ys*rp);
    // total -= (rs*yp);
    // total -= (os*pp);
    // total -= (ps*op);

    ll minus = (ys * rp + rs * yp + os * pp + ps * op) % MOD;

    ll rem = (total - minus + MOD) % MOD;
    ll base = (rem - 1 + MOD) % MOD;

    ll ans = (rem * (binExpRecur(base,n-1))) % MOD;

    cout<<ans<<endl;


}