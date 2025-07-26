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

    ll currh = arr[k-1];
    // cout<<currh<<endl;

    sort(arr.begin(), arr.end());
    set<ll> s(arr.begin(), arr.end());

    
    auto it = s.lower_bound(currh);
    s.erase(s.begin(), it);

    vector<ll> d;

    for(auto i:s){
        // cout<<i<<" ";
        d.push_back(i);
    }

    ll currw = 1;

    if(currw > currh){
        cout<<"NO"<<endl;
        return;
    }

    ll lower = currh;

    for(ll i = 0; i<d.size()-1; i++){

        if(d[i+1]-d[i]+currw-1 > d[i]){
            cout<<"NO"<<endl;
            return;
        }

        currw += d[i+1] - d[i];
    }

    cout<<"YES"<<endl;

    
}