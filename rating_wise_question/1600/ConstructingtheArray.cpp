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

struct cmp {
    bool operator() (const pair<ll, ll> &a, const pair<ll, ll> &b) const {
        ll lena = a.second - a.first + 1;
        ll lenb = b.second - b.first + 1;

        if (lena == lenb) 
            return a.first < b.first;

        return lena > lenb;
    }
};

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

    vector<ll> arr(n,0);

    set<pair<ll,ll>, cmp> st;
    st.insert({0,n-1});

    ll x = 1;

    while(st.size() > 0){
        auto it = st.begin();

        int l = it->first;
        int r = it->second;

        st.erase(it);

        int mid;

        if((r - l + 1) % 2 == 1)
            mid = (l + r) / 2;
        else
            mid = (l + r - 1) / 2;

        arr[mid] = x;
        x++;

        if(l <= mid - 1)
            st.insert({l, mid - 1});

        if(mid + 1 <= r)
            st.insert({mid + 1, r});
    }

    printV(arr);


}