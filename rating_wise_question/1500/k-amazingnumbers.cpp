#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MOD = 1000000007; // 1e9 + 7

void inputV(vector<ll> &v, ll size) {
    v.resize(size);
    for (ll i = 0; i < size; i++) {
        cin >> v[i];
    }
}

void printV(const vector<ll> &v) {
    for (ll val : v) {
        cout << val << " ";
    }
    cout << endl;
}

void createsieve(vector<bool> &prime, ll n) {
    prime[0] = prime[1] = false;
    for (ll i = 2; i * i < n; i++) {
        if (prime[i]) {
            for (ll j = i * i; j < n; j += i) {
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

    ll t;
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

    for(ll i=1;i<=n;i++) cin>>arr[i];



    map<ll,ll> last_pos;

    map<ll,ll> pos_diff;

    for(ll i=1;i<=n;i++){

        pos_diff[arr[i]] = max(pos_diff[arr[i]],i-last_pos[arr[i]]);

        last_pos[arr[i]] = i;

    }

    for(auto i:last_pos){

        pos_diff[i.first] = max(pos_diff[i.first],n-i.second+1);

    }

    vector<ll> ans(n+1,INT_MAX);

    for(auto i:pos_diff){

        ans[i.second] = min(i.first,ans[i.second]);

    }

    ll last_min = INT_MAX;

    for(ll i=1;i<=n;i++){

        ans[i] = min(ans[i],last_min);

        if(ans[i] == INT_MAX) cout<<-1<<" ";

        else cout<<ans[i]<<" ";

        last_min = ans[i];

    }

    cout<<endl;
}