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

    vector<ll> arr(n+1);

    for(ll i=1; i<=n; i++){
        cin>>arr[i];
    }

    ll ind1 = 1;
    ll ind2 = -1;

    vector<vector<ll>> ans;

    for(ll i=2; i<=n; i++){
        if(arr[ind1] != arr[i]){
            ind2 = i;
            break;
        }
    }


    if(ind2 == -1){
        cout<<"NO"<<endl;
        return;
    }

    ans.push_back({ind1,ind2});

    for(ll i= 2; i<=n; i++){
        if(ind2 == i){
            continue;
        }

        if(arr[ind1] != arr[i]){
            ans.push_back({ind1,i});
        }else{
            ans.push_back({ind2,i});
        }
    }

    cout<<"YES"<<endl;

    for(ll i = 0; i<ans.size(); i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }


}