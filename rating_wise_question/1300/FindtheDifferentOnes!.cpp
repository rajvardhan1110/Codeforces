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

     vector<ll> arr(n+1);

     for(ll i=1; i<=n; i++){
        cin>>arr[i];
     }

     ll q;
     cin>>q;


    //  vector<ll> Left(n+1);
     vector<ll> Right(n+1);

    vector<ll> Left(n + 1, -1); // assuming 1-based indexing
    ll lMiniInd = -1;

    for (ll i = 1; i <= n; i++) {
        if (lMiniInd == -1) {
            Left[i] = -1;
        } else {
            Left[i] = lMiniInd;
        }

        // Update lMiniInd only if i < n to avoid out of bounds
        if (i < n && arr[i] != arr[i + 1]) {
            lMiniInd = i;
        }
    }

     ll rMiniInd = -1;


     for(ll i=n; i>=1; i--){
        if(rMiniInd == -1){
            Right[i] = -1;
            if(i != 1){
                if(arr[i] != arr[i-1]){
                    rMiniInd = i;
                }
            }
        }else{

            Right[i] = rMiniInd;

            if(i != 1){
                if(arr[i] != arr[i-1]){
                    rMiniInd = i;
                }
            }

        }
     }

     Left[0] = -1;
     Right[0] = -1;
    //  printV(Left);
    //  printV(Right);

     while(q--){
        ll l;
        ll r;

        cin>>l>>r;

        if(Left[r] != -1 && Left[r] >= l){
            cout<<Left[r]<<" "<<r<<endl;
        }else if(Right[l] != -1 && Right[l] <= r){
            cout<<l<<" "<<Right[l]<<endl;
        }else{
            cout<<-1<<" "<<-1<<endl;
        }
     }

     cout<<endl;


}