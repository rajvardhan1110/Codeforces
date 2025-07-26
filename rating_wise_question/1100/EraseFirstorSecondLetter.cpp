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

// void solve2(string s,unordered_set<string>& se){
//     if(s.empty() || se.count(s)){
//         return;
//     }

//     se.insert(s);

//     //first remove
//     if(s.size() >= 1){
//         solve2(s.substr(1),se);
//     }


//     //sec remove

//     if(s.size() >= 2){
//         solve2(s[0] + s.substr(2),se);
//     }
// }

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

    string s;
    cin>>s;

    unordered_set<char> se;
    // // se.insert(s.begin(),s.end());

    // // vector<vector<int>> dp(n,vector<int> (n,-1));

    // solve2(s,se);

    // cout<< se.size() << endl;

    ll ans  = 1;
    se.insert(s[0]);

    for(ll i = 1; i<n; i++){
        se.insert(s[i]);

        ans += se.size();
    }

    cout<<ans<<endl;
}