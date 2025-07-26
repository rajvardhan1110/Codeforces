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

    ll n,k;
    cin>>n>>k;

    vector<ll> arr(n);

    inputV(arr,n);

    ll ans = INT_MAX;

    map<ll,vector<ll>> mp;

    for(ll i = 0; i<n; i++){
        mp[arr[i]].push_back(i);
    }

    for(auto i : mp){
        vector<ll> dummy = i.second;
        vector<ll> check;

        // printV(dummy);

        for(int j=0; j<dummy.size(); j++){
            if(j == 0){
                check.push_back(dummy[j]);
            }else{
                check.push_back(dummy[j] - dummy[j-1] - 1);
            }
        }

        check.push_back(arr.size()-1-dummy[dummy.size()-1]);

        // cout<<i.first<<endl;
        // printV(check);

        ll lastindex = check.size() - 1;

        sort(check.begin(),check.end());

        ll S = max(check[lastindex] / 2,check[lastindex-1]);

        ans = min(ans,S);

        // cout<<ans<<endl;
    }

    cout<<ans<<endl;
}