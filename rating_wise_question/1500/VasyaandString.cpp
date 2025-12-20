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

    ll n,m;

    cin>>n>>m;

    string s;
    cin>>s;

    ll a = 0;
    ll b = 0;

    ll i = 0; 
    ll j = 0;

    ll ans = INT_MIN;

    while(j < n){

        if(s[j] == 'a'){
            a++;
        }

        while(a > m){
            if(s[i] == 'a'){
                a--;
            }

            i++;
        }

        ans = max(ans,j-i+1);
        j++;

    }

    i = 0;
    j = 0;

    while(j < n){

        if(s[j] == 'b'){
            b++;
        }

        while(b > m){
            if(s[i] == 'b'){
                b--;
            }

            i++;
        }

        ans = max(ans,j-i+1);
        j++;

    }

    cout<<ans<<endl;
}