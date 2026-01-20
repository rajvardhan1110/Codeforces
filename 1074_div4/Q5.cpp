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
    ll n,m,k;
    cin>>n>>m>>k;

    vector<ll> a, b;
    inputV(a, n);
    inputV(b, m);
    sort(b.begin(), b.end());

    string steps;
    cin>>steps;

    map<ll,ll> Prev, Next;
    ll robotstep = 0;
    ll maxi = 0;
    ll mini = 0;

    for (ll i = 1; i <= k; i++) {

        if(steps[i - 1] == 'R'){
            robotstep++;
        }else{
            robotstep--;
        }
        

        if (robotstep > maxi && !Prev.count(robotstep)){ 
            Prev[robotstep] = i;
        }
        
        if (robotstep < mini && !Next.count(-robotstep)){ 
            Next[-robotstep] = i;
        }

        maxi = max(maxi, robotstep);
        mini = min(mini, robotstep);
    }

    map<ll,ll> die;
    ll alive = n;
   

    for (ll i = 0; i < n; i++) {
        ll x = a[i];

        if (binary_search(b.begin(), b.end(), x)) {
            alive--;   
            continue;  
        }

        ll best = INT_MAX;

        auto it = lower_bound(b.begin(), b.end(), x);

        if (it != b.end()) {
            ll d = *it - x;
            if (d > 0 && Prev.count(d)) best = min(best, Prev[d]);
        }
        if (it != b.begin()) {
            auto jt = prev(it);
            ll d = x - *jt;
            if (d > 0 && Next.count(d)) best = min(best, Next[d]);
        }

        if (best != INT_MAX) die[best]++;
    }

    
    for (ll i = 1; i <= k; i++) {
        if (die.count(i)) alive -= die[i];
        cout << alive << " ";
    }

    cout<<endl;
}