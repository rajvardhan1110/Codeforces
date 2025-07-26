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

    string s;
    cin>>s;

    ll n = s.size();

    vector<pair<ll,ll>> fre;

    ll cnt = 1;

    for(ll i = 1; i<n; i++){
        if(s[i] == s[i-1]){
            cnt++;
        }else{
            ll start = i-cnt+1;
            fre.push_back({start-1,cnt});
            cnt = 1;
        }
    }
    
    fre.push_back({n-1-cnt+1,cnt});

    // for(auto i : fre){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }

    for(auto i : fre){
        if(i.second != 1){
            char prev = s[i.first];
            char curr = s[i.first];
            char next = s[i.first];

            if(i.first > 0){
                prev = s[i.first-1];
            }

            if(i.first + i.second < n){
                next = s[i.first + i.second];
            }
            
            // cout<<next<<endl;

            char change = 'a';

            while(1){
                if(change == prev || change == curr || change == next){
                    change++;
                }else{
                    break;
                }
            }

            ll x = i.first+1;
            for(ll j = 0; j<(i.second / 2); j++){
                s[x] = change;
                x += 2;
            }
        }
    }

    cout<<s<<endl;
}