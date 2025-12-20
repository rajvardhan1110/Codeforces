#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MOD = 1000000007; // 1e9 + 7

void inputV(vector<ll> &v, ll size) {
    v.resize(size);
    for (ll i = 0; i < size; i++) {
        cin >> v[i];
    }
}

void printV(const vector<ll> &v) {
    for (ll val : v) {
        cout << val << " ";
    }
    cout << endl;
}

void createsieve(vector<bool> &prime, ll n) {
    prime[0] = prime[1] = false;
    for (ll i = 2; i * i < n; i++) {
        if (prime[i]) {
            for (ll j = i * i; j < n; j += i) {
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

    string s;
    ll k;
    cin >> s >> k;
    ll n = s.size();
    
    vector<bool> rusted(n, false);

    
    for (ll i = 0; i < n; i++) {
        if (s[i] == 'R') rusted[i] = true;
    }

    
    ll lastR = -1e9; 

    for (ll i = 0; i < n; i++) {
        if (s[i] == 'R') lastR = i;

        
        if (i - lastR <= k && lastR != -1e9){
            rusted[i] = true;
        } 
    }

    
    lastR = 1e9; 

    for (ll i = n - 1; i >= 0; i--) {
        if (s[i] == 'R') lastR = i;

        if (lastR - i <= k && lastR != 1e9){
            rusted[i] = true;
        } 
    }

    
    ll ans = 0;
    ll i = 0;
    while (i < n) {
        if (rusted[i]) {
            i++;
            continue;
        }
        ll len = 0;


        while (i < n && !rusted[i]) {
            len++;

            i++;
        }


        ans += (len + 1) / 2;
    }



    cout << ans << endl;



}







