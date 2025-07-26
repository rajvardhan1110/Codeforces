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

    ll h,p,l;
    cin>>h>>p>>l;

    vector<pair<ll,ll>> hurdle;
    vector<pair<ll,ll>> powerup;

    while(h--){
        ll a,b;
        cin>>a>>b;

        hurdle.push_back({a,b});
    }

    while(p--){
        ll a,b;

        cin>>a>>b;

        powerup.push_back({a,b});
    }

    priority_queue<ll> qu;

    ll indexhurdle = 0;
    ll indexpower = 0;

    ll ans = 0;

    ll score = 1;

    while(indexhurdle < hurdle.size()){

        ll upto = hurdle[indexhurdle].first;
        ll need = hurdle[indexhurdle].second-hurdle[indexhurdle].first+2;
        // cout<<need<<endl;

        while(indexpower < powerup.size() && powerup[indexpower].first < upto){
            qu.push(powerup[indexpower].second);
            indexpower++;
        }

        if(score >= need){
            indexhurdle++;
        }else{
            while(!qu.empty() && score < need){
                score += qu.top();
                // cout<<score<<endl;
                ans++;
                qu.pop();
            }

            if(score < need){
                cout<<-1<<endl;
                return;
            }

            indexhurdle++;

        }

    }

    cout<<ans<<endl;
}