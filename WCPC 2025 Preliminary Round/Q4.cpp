#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MOD = 1000000007; // 1e9 + 7

const ll INF = 1e18;

ll recur(int i, bool prevR, int n, vector<string> &words, vector<string> &revW, vector<ll> &cost, vector<vector<ll>> &dp) {

    if (i == n) return 0;

    if (dp[i][prevR] != -1) return dp[i][prevR];

    ll ans = INF;

    string prevWord;
    if (prevR){
        prevWord = revW[i - 1];
    }else{
        prevWord = words[i - 1];
    }
        

    
    if (words[i] >= prevWord) {
        ans = min(ans, recur(i + 1, 0, n, words, revW, cost, dp));
    }

   
    if (revW[i] >= prevWord) {
        ans = min(ans, recur(i + 1, 1, n, words, revW, cost, dp) + cost[i]);
    }

    dp[i][prevR] = ans;
    return ans;
}

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

    ll t = 1;
    // cin >> t ;
    while (t--) {
        solve();
    }
}

void solve() {

    //Rajvardhan Patil

    ll n;
    cin >> n;

    vector<ll> cost(n);
    for (ll i = 0; i < n; i++) cin >> cost[i];

    vector<string> word(n), revW(n);
    for (ll i = 0; i < n; i++) {
        cin >> word[i];
        revW[i] = word[i];
        reverse(revW[i].begin(), revW[i].end());
    }

    vector<vector<ll>> dp(n, vector<ll>(2, -1));

    ll ans = min(recur(1, 0, n, word, revW, cost, dp), recur(1, 1, n, word, revW, cost, dp) + cost[0]);

    if (ans >= INF){
        cout <<-1<< endl;
    }else{
             cout<<ans<<endl;
    }

   


    
}