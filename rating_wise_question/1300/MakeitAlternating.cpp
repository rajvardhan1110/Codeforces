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

long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++)
        res = (res*i) % 998244353;
    return res % 998244353;
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

    string s;
    cin>>s;

    vector<ll> arr;

    bool falg = false;
    
    if(s[0] == '1'){
        falg = true;
    }else{
        falg = false;

    }

    ll cnt = 0;

    for(int i=0; i<s.size();){

        if(falg == false){
            if(s[i] == '0'){
                cnt++;
                i++;
            }else{
                falg = true;
                arr.push_back(cnt);
                cnt = 0;
            }
        }else{
            if(s[i] == '1'){
                cnt++;
                i++;
            }else{
                falg = false;
                arr.push_back(cnt);
                cnt = 0;
            }
        }
    }

    arr.push_back(cnt);

    // printV(arr);

    ll n = s.size();
    ll k = arr.size();

    ll prod = 1;
    ll fi = 0;

    for (ll len : arr) {
        prod = (prod * len) % 998244353;
        fi += len - 1;
    }

    ll ways = (prod * factorial(n - k)) % 998244353;

    cout << fi <<" "<< ways << "\n";
}