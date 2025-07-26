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

    ll n;
    cin>>n;

    string s;
    cin>>s;

    // cout<<s<<endl;

    if(n == 1){
        cout<<0<<endl;
        return;
    }

    vector<ll> pre(n,0);
    vector<ll> suff(n,0);

    ll cnt = 0;
    ll ans1 = 0;
    ll space = 0;

    if(s[0] == '*'){
        cnt++;
    }

    for(ll i =1; i<n; i++){
        if(s[i] == '*'){
            
            pre[i] = pre[i-1];
            cnt++;
            // cout<<"True"<<endl;
            
        }else{
            pre[i] = cnt+pre[i-1];
            // cout<<"False"<<endl;
        }

        // cout<<cnt<<endl;
    }

   cnt = 0;
   if(s[n-1] == '*'){
    cnt++;
   }

    for(ll i = n-2; i>=0; i--){
        if(s[i] == '*'){
            suff[i] = suff[i+1];
            cnt++;
        }else{
            suff[i] = cnt+suff[i+1];
        }
    }

    // printV(pre);
    // printV(suff);

    ll sol = LLONG_MAX;

    for(ll i =0; i<n-1; i++){
        sol = min(sol,pre[i]+suff[i+1]);
    }

    cout<<sol<<endl;

// ll cnt = 0;

// for(ll i = 0; i<n; i++){
//     if(s[i] == '*'){
//         cnt++;
//     }
// }

// ll mid = (cnt+1)/2;

// ll cnt2 = 0;

// ll ind = -1;

// for(ll i = 0; i<n; i++){
//     if(s[i] == '*'){
//         cnt2++;
//     }

//     if(cnt2 == mid){
//         ind = i;
//         break;
//     }
// }


// ll ans = 0;
// ll space = 0;

// for(ll i = ind-1; i >=0; i--){
//     if(s[i] == '.'){
//         space++;
//     }else{
//         ans += space;
//     }
// }

// space = 0;

// for(ll i =ind+1; i<n; i++){
//     if(s[i] == '.'){
//         space++;
//     }else{
//         ans += space;
//     }
// }

// cout<<ans<<endl;

}