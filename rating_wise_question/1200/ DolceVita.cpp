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

    ll n,tar;
    cin>>n>>tar;

    vector<ll> arr(n);
    inputV(arr,n);

    sort(arr.begin(),arr.end());

    vector<ll> pref(n);
    pref[0] = arr[0];

    for(ll i=1; i<n; i++){
        pref[i] = arr[i] + pref[i-1];
    }

    // printV(pref);

    ll count = 0;

    ll sol = 0;

    // ll i = 0;
    // ll j = n-1;

    // while(j != -1){
    //     i = 0;
    //     j = n-1;

    //     ll ans = -1;

    //     while(i<=j){
    //         ll mid = (i+j) / 2;

    //         if(pref[mid] + (count*(mid+1)) <= tar){
    //             ans = mid;
    //             i = mid + 1;
    //         }else{
    //            j = mid - 1;
    //         }
    //     }

    //     if(j != -1 && ans != -1){
    //         sol += ans + 1;
    //     }else{
    //         break;
    //     }

    //     count++;
    // }

    // cout<<sol<<endl;

    for(ll i=0; i<n; i++){
        ll diff = tar - pref[i];
        ll div = i+1;

        if(diff < 0){
            break;


        }

        count += (diff/div) + 1;
    }

    cout<<count<<endl;




}