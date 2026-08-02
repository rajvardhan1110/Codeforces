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

const int MAXR = 2023;

ll dp[MAXR][MAXR];

ll getVal(ll r, ll c){
    return (r*(r+1))/2 + c + 1;
}

void precompute(){
    for(int r = 0; r < MAXR; r++){
        for(int c = 0; c <= r; c++){
            ll val = getVal(r,c);
            ll sq = val * val;

            dp[r][c] = sq;

            if(r-1 >= 0 && c-1 >= 0)
                dp[r][c] += dp[r-1][c-1];

            if(r-1 >= 0 && c <= r-1)
                dp[r][c] += dp[r-1][c];

            if(r-2 >= 0 && c-1 >= 0 && c-1 <= r-2)
                dp[r][c] -= dp[r-2][c-1];
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    precompute();
    while (t--) {
        
        solve();
    }
}

void solve() {
    //Rajvardhan Patil

    ll n;
    cin >> n;

    ll r = 0;
    while((r+1)*(r+2)/2 < n) r++;

    ll start = r*(r+1)/2 + 1;
    ll c = n - start;

    cout << dp[r][c] << endl;
}