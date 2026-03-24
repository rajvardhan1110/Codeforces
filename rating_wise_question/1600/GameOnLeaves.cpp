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

ll dfs(ll node, ll parent, vector<vector<ll>> &adj) {
    ll cnt = 1;
    for (auto next : adj[node]) {
        if (next != parent) {
            cnt += dfs(next, node, adj);
        }
    }
    return cnt;
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

    ll n,x;
    cin>>n>>x;

    if(n == 1){
        cout<<"Ayush"<<endl;
        return;
    }

    vector<vector<ll>> adj(n + 1);

    for(ll i = 1; i<n; i++){
        ll a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    priority_queue<ll> groups;

    for (auto neighbor : adj[x]) {
        ll cnt = dfs(neighbor, x, adj);
        groups.push(cnt);
    }

    string turn = "Ayush";

    while(groups.size() != 1){
        if(turn == "Ayush"){
            turn = "Ashish";
        }else{
            turn = "Ayush";
        }

        ll Big = groups.top();
        groups.pop();

        Big--;

        if(Big > 0){
            groups.push(Big);
        }
    }

    cout<<turn<<endl;
}