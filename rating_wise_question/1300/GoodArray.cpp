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

    int t=1;
    // cin >> t;
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

    vector<pair<ll,ll>> asce;
    map<ll,ll> index;

    for(ll i = 0; i<n; i++){
        asce.push_back({arr[i],i});
    }

    sort(asce.begin(),asce.end());

    ll sum = accumulate(arr.begin(),arr.end(),0LL);

    vector<ll> ans;

    for(ll i = 0; i<n; i++){
       ll check = sum - arr[i];

       ll maxi = -1;

       if(arr[i] == asce[asce.size()-1].first){
            maxi = asce[asce.size()-2].first;
       }else{
            maxi = asce[asce.size()-1].first;
       }

       check -= maxi;

       if(check == maxi){
        ans.push_back(i+1);
       }
    }

    if(ans.size() == 0){
        cout<<0<<endl;
    }else{
        cout<<ans.size()<<endl;
        printV(ans);
    }
}