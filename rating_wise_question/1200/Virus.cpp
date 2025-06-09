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

    ll n,k;
    cin>>n>>k;

    vector<ll> arr(k);
    inputV(arr,k);

    sort(arr.begin(),arr.end());

    vector<ll> ans;

    ll a = arr[0] - 1 + n - arr[k-1];

    ans.push_back(a);

    for(int i=0; i<k-1; i++){
        ans.push_back(arr[i+1]-arr[i]-1);
    }

    ll count = 0;

    sort(ans.begin(),ans.end());

    if(ans[k-1] == 0){
        cout<<n<<endl;
        return;
    }

    if(ans[k-1] == 2 || ans[k-1] == 1){
        cout<<n-1<<endl;
        return;
    }


    // printV(ans);

    ll multi = 2;

    count += ans[k-1] - 1;

    for(ll i = k-2; i>=0; i--){
        ll rem = ans[i] - multi*2;
        
        if(rem <= 0){
            break;
        }

        if(rem == 1 || rem == 2){
            count++;
            break;
        }

        count += rem-1;

        multi += 2;
    }

    cout<<n-count<<endl;


}