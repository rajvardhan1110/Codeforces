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

bool solve2(ll mid,ll row,ll col,ll stu){
    ll remc = col / (mid+1);
    ll total = col - remc;

    ll totalstu = total * row;

    if(totalstu >= stu){
        return true;
    }

    return false;
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

    ll r,c,s;
    cin>>r>>c>>s;

    ll mini = 1;
    ll maxi = c;

    ll ans = -1;

    while(mini <= maxi){
        ll mid = (mini+maxi) / 2;

        if(solve2(mid,r,c,s)){
            ans = mid;
            maxi =mid -1;
        }else{
            mini = mid+1;
        }
    }

    cout<<ans<<endl;
}