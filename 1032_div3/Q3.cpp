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

    ll n,m;

    cin>>n>>m;

    vector<vector<ll>> arr(n,vector<ll> (m));

    map<ll,ll> row;
    map<ll,ll> col;

    ll total = 1;

    vector<ll> num;


    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<m; j++){
            cin>>arr[i][j];

            num.push_back(arr[i][j]);

        }
    }

    sort(num.begin(),num.end());

    ll maxi = num[num.size() - 1];

    ll secmaxi = 0;

    for(ll i=num.size() - 2; i>=0; i--){
        if(num[i] == maxi){
            total++;
        }else{
            secmaxi = num[i];
            break;
        }
    }

    // cout<<"maxi = "<<maxi<<endl;
    // cout<<"secmaxi = "<<secmaxi<<endl;

    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<m; j++){
            
            if(arr[i][j] == maxi){
                row[i]++;
                col[j]++;
            }

        }
    }

    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<m; j++){
            
           if(arr[i][j] == maxi){
                if(row[i] + col[j] - 1 == total){
                    cout<<maxi-1<<endl;
                    return;
                }
           }else{
                if(row[i] + col[j] == total){
                    cout<<maxi-1<<endl;
                    return;
                }
           }
        }
    }

    cout<<maxi<<endl;

    
    


}