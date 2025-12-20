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

ll solve2(map<pair<ll,ll>,ll>& mp,vector<ll>& t,vector<ll>& h,ll ind,ll prev){
    if(ind >= t.size()){
        return 0;
    }

    if(mp.count({ind,prev})){
        return mp[{ind,prev}];
    }

    ll ans = 0;


    //standing

    ans =max(ans,solve2(mp,t,h,ind+1,t[ind]));

    //left
    if(t[ind] - h[ind] > prev){
        ans =max(ans,1+solve2(mp,t,h,ind+1,t[ind]));
    }

    //right
    if(ind == (t.size()-1) || t[ind] + h[ind] < t[ind+1]){
        ans =max(ans,1+solve2(mp,t,h,ind+1,t[ind]+h[ind]));
    }

    mp[{ind,prev}] = ans;

    return ans;
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

    ll n;
    cin>>n;

    vector<ll> t(n);
    vector<ll> h(n);

    for(int i=0; i<n; i++){
        cin>>t[i]>>h[i];
    }

    map<pair<ll,ll>,ll> mp;

    cout<<solve2(mp,t,h,0,LLONG_MIN)<<endl;
}