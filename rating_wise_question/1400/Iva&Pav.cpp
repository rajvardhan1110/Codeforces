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

// FIXED: correct zero counting for range [low, high]
ll solve2(ll low,ll high,vector<vector<ll>>& zero){
    ll ans = 0;
    for(ll i = 0; i<=30; i++){
        ll cntZeros = zero[i][high] - (low > 0 ? zero[i][low - 1] : 0);
        if(cntZeros == 0){
            ans += (1LL << i);
        }
    }
    return ans;
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
    // Rajvardhan Patil

    ll n;
    cin>>n;

    vector<ll> arr(n);
    inputV(arr,n);

    vector<vector<ll>> zero(31,vector<ll> (n,0));

    for(ll i = 0; i<=30; i++){
        ll cnt = 0;
        for(ll j = 0; j<n; j++){
            if((1<<i) & arr[j]){
                // bit is 1, do nothing
            }else{
                cnt++;
            }
            zero[i][j] = cnt;
        }
    }

    ll q;
    cin>>q;

    while(q--){
        ll l,k;
        cin>>l>>k;
        l--;

        if(arr[l] < k){
            cout<<-1<<" ";
            continue;
        }

        ll low = l;
        ll high = n-1;

        // FIXED: binary search condition and mid calculation
        while(low < high){
            ll mid = (low + high +1) / 2;
            if(solve2(l, mid, zero) >= k){
                low = mid;
            }else{
                high = mid - 1;
            }
        }

        cout<<low+1<<" ";
    }

    cout<<endl;
}
