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

    ll d,s;
    cin>>d>>s;

    vector<ll> small(d,0);

    if(s == 0 && d == 1){
        cout<<0<<" "<<0<<endl;
        return;
    }

    if(s == 0){
        cout<<-1<<" "<<-1<<endl;
        return;
    }

    small[0] = 1;

    ll sm = s-1;

    for(int i = d-1; i>0; i--){
        if(sm / 10 == 0){
            small[i] = sm;
            sm -= sm;
        }else{
            small[i] = 9;
            sm -= 9;
        }
    }

    if(sm <= 8){
        small[0] += sm;
        sm -= sm;
    }

    if(sm > 0){
        cout<<-1<<" "<<-1<<endl;
        return;
    }

    vector<ll> big(d,0);

    ll bi = s;

    for(int i=0; i<d; i++){
        if(bi <= 8){
            big[i] = bi;
            bi -= bi;
        }else{
            big[i] = 9;
            bi -= 9;
        }
    }

    if(bi > 0){
        cout<<-1<<" "<<-1<<endl;
        return;
    }

    string ans1 = "";
    string ans2 = "";

    for(ll i = 0; i<d; i++){
        ans1 += ('0' + small[i]);
        ans2 += ('0' + big[i]);
    }

    cout<<ans1<<" "<<ans2<<endl;

    // ll sol1 = stoll(ans1);
    // ll sol2 = stoll(ans2);

    // cout<<sol1<<" "<<sol2<<endl;

}