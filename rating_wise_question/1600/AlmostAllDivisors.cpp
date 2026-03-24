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

bool check(ll n,set<ll> &s) {


    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if(!s.count(i)){
                return false;
            }

            if (i != n / i) {
               
                if(!s.count(n/i)){
                    return false;
                }
            }
        }
    }

   return true;
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

    vector<ll> arr(n);
    inputV(arr,n);

    sort(arr.begin(),arr.end());

    ll ans = arr[0]*arr[n-1];

    ll i = 1;
    ll j = n-2; 

    while(i <= j){
        if(arr[i]*arr[j] != ans){
            cout<<-1<<endl;
            return;
        }
        i++;
        j--;
    }

    set<ll> s(arr.begin(),arr.end());
    if(!check(ans,s)){
        cout<<-1<<endl;
        return;
    }


    cout<<ans<<endl;
}