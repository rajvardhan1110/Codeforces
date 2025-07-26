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

    vector<ll> arr(n);
    inputV(arr,n);

    vector<pair<ll,ll>> group;

    for(ll i = 0; i<n; i++){
        if(arr[i] < (i+1)){
            group.push_back({arr[i],i+1});
        }
    }

    ll ans = 0;

    // for(ll i=0; i<group.size(); i++){
    //     cout<<group[i].first<<" "<<group[i].second<<endl;
    // }

    map<ll,ll> mp;

    for(ll i = group.size()-1; i>=0; i--){
        ll target = group[i].first;
        // cout<<target<<endl;

        if(mp[target] > 0){
            ans += mp[target];
            continue;
        }

        ll left = 0;
        ll right = i-1;
        ll sol = 0;


        while(left <= right){
            ll mid = (left+right) / 2;
        
            if(group[mid].second < target){
                sol = mid+1;
                left = mid+1;
            }else{
                right=mid-1;
            }
        }
        mp[target] = sol;

        ans += sol;
    }

    cout<<ans<<endl;
}