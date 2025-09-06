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

    ll n,s;

    cin>>n>>s;

    vector<ll> arr(n);

    inputV(arr,n);

    ll sum = accumulate(arr.begin(),arr.end(),0);

    // cout<<"sum->"<<sum<<endl;
    if(sum > s){
        printV(arr);
        return;
    }

    if(sum == s-1){
        ll cnt0 = 0;
        ll cnt1 = 0;
        ll cnt2 = 0;

        for(auto i : arr){
            if(i == 0){
                cnt0++;
            }else if(i == 1){
                cnt1++;
            }else{
                cnt2++;
            }
        }

        while(cnt0--){
            cout<<0<<" ";
        }

        while(cnt2--){
            cout<<2<<" ";
        }

        while(cnt1--){
            cout<<1<<" ";
        }

        cout<<endl;
    }else{
        cout<<-1<<endl;
    }
}