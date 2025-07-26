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

ll solve2(vector<pair<ll,ll>>& arr,ll index,vector<ll>& dp){
    if(index >= arr.size()){
        return 0;
    }

    if(dp[index] != -1){
        return dp[index];
    }

    //lelo
    ll nxt = index + 1;
    if (nxt < arr.size() && arr[nxt].first == arr[index].first + 1) {
        nxt++; 
    }
    ll lelo = arr[index].first * arr[index].second + solve2(arr, nxt, dp);

    //chod do
    ll chod = solve2(arr,index+1,dp);

    ll ans = max(lelo,chod);

    dp[index] = ans;

    return ans;

}

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin >> t;
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

    map<ll,ll> mp;

    for(ll i=0; i<n; i++){
        mp[arr[i]]++;
    }

    vector<pair<ll,ll>> arr2;

    for(auto i: mp){
        arr2.push_back({i.first,i.second});
    }

    sort(arr2.begin(),arr2.end());

    vector<ll> dp(arr2.size(),-1);

    cout<<solve2(arr2,0,dp)<<endl;
}