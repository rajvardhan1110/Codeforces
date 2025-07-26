#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MOD = 1000000007; // 1e9 + 7

// vector<ll> prime(1e7);

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
    // createsieve(prime,1e7);
    while (t--) {
        solve();
    }
}

void solve() {
    //Rajvardhan Patil

    ll n;
    cin>>n;

    vector<ll> odd;
    vector<ll> even;

    if(n<=4){
        cout<<-1<<endl;
        return;
    }

    for(ll i =1; i<=n; i++){
        if(i % 2 == 0){
            even.push_back(i);
        }else{
            odd.push_back(i);
        }
    }

    vector<ll> ans;

    for(ll i =0; i<odd.size(); i++){
        if(odd[i] != 5){
            ans.push_back(odd[i]);
        }
    }

    ans.push_back(5);
    ans.push_back(4);

    for(ll i =0; i<even.size(); i++){
        if(even[i] != 4){
            ans.push_back(even[i]);
        }
    }

    printV(ans);

}