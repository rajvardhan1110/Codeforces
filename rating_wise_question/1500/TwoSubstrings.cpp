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


    bool f1 = false;
    bool f2 = false;
    bool f3 = false;
    bool f4 = false;

    ll ind1 = 0;

    while(ind1 < s.size()-1){
        if(f1){
            if(s[ind1] == 'B' && s[ind1+1] == 'A'){
                f2 = true;
                break;
            }else{
                ind1++;
            }
        }else{
            if(s[ind1] == 'A' && s[ind1+1] == 'B'){
                f1 = true;
                ind1 += 2;
            }else{
                ind1++;
            }
        }
    }

    if(f1 == true && f2 == true){
        cout<<"YES"<<endl;
        return;
    }

    ll ind2 = 0;

    while(ind2 < s.size()-1){
        if(f3){
            if(s[ind2] == 'A' && s[ind2+1] == 'B'){
                f4 = true;
                break;
            }else{
                ind2++;
            }
        }else{
            if(s[ind2] == 'B' && s[ind2+1] == 'A'){
                f3 = true;
                ind2 += 2;
            }else{
                ind2++;
            }
        }
    }

    if(f3 == true && f4 == true){
        cout<<"YES"<<endl;
        return;
    }

    cout<<"NO"<<endl;

}