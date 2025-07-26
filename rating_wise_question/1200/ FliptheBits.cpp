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

    string a;
    string b;
    cin>>a;
    cin>>b;

    ll cntZero = 0;
    ll cntOne = 0;

    for(ll i=0; i<n; i++){
        if(a[i] == '0'){
            cntZero++;
        }else{
            cntOne++;
        }
    }

    ll change = 0;

    for(ll i = n-1; i>=0; i--){
        char curr = a[i];

        if(change % 2 != 0){
            if(a[i] == '1'){
                curr = '0';
            }else{
                curr = '1';
            }
        }


        // cout<<curr<<endl<<endl;
        // cout<<cntOne<<" "<<cntZero<<endl;

        if(curr == b[i]){
            if(curr == '0'){
                cntZero--;
            }else{
                cntOne--;
            }
        }else{
            if(cntOne != cntZero){
                cout<<"NO"<<endl;
                return;
            }else{
                if(curr == '1'){
                    cntZero--;
                }else{
                    cntOne--;
                }

                
            }

            change++;
        }

        // cout<<cntOne<<" "<<cntZero<<endl;

    }

    cout<<"YES"<<endl;
}