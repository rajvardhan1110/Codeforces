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

ll solve2(vector<ll>& arr,ll s, ll e,ll sum,ll target,vector<vector<ll>>& dp){
    if(sum == target){
        return arr.size() - (e-s) - 1;
    }

    if(sum < target){
        return INT_MAX;
    }

    if(e < s){
        return INT_MAX;
    }

    if(dp[s][e] != -1){
        return dp[s][e];
    }

    //s

    ll x = INT_MAX;

    if(arr[s] == 1){
        x = solve2(arr,s+1,e,sum-1,target,dp);
    }else{
        x = solve2(arr,s+1,e,sum,target,dp);
    }

    //e

    ll y = INT_MAX;

    if(arr[e] == 1){
        y = solve2(arr,s,e-1,sum-1,target,dp);
    }else{
        y = solve2(arr,s,e-1,sum,target,dp);
    }

    //s e

    ll z = INT_MAX;

    if(arr[s]==1 && arr[e]==1){
        z = solve2(arr,s+1,e-1,sum-2,target,dp);
    }else if(arr[s]==1 || arr[e]==1){
        z = solve2(arr,s+1,e-1,sum-1,target,dp);
    }else{
        z = solve2(arr,s+1,e-1,sum,target,dp);
    }

    dp[s][e] = min(x,min(y,z));

    return dp[s][e];

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

    ll n,target;
    cin>>n>>target;

    vector<ll> arr(n);
    inputV(arr,n);

    vector<vector<ll>> dp(n,vector<ll> (n+1,-1));

    ll sum = 0;

    for(auto i:arr){
        if(i==1){
            sum += 1;
        }
    }

    if(sum == target){
        cout<<0<<endl;
        return;
    }


    if(sum < target){
        cout<<-1<<endl;
        return;
    }

    ll w = solve2(arr,0,n-1,sum,target,dp);

    cout<<w<<endl;
}