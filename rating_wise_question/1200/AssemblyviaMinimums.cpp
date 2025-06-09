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

    ll ni;
    cin>>ni;

    ll n = (ni * (ni-1)) / 2;

    vector<ll> arr(n);
    inputV(arr,n);

    sort(arr.begin(),arr.end());

    // ll upto = n / 2;

    // ll Size = -1;

    // for(ll i=0; i<upto; i++){

    //     if(i * (i+1) == n*2){
    //         Size = i+1;
    //         break;
    //     }

    // }

    ll ch = ni - 1;

    ll maxi = INT_MIN;

    vector<ll> ans;

    for(ll i=0; i<n;){
        maxi = max(maxi,arr[i]);

        ll k = ch;
        ll mini = INT_MAX;

        while(k--){
            
            mini = min(mini,arr[i]);

            i++;
        }

        ans.push_back(mini);
        ch--;
    }

    ans.push_back(maxi);

    printV(ans);


    
}