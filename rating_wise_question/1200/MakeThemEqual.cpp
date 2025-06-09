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
    char c;
    cin>>n;
    cin>>c;

    string s;
    cin>>s;

    ll cnt=0;

    for(auto i:s){
        if(i == c){
            cnt++;
        }
    }

    if(cnt == n){
        cout<<0<<endl;
        return;
    }

    if(s[n-1] == c){
        cout<<1<<endl;
        cout<<n<<endl;
        return;
    }

    vector<ll> arr;

   for(ll i=0; i<n; i++){
        if(s[i] == c){
            arr.push_back(i+1);
        }
    }

    sort(arr.rbegin(),arr.rend());

    // printV(arr);


    for(auto i:arr){
        // ll num = i;
        ll multi = 1;

        bool flag = false;

        while(i*multi <= n){
            if(s[i*multi - 1] != c){
                flag = true;
                break;
            }

            multi++;
        }

        if(flag == false){
            cout<<1<<endl;
            cout<<i<<endl;
            return;
        }
    }

    cout<<2<<endl;
    cout<<n<<" "<<n-1<<endl;




}