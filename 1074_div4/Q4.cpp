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
    
    ll n, m, h;
    cin>>n>>m>>h;

    vector<ll> arr(n);
    inputV(arr, n);

    vector<ll> change = arr;
    vector<ll> I; 
    vector<bool> flag(n, false);

    for(ll i = 0; i < m; i++){
        ll a, b;
        cin >> a >> b;
        a--; 

        if(change[a] + b > h){
            
            for(ll idx : I){
                change[idx] = arr[idx];
                flag[idx] = false;
            }
            I.clear();
        } else {
            change[a] += b;
            if (!flag[a]) {
                flag[a] = true;
                I.push_back(a);
            }
        }
    }

    printV(change);
}