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


    ll x = n;

    vector<ll> fact;

    while(n % 2 == 0){
        fact.push_back(2);
        n /= 2;
    }

    for(ll i = 3; i*i <= n; i += 2){
        while(n % i == 0){
            fact.push_back(i);
            n /= i;
        }
    }

    if(n > 1){
        fact.push_back(n);
    }

    if(fact.size() < 3){
        cout<<"NO"<<endl;
        return;
    }

    vector<ll> ans;

    ans.push_back(fact[0]);

    ll prd = 1;


    ll ind = 1;
    for(ind = 1; ind<fact.size(); ind++){
        prd *= fact[ind];

        if(prd != fact[0]){
            ans.push_back(prd);
            break;
        }

    }

    ll another = 1;

    for(ll i = ind+1; i<fact.size(); i++){
        another *= fact[i];
    }

    if(another != 1){
        ans.push_back(another);
    }

    set<ll> s;

    for(auto i : ans){
        s.insert(i);
    }

    if(s.size() != 3){
        cout<<"NO"<<endl;
        return;
    }else{
        cout<<"YES"<<endl;
        for(auto i:s){
            cout<<i<<" ";
        }

        cout<<endl;
    }
}