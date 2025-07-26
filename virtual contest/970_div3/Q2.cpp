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

    string s;
    cin>>s;


    ll sq = sqrt(n);

    if(sq * sq != n){
        cout<<"No"<<endl;
        return;
    }

    vector<vector<char>> arr(sq,vector<char> (sq));

    for(ll i=0; i<n; i++){
        arr[i/sq][i%sq] = s[i];
    }

    bool flag = false;

    //first row

    for(ll i = 0; i<sq; i++){
        if(arr[0][i] == '0'){
            cout<<"No"<<endl;
            flag = true;
            return;
        }
    }

    //last row

    for(ll i = 0; i<sq; i++){
        if(arr[sq-1][i] == '0'){
            cout<<"No"<<endl;
            flag = true;
            return;
        }
    }

    // first col

    for(ll i = 0; i<sq; i++){
        if(arr[i][0] == '0'){
            cout<<"No"<<endl;
            flag = true;
            return;
        }
    }

    // last col

    for(ll i = 0; i<sq; i++){
        if(arr[i][sq-1] == '0'){
            cout<<"No"<<endl;
            flag = true;
            return;
        }
    }

    //middle

    for(ll i =1; i<sq-1; i++){
        for(ll j = 1; j<sq-1; j++){
            if(arr[i][j] == '1'){
                cout<<"No"<<endl;
                return;
            }
        }
    }

    cout<<"Yes"<<endl;

}