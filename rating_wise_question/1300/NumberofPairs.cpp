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

    vector<ll> arr(n);
    inputV(arr,n);

    ll ans = 0;

    sort(arr.begin(),arr.end());

    // for(ll i = 0; i<n; i++){
    //     ll num = arr[i];

    //     ll l1 = i+1;
    //     ll r1 = n-1;

    //     ll l2 = i+1;
    //     ll r2 = n-1;

    //     ll la = -1;
    //     ll ra = -1;

    //     while(l1 <= r1){
    //         ll mid = (l1+r1) / 2;

    //         if (num + arr[mid] >= a) {
    //             la = mid;
    //             r1 = mid - 1;
    //         } else {
    //             l1 = mid + 1;
    //         }
    //     }

    //     while(l2 <= r2){
    //         ll mid = (l2+r2) / 2;

    //         if (num + arr[mid] <= b) {
    //             ra = mid;
    //             l2 = mid + 1;
    //         } else {
    //             r2 = mid - 1;
    //         }
    //     }

    //     if(la != -1 && ra != -1 && ra >= la){
    //         ans += (ra-la+1);
    //     }
    // }

    for(ll i = 0; i<n; i++){
        ll lowVal = a - arr[i];
        ll highVal = b - arr[i];

        auto lowIt = lower_bound(arr.begin() + i + 1, arr.end(), lowVal);
        auto highIt = upper_bound(arr.begin() + i + 1, arr.end(), highVal);

        ans += (highIt - lowIt);
    }

    cout<<ans<<endl;
}