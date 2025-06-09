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

    ll k;
    cin>>k;

    vector<vector<ll>> arr(k,vector<ll> (k));

     for (int i = 0; i < k; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < k; j++) {
            arr[i][j] = s[j] - '0';  // convert char to int
        }
    }



    vector<vector<bool>> flag(k,vector<bool> (k,false));

    int n = k-1;

    if(n%2 == 0){
        flag[n/2][n/2] = true;
    }

    int count = 0;

    for(ll i=0; i<k; i++){
        for(ll j=0; j<k; j++){



            if(flag[i][j] == false){
                ll zc = 0;
                ll oc = 0;

                //0
                ll zero = arr[i][j];
                flag[i][j] = true;

                if(zero == 0){
                    zc++;

                }else{
                    oc++;
                }

                //90
                ll nine = arr[j][n-i];
                flag[j][n-i] = true;

                if(nine == 0){
                    zc++;

                }else{
                    oc++;
                }

                //180

                ll athara = arr[n-i][n-j];
                flag[n-i][n-j] = true;

                if(athara == 0){
                    zc++;

                }else{
                    oc++;
                }

                //270

                ll satara = arr[n-j][i];
                flag[n-j][i] = true;

                if(satara == 0){
                    zc++;

                }else{
                    oc++;
                }

                count += min(zc,oc);


            }
           
        }
    }

    cout<<count<<endl;


}