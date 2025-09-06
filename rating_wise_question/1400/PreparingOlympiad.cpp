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

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}

void solve() {
    //Rajvardhan Patil

    ll n,b,c,d;
    cin>>n>>b>>c>>d;

    vector<ll> arr(n);
    inputV(arr,n);

    sort(arr.begin(),arr.end());

    vector<vector<ll>> ans;

        

        ll upto = (1<<n);

        for(ll i=0; i<upto; i++){
            vector<ll> v;

            for(int j=0; j<n; j++){
                if(i & (1 << j)){
                    v.push_back(arr[j]);
                }
            }

            ans.push_back(v);
        }

    ll sol = 0;

    for(ll i =0; i<ans.size(); i++){
        if(ans[i].size() >= 2){
            ll mini = ans[i][0];
            ll maxi = ans[i][ans[i].size()-1];

            ll sum = accumulate(ans[i].begin(),ans[i].end(),0);

            if(sum >= b && sum <= c && maxi-mini >= d){
                sol++;
            }
        }
    }

    cout<<sol<<endl;
}