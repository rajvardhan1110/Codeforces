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

    ll one = 0;

    for(auto i : s){
        if(i == '1'){
            one++;
        }
    }

   

    if(one == 0){

        ll cnt = 0;
        ll ans = 1;
        
        for(ll i = 2; i<n; i++){
            if(cnt == 2){
                cnt=0;
                ans++;
            }else{
                cnt++;
            }
        }

        if(cnt == 2){
            ans++;
        }

        cout<<ans<<endl;
        return;

    }


    ll i = 0;

    ll ans = 0;

    ll cnt1 = 0;

    // cout<<ans<<endl;

    while(s[i] != '1'){
        cnt1++;
        i++;
    }


    if(cnt1 % 3 == 0){
        ans += cnt1/3;
    }else if((cnt1 - 1) % 3 == 0){
        ans += (cnt1-1)/3; 
    }else{
        ans += (cnt1+1)/3;
    }

    // cout<<ans<<endl;


    cnt1 = 0;

    for(ll j = i+1; j<n; j++){
        if(s[j] == '1'){
            ans += cnt1/3;
            cnt1=0;
        }else{
            cnt1++;
        }
    }

    // cout<<ans<<endl;


    if(cnt1 % 3 == 0){
        ans += cnt1/3;
    }else if((cnt1 - 1) % 3 == 0){
        ans += (cnt1-1)/3; 
    }else{
        ans += (cnt1+1)/3;
    }

    // cout<<ans<<endl;

    ans += one;

    cout<<ans<<endl;

    
}