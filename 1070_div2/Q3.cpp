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

    vector<ll> arr(n);
    inputV(arr,n);

    ll oddmaxi = 0;

    priority_queue<ll> even;  
    priority_queue<ll, vector<ll>, greater<ll>> odd;
     ll mini = INT_MAX;

    for(ll i = 0; i<n; i++){
        if(arr[i]&1){
            odd.push(arr[i]);
            oddmaxi = max(oddmaxi,arr[i]);
        }else{
            even.push(arr[i]);
            mini = min(mini,arr[i]);
        }
    }

    vector<ll> ans(n);

   

    if(odd.size() == 0){
        for(ll i = 0; i<n; i++){
            cout<<0<<" ";
        }

        cout<<endl;
        return;
    }else if(even.size() == 0){
        bool flag = true;
        for(ll i = 0; i<n; i++){
           if(flag){
            cout<<oddmaxi<<" ";
            flag = false;
           }else{
            cout<<0<<" ";
            flag = true;
           }
        }

        cout<<endl;
        return;
    }

    

    ans[0] = oddmaxi;

    vector<ll> tmp;

    ll maxi = LLONG_MIN;


    while (!odd.empty()) {
        ll val = odd.top(); odd.pop();
        if (val > maxi) maxi = val;
        tmp.push_back(val);
    }


    bool removed = false;
    priority_queue<ll, vector<ll>, greater<ll>> new_odd;
    for (ll val : tmp) {
        if (val == maxi && !removed) {
            removed = true;
            continue; 
        }
        new_odd.push(val);
    }


    odd = move(new_odd);


    for(int i=1; i<n; i++){
        ll prev = ans[i-1];

        if(even.size() != 0){
            ans[i] = ans[i-1] + even.top();
            even.pop();
        }else{
            if(odd.size() == 1){
                ans[i] = 0;
            }else{
                ans[i] = ans[i-1] - mini;
                even.push(mini);
            }
        }
    }

    for(ll i = 0; i<n; i++){
        cout<<ans[i]<<" ";
    }

    cout<<endl;




}