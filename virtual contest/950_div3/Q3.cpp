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

    vector<ll> a(n);
    inputV(a,n);

    vector<ll> b(n);
    inputV(b,n);

    ll op;
    cin>>op;

    vector<ll> move(op);
    inputV(move,op);

    set<ll> var;
    set<ll> khali;
    map<ll,ll> mp;

    for(ll i =0; i<n; i++){
        if(a[i] != b[i]){
            var.insert(b[i]);
            mp[b[i]]++;
        }
    }

    for(auto i:move){
        khali.insert(i);
    }

    for(auto i : var){
        if(khali.count(i)){

        }else{
            cout<<"NO"<<endl;
            return;
        }
    }

    set<ll> check;

    for(auto i: b){
        check.insert(i);
    }


    ll cnt = 0;

    for(auto i : move){
        if(check.count(i)){
            cnt = 0;
            mp[i]--;
        }else{
            cnt++;
        }
    }


    if(cnt > 0){
        cout<<"NO"<<endl;
        return;
    }

    for(auto i:mp){
        if(i.second > 0){
            cout<<"NO"<<endl;
            return;
        }
    }



    cout<<"YES"<<endl;



}