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

    string n;
    cin>>n;

    //for 0 and 8

    for(auto i : n){
        if(i == '0' || i == '8'){
            cout<<"YES"<<endl;
            cout<<i<<endl;
            return;
        }
    }


    //2 digit

    for(ll i =0; i<n.size(); i++){
        ll num = n[i] - '0';
        num *= 10;

        for(ll j = i+1; j<n.size(); j++){
            ll num1 = n[j] - '0';
            ll num2 = num + num1;

            if(num2 % 8 == 0){
                cout<<"YES"<<endl;
                cout<<num2<<endl;
                return;
            }
        }
    }

    //3 digit
    if(n.size() >= 3){
        for(ll i =0; i<n.size(); i++){
            ll num = n[i] - '0';
            num *= 100;

            for(ll j = i+1; j<n.size(); j++){
                ll num1 = n[j] - '0';
                num1 *= 10;

                for(ll k = j+1; k<n.size(); k++){
                    ll num3 = n[k] - '0';
                    ll numm = num + num1 + num3;

                    if(numm % 8 == 0){
                        cout<<"YES"<<endl;
                        cout<<numm<<endl;
                        return;
                    }
                 }
            }
         }
    }

    cout<<"NO"<<endl;
    

}