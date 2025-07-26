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

     vector<ll> arr(n);
     inputV(arr,n);

     map<ll,ll> mp;

     for(ll i=0; i<n; i++){
        mp[arr[i] % k]++;
     }

     ll cnt = 0;
     if(mp[0] > 0){
        cnt++;
        mp.erase(0);
     }

    //  set<ll> F;
    //  set<ll> L;

    //  for(ll i=0; i<n; i++){
    //     ll modl = arr[i] % k;



    //     ll req = k - modl;

    //     // if(modl == 0){
    //     //     continue;
    //     // }
    //     cout<<modl<<" "<<req<<endl;

    //     if(F.count(req)){
    //         F.erase(req);
    //         F.insert(modl);
    //     }else if(L.count(req)){
    //         L.erase(req);
    //         L.insert(modl);
    //     }else if(modl == req){
    //         if(mp[req] > 1){
    //             cnt++;
    //             mp[req] -= 2;
    //             F.insert(req);
    //             L.insert(req);
    //         }

    //          if(mp[req] == 0){
    //             mp.erase(req);
    //         }

    //         if(mp[modl] == 0){
    //              mp.erase(modl);
    //         }
    //     }else{
    //         if(mp[req] > 1){
    //             cnt++;
    //             mp[req] -= 1;
    //             mp[modl] -= 1;
    //             F.insert(modl);
    //             L.insert(req);

    //             if(mp[req] == 0){
    //                 mp.erase(req);
    //             }

    //             if(mp[modl] == 0){
    //                 mp.erase(modl);
    //             }
    //         }
    //     }   
    //  }

   for (auto &[rem, freq] : mp) {
    if (freq == 0) continue;

    ll req = k - rem;
    if (req == rem) {
        cnt++; 
    } else if (mp.count(req)) {
        ll mini = min(freq, mp[req]);
        if (mini > 0) {
            cnt++; 
            ll left = abs(freq - mp[req]) - 1;
            if (left > 0) cnt += left;
            mp[req] = 0;
        } else {
            cnt += freq;
        }
    } else {
        cnt += freq;
    }

    mp[rem] = 0;
    mp[req] = 0;
}


    cout<<cnt<<endl;
}