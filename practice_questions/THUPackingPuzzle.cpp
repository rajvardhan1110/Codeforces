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

    ll t,h,u;
    cin>>t>>h>>u;

    ll ans = 0;

    ll tu = min(t,u);
    ans += (tu*4);
    t -= tu;

    u -= tu;


    if(u > 0){
        ans += (3*u);
    }

    if (t >= 2 && h > 0) {
        ll tht = min(h, t / 2);
        ans += 7 * tht;
        t -= 2 * tht;
        h -= tht;
    }

    if(t == 1 && h > 0){
        ans += 5;
        t = 0;
        h--;
    }

    if(t > 0){
        if(t == 1){
            ans += 3;
        }else{
            ans += 3 + (t-1)*2;
        }
    }

    if(h > 0){
        ans += (3*h);
    }

    cout<<ans<<endl;


    

}