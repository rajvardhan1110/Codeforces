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

    // ll n;
    // cin>>n;

    // vector<ll> arr(n);
    // inputV(arr,n);

    // for(ll i=0; i<n; i++){
    //     arr[i] -= 1;
    // }


    // string s;
    // cin>>s;

    // map<ll,set<ll>> mp;
    // set<ll> big;

    // vector<ll> ans(n);

    // for(ll i = 0; i<n; i++){
    //     ll j = arr[i];
    //     if (big.count(j)) {

    //         for(auto k : mp){
    //             set<ll> dummy = k.second;

    //             if(dummy.count(j)){
    //                 ans[i] = k.first;
    //                 break;
    //             }
    //         }
             
    //     } else {
    //         ll num = arr[j];
    //         ll cnt = 0;
    //         set<ll> own;
    //         own.insert(j);
    //         big.insert(j);

    //         if(s[j] == '0'){
    //             cnt++;
    //         }

    //         while(num != arr[i]){
    //             if(s[num] == '0'){
    //                 cnt++;
    //             }

    //             own.insert(num);
    //             big.insert(num);

    //             num = arr[num];
    //         }

    //         ans[i] = cnt;

    //         for(auto i:own){
    //             mp[cnt].insert(i);
    //         }


    //     }

    // }

    // printV(ans);



    ll n;
    cin >> n;

    vector<ll> arr(n);

    inputV(arr,n);

    for(ll i=0; i<n; i++){
        arr[i] -= 1;
    }

    
    string s;
    cin >> s;

    vector<ll> ans(n);
    vector<bool> flag(n, false);

    for (ll i = 0; i < n; ++i) {
        if (flag[i]) continue;

        vector<ll> cycle;
        ll u = i;

        while (!flag[u]) {
            flag[u] = true;
            cycle.push_back(u);
            u = arr[u];
        }

        
        ll cnt = 0;
        for (auto x : cycle) {
            if (s[x] == '0') cnt++;
        }

        for (auto x : cycle) {
            ans[x] = cnt;
        }
    }

    printV(ans);
    


}