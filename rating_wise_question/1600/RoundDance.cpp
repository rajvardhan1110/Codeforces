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

ll dfs(ll curr,vector<bool> &visit,vector<ll> &arr){
    ll cnt = 0;

    visit[curr] = 1;

    if(visit[arr[curr]] == false){
        cnt += dfs(arr[curr],visit,arr);
    }

    return cnt;

}

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
    cin >> n;

    vector<ll> arr(n + 1);
    for (ll i = 1; i <= n; i++) cin >> arr[i];

    vector<bool> vis(n + 1, false);

    ll cycles = 0;
    ll cnt2 = 0;

    for (ll i = 1; i <= n; i++) {
        if (!vis[i]) {
            ll curr = i;
            unordered_map<ll, ll> pos; 

            ll step = 0;

            while (!vis[curr]) {
                vis[curr] = true;
                pos[curr] = step++;
                curr = arr[curr];
            }

            if (pos.count(curr)) {
                ll cycle_size = step - pos[curr];
                cycles++;

                if (cycle_size == 2) cnt2++;
            }
        }
    }

    ll maxi = cycles;
    ll mini = cycles;

    if (cnt2 > 0) {
        mini = cycles - cnt2 + 1;
    }

    cout << mini << " " << maxi << endl;




}