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

    ll row,col;
    cin>>row>>col;

    // vector<vector<ll>> grid(row,vector<ll> (col));
   vector<string> grid(row);

    for(ll i=0; i<row; i++){
        cin>>grid[i];
    }

    ll ans = 0;

    ll x = min(row/2,col/2);

    for(ll z=0; z<x; z++){

        vector<ll> check;

        //left to right

        ll l = z;

        for(int i=z; i<col-l; i++){
            check.push_back(grid[l][i] - '0');
        }

        //top to bottom

        ll t = z+1;

        for(ll i=t; i<row-z; i++){
            check.push_back(grid[i][col-z-1] - '0');
        }

        //right to left

        for(ll i = col-2-z; i>=z; i--){
            check.push_back(grid[row-z-1][i] - '0');
        }

        //bottom to up

        for(ll i = row-2-z; i>=z; i--){
            check.push_back(grid[i][z] - '0');
        }

        check.push_back(check[1]);
        check.push_back(check[2]);


        for(ll i=0; i<=check.size()-4; i++){
            if(check[i] == 1 && check[i+1] == 5 && check[i+2] == 4 && check[i+3] == 3){
                ans++;
            }
        }


    }

    cout<<ans<<endl;
}