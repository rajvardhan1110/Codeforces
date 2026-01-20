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

     ll n;
    cin >> n;

    vector<tuple<ll,ll,ll>> arr(n);

    for(ll i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        arr[i] = {a, b, i + 1};
    }

    sort(arr.begin(), arr.end(), [](auto &A, auto &B){
        if(get<0>(A) != get<0>(B))
            return get<0>(A) < get<0>(B);          
        if(get<1>(A) != get<1>(B))
            return get<1>(A) > get<1>(B);          
        return get<2>(A) < get<2>(B);              
    });

    for(ll i = 0; i < n - 1; i++){
        ll l1 = get<0>(arr[i]);
        ll r1 = get<1>(arr[i]);
        ll l2 = get<0>(arr[i + 1]);
        ll r2 = get<1>(arr[i + 1]);

        if(l1 <= l2 && r1 >= r2){
            cout << get<2>(arr[i + 1]) << " " << get<2>(arr[i]) << endl;
            return;
        }
    }

    cout << -1 << " " << -1 << endl;


}