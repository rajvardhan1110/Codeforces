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
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> arr(n);
    inputV(arr, n);

    vector<pair<pair<ll,ll>, ll>> op(m);

    vector<ll> Add(n + 1, 0);
    vector<ll> Del(n + 1, 0);

    vector<ll> Addop(m + 1, 0);
    vector<ll> Delop(m + 1, 0);

    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        op[i] = {{a - 1, b - 1}, c};   
    }

    // queries
    for (ll i = 0; i < k; i++) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        Addop[a]++;
        Delop[b]++;   
    }

    ll opcnt = 0;

    for (ll i = 0; i < m; i++) {
        opcnt += Addop[i];

        ll l = op[i].first.first;
        ll r = op[i].first.second;
        ll d = op[i].second;

        Add[l] += opcnt * d;
        Del[r] += opcnt * d;

        opcnt -= Delop[i];   
    }

    ll plus = 0;
    for (ll i = 0; i < n; i++) {
        plus += Add[i];
        arr[i] += plus;
        plus -= Del[i];
    }

    printV(arr);
}
