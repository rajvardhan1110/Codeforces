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

    ll n,a,b;

    cin>>n>>a>>b;

    ll n1 = n / a;
    ll n2 = n / b;

    ll F = n1*a;
    ll S = n2*b;

    ll upto = min(F,S);

    ll Find = (a * b) / __gcd(a, b);

    ll comm = upto / Find;

    ll num1 = n1 - comm;
    ll num2 = n2 - comm;

    ll x = num1-1;
    ll y = (x*(x+1)) / 2;

    ll maxi = num1*n - y;
    ll mini = (num2*(num2+1)) / 2;

    cout<<maxi - mini<<endl;

    
}