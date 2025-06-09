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
    ll n, k, diff;

    cin>>n>>k>>diff;

    vector<ll> arr(n);
    inputV(arr,n);

    ll cnt = 0;

    sort(arr.begin(),arr.end());

    if(n == 1){
        cout<<1<<endl;
        return;
    }

    vector<ll> sol;

    for(ll i=1; i<n; i++){
        if(arr[i] - arr[i-1] > diff){
            
            ll x = arr[i] - arr[i-1];

            if(x%diff == 0){
                sol.push_back(x/diff - 1);
            }else{
                sol.push_back(x/diff);
            }
            
        }
    }

    sort(sol.begin(),sol.end());

    // printV(sol);

    ll ind = 0;

    while(k && ind < sol.size()){
        if(k >= sol[ind]){
            k -= sol[ind];
            sol[ind]=0;
        }else{
            break;
        }
        ind++;
    }

    // printV(sol);

    for(ll i=0; i<sol.size(); i++){
        if(sol[i] == 0){
            cnt++;
        }else{
            break;
        }
    }

    cout<<sol.size()-cnt+1<<endl;
}